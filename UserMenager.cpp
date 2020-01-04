#include "UserMenager.h"

/*int UserMenager::getIDLoggedUser() {
    return IDLoggedUser;
}*/


void UserMenager::userRegistration() {
    User user = enterNewUserData();
    users.push_back(user);
    usersFile.joinUserToFile(user);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserMenager::enterNewUserData() {
    User user;
    user.setUserID(getIdNewUser());
    string login;
    do {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (ifExistLogin(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    string name;
    cout << "Podaj imie: ";
    cin >> name;
    user.setName(name);

    string surname;
    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(surname);

    return user;
}

int UserMenager::getIdNewUser() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserID() + 1;
}

bool UserMenager::ifExistLogin(string login) {
    for(int i = 0 ; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie. Sprobuj jeszcze raz." << endl;
            return true;
        }
    }
    return false;
}

void UserMenager::writeAllUsers() {
    for(int i = 0 ; i < users.size(); i++) {
        cout << users[i].getUserID() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}

void UserMenager::userLogin() {
    string login = "", password = "";

    cout << "Podaj login: ";
    login = AssistantMethods::wczytajLinie();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int attemptQuantity = 3; attemptQuantity > 0; attemptQuantity--) {
                cout << "Podaj haslo. Pozostalo prob: " << attemptQuantity << ": ";
                password = AssistantMethods::wczytajLinie();

                if (itr -> getPassword() == password) {
                    IDLoggedUser = itr -> getUserID();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UserMenager::userLogout() {
    IDLoggedUser = 0;
}
/*
bool UserMenager::czyUserJestZalogowany() {
    if(idZalogowanegoUsera > 0) {
        return true;
    } else {
        return false;
    }
}

void UserMenager::zmianaHaslaZalogowanegoUsera() {
    string noweHaslo = "";

    if(czyUserJestZalogowany()) {
        cout << "Podaj nowe haslo: ";
        noweHaslo = MetodyPomocnicze::wczytajLinie();

        for (vector <User>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++) {
            if (itr -> pobierzId() == idZalogowanegoUsera) {
                itr -> ustawHaslo(noweHaslo);
                cout << "Haslo zostalo zmienione." << endl << endl;
                system("pause");
            }
        }
        plikZUserami.zapiszWszystkichUserowDoPliku(uzytkownicy);
    } else {
        cout << "Aby zmienic haslo, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

*/
