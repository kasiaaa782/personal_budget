#include "ExpensesMenager.h"

void ExpensesMenager::userLogout() {
    expenses.clear();
}
void ExpensesMenager::addExpense() {
    system("cls");
    Expense expense;
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    expense = enterDataNewExpense();

    expenses.push_back(expense);
    if(expensesFile.joinExpenseToFile(expense)) {
        cout << "Nowy wydatek zostal dodany." << endl;
    } else {
        cout << "Blad. Nie udalo sie dodac nowego wydatku do pliku.";
    }
    system("pause");
}

Expense ExpensesMenager::enterDataNewExpense() {
    Expense expense;
    string item;
    float amount;
    int date;

    expense.setUserID(LOGGED_USER_ID);
    expense.setExpenseID(expensesFile.getLastExpenseID() + 1);

    date = getDateFromUser();

    cout << "Podaj rodzaj wydatku (np. jedzenie, restauracja, mieszkanie, transport itd.) : ";
    item = AssistantMethods::loadLine();
    cout << endl;

    cout << "Podaj wysokosc wydatku (w zl.): ";
    amount = AssistantMethods::getFloatNumber();
    cout << endl;

    expense.setDate(date);
    expense.setItem(item);
    expense.setAmount(amount);

    return expense;
}

int ExpensesMenager::getDateFromUser() {
    string dateStr;
    int date;
    cout << "Podaj date: " << endl;
    cout << "1. Z dnia dzisiejszego." << endl;
    cout << "2. Wybierz inna date." << endl;
    cout << "---" << endl;
    cout << "Twoj wybor: ";

    while(true) {
        switch(AssistantMethods::loadChar()) {
        case '1':
            cout << endl << "Wybrano date: ";
            dateStr = AssistantMethods::getCurrentDate();
            cout << dateStr;
            cout << endl << endl;
            date = AssistantMethods::changeDateOnInt(dateStr);
            return date;
        case '2': {
            dateStr = AssistantMethods::getDateFromSelectedPeriod();
            cout << endl;
            date = AssistantMethods::changeDateOnInt(dateStr);
            return date;
        }
        default:
            cout << endl << "Nie ma takiej opcji w menu. Sprobuj ponownie: " ;
            break;
        }
    }
}

void ExpensesMenager::printExpenseData(Expense expense){
    cout << endl << "ID wydatku:         " << expense.getExpenseID() << endl;
    cout << "Data:               " << AssistantMethods::changeDateOnString(expense.getDate()) << endl;
    cout << "Rodzaj wydatku:     " << expense.getItem()<< endl;
    cout << "Wysokosc wydatku:   " << expense.getAmount() << endl;
}

void ExpensesMenager::printExpensesOfCurrentMonth(){
    string currentMonth = AssistantMethods::getMonthFromDate(AssistantMethods::getCurrentDate());
    string month;
    if(!expenses.empty()){
        cout << "WYDATKI: " << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            month = AssistantMethods::getMonthFromDate(AssistantMethods::changeDateOnString(itr -> getDate()));
            if(month == currentMonth){
                printExpenseData(*itr);
            }
        }
        cout << endl;
    }
    else{
        cout << endl << "Nie wprowadzono zadnych wydatkow." << endl << endl;
    }
}

float ExpensesMenager::sumOfExpenses(){
    float sum = 0;
    for(vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++){
        sum = sum + itr->getAmount();
    }
    return sum;
}
