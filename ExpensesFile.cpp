#include "ExpensesFile.h"

void ExpensesFile::setLastExpenseID(int newLastExpenseID){
    lastExpenseID = newLastExpenseID;
}

int ExpensesFile::getLastExpenseID(){
    return lastExpenseID;
}

bool ExpensesFile::joinExpenseToFile(Expense expense){
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
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", expense.getAmount());

    xml.Save("Expenses.xml");

    return true;
}

vector <Expense> ExpensesFile::loadExpensesFromFile(int idLoggedUser) {
    Expense expense;
    vector <Expense> expenses;

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
        xml.FindElem("Date");
        expense.setDate(xml.GetData());
        xml.FindElem("Item");
        expense.setItem(xml.GetData());
        xml.FindElem("Amount");
        expense.setAmount(AssistantMethods::convertionStringOnFloat(xml.GetData()));
        xml.OutOfElem();
        expenses.push_back(expense);
    }
    setLastExpenseID(expense.getExpenseID());
    return expenses;
}


