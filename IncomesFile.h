#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <algorithm>
#include <vector>

#include "Income.h"
#include "AssistantMethods.h"
#include "XMLFile.h"
#include "Markup.h"

using namespace std;

class IncomesFile : public XMLFile{

    int lastIncomeID;

public:
    IncomesFile(string fileName) : XMLFile(fileName){
        lastIncomeID = 0;
    };
    vector <Income> loadIncomesFromFile(int idLoggedUser);
    bool joinIncomeToFile(Income income);

    int getLastIncomeID();
    void setLastIncomeID(int newLastIncomeID);
};

#endif
