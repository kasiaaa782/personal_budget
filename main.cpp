#include <iostream>

#include "Budget.h"

using namespace std;

int main() {
    Budget budget("Users.xml", "Incomes.xml", "Expenses.xml");
    while (true) {
        if (budget.ifUserIsLogged() == false) {
            switch (budget.selectOptionFromMainMenu()) {
            case '1':
                budget.userRegistration();
                 cin.clear();
                 cin.ignore();
                break;
            case '2':
                budget.userLogin();
                break;
            case '8':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            switch (budget.selectOptionFromUserMenu()) {
            case '1':
                budget.addIncome();
                cin.clear();
                cin.ignore();
                break;
            case '2':
                budget.addExpense();
                cin.clear();
                cin.ignore();
                break;
            case '3':
                //budget.balanceOfCurrentMonth();
                break;
            case '4':
                //budget.balanceOfPreviousMonth();
                break;
            case '5':
                //budget.balanceOfPassedPeriod();
                break;
            case '6':
                budget.changePassword();
                break;
            case '7':
                budget.userLogout();
                break;
            }
        }
    }
    return 0;
}

#include "IncomesFile.h"

int _main()
{
    Budget budget("Users.xml", "Incomes.xml", "Expenses.xml");
    ExpensesMenager expensesMenager("Expense.xml", 2);
    expensesMenager.addExpense();

    return 0;
}


