#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income{
    int incomeID;
    int userID;
    int date;
    string item;
    string amount;

public:
    Income(int incomeID = 0, int userID = 0, int date = 0, string item = "", string amount = ""){
        this->incomeID = incomeID;
        this->userID = userID;
        this->date = date;
        this->item = item;
        this->amount = amount;
    }

    void setIncomeID(int newIncomeID);
    void setUserID(int newUserID);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getIncomeID();
    int getUserID();
    int getDate();
    string getItem();
    string getAmount();
};

#endif
