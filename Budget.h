#ifndef BUDGET_H
#define BUDGET_H

#include "UserMenager.h"
#include "IncomesMenager.h"

using namespace std;

class Budget {
    UserMenager userMenager;
    IncomesMenager *incomesMenager;
    const string INCOMES_FILE_NAME;
    //ExpensesManager *expensesManager;

public:
    Budget(string usersFileName, string incomesFileName)// string expensesFileName
        : userMenager(usersFileName), INCOMES_FILE_NAME(incomesFileName) {
            incomesMenager = NULL;
    };
    ~Budget(){
        delete incomesMenager;
        incomesMenager = NULL;
    };

    void userRegistration();
    void writeAllUsers();
    void userLogin();
    void userLogout();
    bool ifUserIsLogged();
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
    void addIncome();
    //void addExpense();
    //void balanceOfCurrentMonth();
    //void balanceOfPreviousMonth();
    //void balanceOfPassedPeriod();
    void changePassword();

};
#endif
