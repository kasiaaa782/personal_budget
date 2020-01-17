#ifndef BUDGET_H
#define BUDGET_H

#include "UserMenager.h"
#include "IncomesMenager.h"
#include "ExpensesMenager.h"

using namespace std;

class Budget {
    UserMenager userMenager;
    IncomesMenager *incomesMenager;
    const string INCOMES_FILE_NAME;
    ExpensesMenager *expensesMenager;
    const string EXPENSES_FILE_NAME;

public:
    Budget(string usersFileName, string incomesFileName, string expensesFileName)
        : userMenager(usersFileName), INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName) {
            incomesMenager = NULL;
            expensesMenager = NULL;
    };
    ~Budget(){
        delete incomesMenager;
        incomesMenager = NULL;
        delete expensesMenager;
        expensesMenager = NULL;
    };

    void userRegistration();
    void writeAllUsers();
    void userLogin();
    void userLogout();
    bool ifUserIsLogged();
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
    void addIncome();
    void addExpense();
    void balanceOfCurrentMonth();
    void balanceOfPreviousMonth();
    //void balanceOfPassedPeriod();
    void changePassword();

};
#endif
