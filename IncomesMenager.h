#ifndef INCOMESMENAGER_H
#define INCOMESMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "Income.h"
#include "IncomesFile.h"

using namespace std;

class IncomesMenager{

    const int LOGGED_USER_ID;
    vector <Income> incomes;
    IncomesFile incomesFile;

    Income enterDataNewIncome();
    string getDateFromUser();

public:
    IncomesMenager(string incomesFileName, int loggedUserID)
        : incomesFile(incomesFileName), LOGGED_USER_ID(loggedUserID){
            incomes = incomesFile.loadIncomesFromFile(LOGGED_USER_ID);
    };
    void addIncome();
    void userLogout();
    //void searchIncomesOfCurrentMonth();
    //void searchIncomesOfPreviousMonth();
    //void searchIncomesOfPassedPeriod();

};

#endif