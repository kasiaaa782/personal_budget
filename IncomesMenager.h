#ifndef INCOMESMENAGER_H
#define INCOMESMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>

#include "Income.h"
#include "IncomesFile.h"

using namespace std;

class IncomesMenager{

    const int LOGGED_USER_ID;
    vector <Income> incomes;
    IncomesFile incomesFile;

    Income enterDataNewIncome();
    int getDateFromUser();
    void printIncomeData(Income income);

public:
    IncomesMenager(string incomesFileName, int loggedUserID)
        : incomesFile(incomesFileName), LOGGED_USER_ID(loggedUserID){
            incomes = incomesFile.loadIncomesFromFile(LOGGED_USER_ID);
            sort( incomes.begin(), incomes.end(), DateClass::sortByDateForIncomes);
    };
    void addIncome();
    void userLogout();
    void printIncomesOfCurrentMonth();
    float sumOfIncomesOfCurrentMonth();
    void printIncomesOfPreviousMonth();
    float sumOfIncomesOfPreviousMonth();
    void printIncomesOfSelectedPeriod(int dateBegin, int dateEnd);
    float sumOfIncomesOfSelectedPeriod(int dateBegin, int dateEnd);

};

#endif
