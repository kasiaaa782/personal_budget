#ifndef USERSFILE_H
#define USERSFILE_H

#include <vector>
#include <iostream>
#include <cstdlib>

#include "User.h"
#include "AssistantMethods.h"
#include "XMLFile.h"
#include "Markup.h"

using namespace std;

class UsersFile : public XMLFile {

    //Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    UsersFile(string fileName) : XMLFile(fileName) {};
    void joinUserToFile(User user);
    vector <User> loadUsersFromFile();
    //void saveAllUsersToFile(vector <User> &users);
};

#endif
