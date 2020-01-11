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
    string date;

    expense.setUserID(LOGGED_USER_ID);
    expense.setExpenseID((expensesFile.getLastExpenseID() + 1));

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

string ExpensesMenager::getDateFromUser() {
    string date;
    cout << "Podaj date: " << endl;
    cout << "1. Z dnia dzisiejszego." << endl;
    cout << "2. Wybierz inna date." << endl;
    cout << "---" << endl;
    cout << "Twoj wybor: ";

    while(true) {
        switch(AssistantMethods::loadChar()) {
        case '1':
            cout << endl << "Wybrano date: ";
            date = AssistantMethods::getCurrentDate();
            cout << endl << endl;
            return date;
        case '2': {
            date = AssistantMethods::getDateFromSelectedPeriod();
            cout << endl;
            return date;
        }
        default:
            cout << endl << "Nie ma takiej opcji w menu. Sprobuj ponownie: " ;
            break;
        }
    }
}
