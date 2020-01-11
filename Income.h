#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income{
    int incomeID;
    int userID;
    string date;
    string item;
    float amount;

public:
    Income(int incomeID = 0, int userID = 0, string date = "", string item = "", float amount = 0){
        this->incomeID = incomeID;
        this->userID = userID;
        this->date = date;
        this->item = item;
        this->amount = amount;
    }

    void setIncomeID(int newIncomeID);
    void setUserID(int newUserID);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getIncomeID();
    int getUserID();
    string getDate();
    string getItem();
    float getAmount();
};

#endif
