#include "ExpensesFile.h"

void ExpensesFile::setLastExpenseID(int newLastExpenseID){
    lastExpenseID = newLastExpenseID;
}

int ExpensesFile::getLastExpenseID(){
    return lastExpenseID;
}

bool ExpensesFile::joinExpenseToFile(Expense expense){
    string dateStr;
    CMarkup xml;
    bool fileExists = xml.Load( "Expenses.xml" );
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseID", expense.getExpenseID());
    xml.AddElem("UserID", expense.getUserID());
    dateStr = DateClass::changeDateOnString(expense.getDate());
    xml.AddElem("Date", dateStr);
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", AssistantMethods::convertionFloatOnString(expense.getAmount()));
    xml.Save("Expenses.xml");
    setLastExpenseID(getLastExpenseID() + 1);

    return true;
}

vector <Expense> ExpensesFile::loadExpensesFromFile(int idLoggedUser) {
    Expense expense;
    vector <Expense> expenses;
    string dateStr;
    int date;
    CMarkup xml;
    xml.Load( "Expenses.xml" );
    xml.FindElem();
    xml.IntoElem();
    while( xml.FindElem("Expense")) {
        xml.IntoElem();
        xml.FindElem("ExpenseID");
        expense.setExpenseID(atoi(MCD_2PCSZ(xml.GetData()))); //it is converted to an integer using atoi (MCD_2PCSZ is defined in Markup.h to return the string's const pointer)
        xml.FindElem("UserID");
        expense.setUserID(atoi(MCD_2PCSZ(xml.GetData()))); //it is converted to an integer using atoi (MCD_2PCSZ is defined in Markup.h to return the string's const pointer)
        if(expense.getUserID() == idLoggedUser){
            xml.FindElem("Date");
            dateStr = xml.GetData();
            date = DateClass::changeDateOnInt(dateStr);
            expense.setDate(date);
            xml.FindElem("Item");
            expense.setItem(xml.GetData());
            xml.FindElem("Amount");
            expense.setAmount(AssistantMethods::convertionStringOnFloat(xml.GetData()));
            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }
    setLastExpenseID(expense.getExpenseID());
    return expenses;
}
