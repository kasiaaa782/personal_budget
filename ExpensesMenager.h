#ifndef EXPENSESMENAGER_H
#define EXPENSESMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "Expense.h"
#include "ExpensesFile.h"

using namespace std;

class ExpensesMenager{

    const int LOGGED_USER_ID;
    vector <Expense> expenses;
    ExpensesFile expensesFile;

    Expense enterDataNewExpense();
    int getDateFromUser();

public:
    ExpensesMenager(string expensesFileName, int loggedUserID)
        : expensesFile(expensesFileName), LOGGED_USER_ID(loggedUserID){
            expenses = expensesFile.loadExpensesFromFile(LOGGED_USER_ID);
    };
    void addExpense();
    void userLogout();
    //void searchIncomesOfCurrentMonth();
    //void searchIncomesOfPreviousMonth();
    //void searchIncomesOfPassedPeriod();

};

#endif
