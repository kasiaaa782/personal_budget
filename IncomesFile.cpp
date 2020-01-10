#include "IncomesFile.h"

void IncomesFile::setLastIncomeID(int newLastIncomeID){
    lastIncomeID = newLastIncomeID;
}

int IncomesFile::getLastIncomeID(){
    return lastIncomeID;
}

vector <Income> IncomesFile::loadIncomesFromFile(int idLoggedUser) {
    Income income;
    vector <Income> incomes;
    /*
    CMarkup xml;
    xml.Load( "Users.xml" );
    xml.FindElem(); // root Users element
    xml.IntoElem(); // inside Users
    while( xml.FindElem("User")) {
        xml.IntoElem(); //inside User
        xml.FindElem("UserId");
        user.setUserID(atoi(MCD_2PCSZ(xml.GetData()))); //it is converted to an integer using atoi (MCD_2PCSZ is defined in Markup.h to return the string's const pointer)
        xml.FindElem("Login");
        user.setLogin(xml.GetData());
        xml.FindElem("Password");
        user.setPassword(xml.GetData());
        xml.FindElem("Name");
        user.setName(xml.GetData());
        xml.FindElem("Surname");
        user.setSurname(xml.GetData());
        xml.OutOfElem(); //opuszczamy obiekt
        users.push_back(user);
    }*/
    return incomes;
}

bool IncomesFile::joinIncomeToFile(Income income){
    return true;
}
