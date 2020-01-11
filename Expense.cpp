#include "Expense.h"

void Expense::setExpenseID(int newExpenseID){
    if(newExpenseID >= 0)
        expenseID = newExpenseID;
}

void Expense::setUserID(int newUserID){
    if(newUserID >= 0)
        userID = newUserID;
}

void Expense::setDate(string newDate){
        date = newDate;
}

void Expense::setItem(string newItem){
    item = newItem;
}
void Expense::setAmount(float newAmount){
    amount = newAmount;
}

int Expense::getExpenseID(){
    return expenseID;
}

int Expense::getUserID(){
    return userID;
}

string Expense::getDate(){
    return date;
}

string Expense::getItem(){
    return item;
}

float Expense::getAmount(){
    return amount;
}
