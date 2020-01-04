#include "UsersFile.h"

void UsersFile::joinUserToFile(User user){
    CMarkup xml;
    bool fileExists = xml.Load( "Users.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserID());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());

    xml.Save("Users.xml");
}

vector <User> UsersFile::loadUsersFromFile(){
    User user;
    vector <User> users;
    CMarkup xml;
    xml.Load( "Users.xml" );
    xml.FindElem(); // root Users element
    xml.IntoElem(); // inside Users
    while( xml.FindElem("User")){
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
    }
    return users;
}

void UsersFile::saveUsersChangesToFile(vector <User> &users){
    CMarkup xml;

    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xml.AddElem("Users");
    xml.IntoElem();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++){
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("UserId", itr -> getUserID());
        xml.AddElem("Login", itr -> getLogin());
        xml.AddElem("Password", itr -> getPassword());
        xml.AddElem("Name", itr -> getName());
        xml.AddElem("Surname", itr -> getSurname());
        xml.OutOfElem();
    }

    xml.Save("Users.xml");
}

