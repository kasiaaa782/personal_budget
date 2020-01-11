#include "Income.h"

void Income::setIncomeID(int newIncomeID){
    if(newIncomeID >= 0)
        incomeID = newIncomeID;
}

void Income::setUserID(int newUserID){
    if(newUserID >= 0)
        userID = newUserID;
}

void Income::setDate(int newDate){
    if(newDate >= 0)
        date = newDate;
}

void Income::setItem(string newItem){
    item = newItem;
}
void Income::setAmount(float newAmount){
    amount = newAmount;
}

int Income::getIncomeID(){
    return incomeID;
}

int Income::getUserID(){
    return userID;
}

int Income::getDate(){
    return date;
}

string Income::getItem(){
    return item;
}

float Income::getAmount(){
    return amount;
}
