#include "IncomesFile.h"

void IncomesFile::setLastIncomeID(int newLastIncomeID){
    lastIncomeID = newLastIncomeID;
}

int IncomesFile::getLastIncomeID(){
    return lastIncomeID;
}

bool IncomesFile::joinIncomeToFile(Income income){
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
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", income.getAmount());

    xml.Save("Incomes.xml");

    return true;
}

vector <Income> IncomesFile::loadIncomesFromFile(int idLoggedUser) {
    Income income;
    vector <Income> incomes;

    CMarkup xml;
    xml.Load( "Incomes.xml" );
    xml.FindElem();
    xml.IntoElem();
    while( xml.FindElem("Income")) {
        xml.IntoElem();
        xml.FindElem("IncomeID");
        income.setIncomeID(atoi(MCD_2PCSZ(xml.GetData()))); //it is converted to an integer using atoi (MCD_2PCSZ is defined in Markup.h to return the string's const pointer)
        xml.FindElem("UserID");
        income.setUserID(atoi(MCD_2PCSZ(xml.GetData()))); //it is converted to an integer using atoi (MCD_2PCSZ is defined in Markup.h to return the string's const pointer)
        xml.FindElem("Date");
        income.setDate(xml.GetData());
        xml.FindElem("Item");
        income.setItem(xml.GetData());
        xml.FindElem("Amount");
        income.setAmount(AssistantMethods::convertionStringOnFloat(xml.GetData()));
        xml.OutOfElem(); //opuszczamy obiekt
        incomes.push_back(income);
    }
    setLastIncomeID(income.getIncomeID());
    return incomes;
}


