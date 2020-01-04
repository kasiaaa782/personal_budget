#ifndef USERSFILE_H
#define USERSFILE_H

#include <vector>
#include <iostream>
#include <cstdlib>

#include "User.h"
#include "XMLFile.h"
#include "Markup.h"

using namespace std;

class UsersFile : public XMLFile {

public:
    UsersFile(string fileName) : XMLFile(fileName) {};
    void joinUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveUsersChangesToFile(vector <User> &users);
};

#endif
