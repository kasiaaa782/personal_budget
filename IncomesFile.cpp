#include "IncomesFile.h"

void IncomesFile::setLastIncomeID(int newLastIncomeID){
    lastIncomeID = newLastIncomeID;
}

int IncomesFile::getLastIncomeID(){
    return lastIncomeID;
}

bool IncomesFile::joinIncomeToFile(Income income){
    string dateStr;
    CMarkup xml;
    bool fileExists = xml.Load( "Incomes.xml" );
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeID", income.getIncomeID());
    xml.AddElem("UserID", income.getUserID());
    dateStr = DateClass::changeDateOnString(income.getDate());
    xml.AddElem("Date", dateStr);
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", AssistantMethods::convertionFloatOnString(income.getAmount()));
    xml.Save("Incomes.xml");
    setLastIncomeID(getLastIncomeID() + 1);
    return true;
}

vector <Income> IncomesFile::loadIncomesFromFile(int idLoggedUser) {
    Income income;
    vector <Income> incomes;
    string dateStr;
    int date;

    CMarkup xml;
    xml.Load( "Incomes.xml" );
    xml.FindElem();
    xml.IntoElem();
    while( xml.FindElem("Income")) {
        xml.IntoElem();
        xml.FindElem("IncomeID");
        income.setIncomeID(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("UserID");
        income.setUserID(atoi(MCD_2PCSZ(xml.GetData()))); //it is converted to an integer using atoi (MCD_2PCSZ is defined in Markup.h to return the string's const pointer)
        if(income.getUserID() == idLoggedUser){
            xml.FindElem("Date");
            dateStr = xml.GetData();
            date = DateClass::changeDateOnInt(dateStr);
            income.setDate(date);
            xml.FindElem("Item");
            income.setItem(xml.GetData());
            xml.FindElem("Amount");
            income.setAmount(AssistantMethods::convertionStringOnFloat(xml.GetData()));
            incomes.push_back(income);
        }
        xml.OutOfElem();
    }
    setLastIncomeID(income.getIncomeID());
    return incomes;
}


