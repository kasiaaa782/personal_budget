#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense{
    int expenseID;
    int userID;
    string date;
    string item;
    float amount;

public:
    Expense(int expenseID = 0, int userID = 0, string date = "", string item = "", float amount = 0){
        this->expenseID = expenseID;
        this->userID = userID;
        this->date = date;
        this->item = item;
        this->amount = amount;
    }

    void setExpenseID(int newExpenseID);
    void setUserID(int newUserID);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getExpenseID();
    int getUserID();
    string getDate();
    string getItem();
    float getAmount();
};

#endif
