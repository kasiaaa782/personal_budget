#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income{
    int incomeID;
    int date;
    string item;
    string amount;

public:
    Income(int incomeID = 0, int date = 0, string item = "", string amount = ""){
        this->incomeID = incomeID;
        this->date = date;
        this->item = item;
        this->amount = amount;
    }

    void setIncomeID(int newIncomeID);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getIncomeID();
    int getDate();
    string getItem();
    string getAmount();
};

#endif
