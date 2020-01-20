#ifndef EXPENSESMENAGER_H
#define EXPENSESMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>

#include "Expense.h"
#include "ExpensesFile.h"

using namespace std;

class ExpensesMenager{

    const int LOGGED_USER_ID;
    vector <Expense> expenses;
    ExpensesFile expensesFile;

    Expense enterDataNewExpense();
    int getDateFromUser();
    void printExpenseData(Expense expense);

public:
    ExpensesMenager(string expensesFileName, int loggedUserID)
        : expensesFile(expensesFileName), LOGGED_USER_ID(loggedUserID){
            expenses = expensesFile.loadExpensesFromFile(LOGGED_USER_ID);
            sort( expenses.begin(), expenses.end(), DateClass::sortByDateForExpenses);
    };
    void addExpense();
    void userLogout();
    void printExpensesOfCurrentMonth();
    float sumOfExpensesOfCurrentMonth();
    void printExpensesOfPreviousMonth();
    float sumOfExpensesOfPreviousMonth();
    void printExpensesOfSelectedPeriod(int dateBegin, int dateEnd);
    float sumOfExpensesOfSelectedPeriod(int dateBegin, int dateEnd);

};

#endif
