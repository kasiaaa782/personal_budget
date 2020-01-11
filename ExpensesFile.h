#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <algorithm>
#include <vector>

#include "Expense.h"
#include "AssistantMethods.h"
#include "XMLFile.h"
#include "Markup.h"

using namespace std;

class ExpensesFile : public XMLFile{

    int lastExpenseID;

public:
    ExpensesFile(string fileName) : XMLFile(fileName){
        lastExpenseID = 0;
    };
    vector <Expense> loadExpensesFromFile(int idLoggedUser);
    bool joinExpenseToFile(Expense expense);

    int getLastExpenseID();
    void setLastExpenseID(int newLastExpenseID);
};

#endif
