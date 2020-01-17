#include "IncomesMenager.h"

void IncomesMenager::userLogout() {
    incomes.clear();
}
void IncomesMenager::addIncome() {
    system("cls");
    Income income;
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    income = enterDataNewIncome();

    incomes.push_back(income);
    if(incomesFile.joinIncomeToFile(income)) {
        cout << "Nowy przychod zostal dodany." << endl;
    } else {
        cout << "Blad. Nie udalo sie dodac nowego przychodu do pliku.";
    }
    system("pause");
}

Income IncomesMenager::enterDataNewIncome() {
    Income income;
    string item;
    float amount;
    int date;

    income.setUserID(LOGGED_USER_ID);
    income.setIncomeID(incomesFile.getLastIncomeID() + 1);

    date = getDateFromUser();

    cout << "Podaj rodzaj przychodu (np.  wyplata itd.) : ";
    item = AssistantMethods::loadLine();
    cout << endl;

    cout << "Podaj wysokosc przychodu (w zl.): ";
    amount = AssistantMethods::getFloatNumber();
    cout << endl;

    income.setDate(date);
    income.setItem(item);
    income.setAmount(amount);

    return income;
}

int IncomesMenager::getDateFromUser() {
    string dateStr;
    int date;
    cout << "Podaj date: " << endl;
    cout << "1. Z dnia dzisiejszego." << endl;
    cout << "2. Wybierz inna date." << endl;
    cout << "---" << endl;
    cout << "Twoj wybor: ";

    while(true) {
        switch(AssistantMethods::loadChar()) {
        case '1':
            cout << endl << "Wybrano date: ";
            dateStr = AssistantMethods::getCurrentDate();
            cout << dateStr;
            cout << endl << endl;
            date = AssistantMethods::changeDateOnInt(dateStr);
            return date;
        case '2': {
            dateStr = AssistantMethods::getDateFromSelectedPeriod();
            cout << endl;
            date = AssistantMethods::changeDateOnInt(dateStr);
            return date;
        }
        default:
            cout << endl << "Nie ma takiej opcji w menu. Sprobuj ponownie: " ;
            break;
        }
    }
}

void IncomesMenager::printIncomeData(Income income){
    cout << endl << "ID przychodu:         " << income.getIncomeID() << endl;
    cout << "Data:                 " << AssistantMethods::changeDateOnString(income.getDate()) << endl;
    cout << "Rodzaj przychodu:     " << income.getItem()<< endl;
    cout << "Wysokosc przychodu:   " << income.getAmount() << endl;
}

void IncomesMenager::printIncomesOfCurrentMonth(){

    string currentMonth = AssistantMethods::getMonthFromDate(AssistantMethods::getCurrentDate());
    string month;
    if(!incomes.empty()){
        cout << "PRZYCHODY Z OBECNEGO MIESIACA: " << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            month = AssistantMethods::getMonthFromDate(AssistantMethods::changeDateOnString(itr -> getDate()));
            if(month == currentMonth){
                printIncomeData(*itr);
            }
        }
        cout << endl;
    }
    else{
        cout << endl << "Nie wprowadzono zadnych przychodow." << endl << endl;
    }
    system("pause");
}

/*void IncomesMenager::searchIncomesOfCurrentMonth(){
    system("cls");
    //int date = AssistantMethods::changeDateOnIntWithoutDashes(AssistantMethods::getCurrentDate());
    string date = AssistantMethods::getCurrentDate();
    //format date YYYY-MM-DD
    string currentMonth = date.substr(5,2);

    if(!incomes.empty()){
        cout << "PRZYCHODY Z OBECNEGO MIESIACA: " << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            if(itr -> getDate().substr(5,2)) == currentMonth){
                printIncomeData(*itr);
            }
        }
        cout << endl;
    }
    else{
        cout << endl << "Nie wprowadzono zadnych przychodow." << endl << endl;
    }
    system("pause");
}

void IncomesMenager::printIncomeData(Income income){
    cout << endl << "ID przychodu:         " << income.getIncomeID() << endl;
    cout << "Data:                 " << income.getDate() << endl;
    cout << "Rodzaj przychodu:     " << income.getItem()<< endl;
    cout << "Wysokosc przychodu:   " << income.getAmount() << endl;
}

void AdresatMenadzer::wyswietlWszystkichAdresatow(){
    system("cls");
    if (!adresaci.empty()){
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else{
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenadzer::wyswietlDaneAdresata(Adresat adresat){
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

char AdresatMenadzer::wybierzOpcjeZMenuUzytkownika(){
    char wybor;
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();
    return wybor;
}

void AdresatMenadzer::wylogowanieUzytkownika(){
    adresaci.clear();
}

void AdresatMenadzer::usuwanieAdresata(){
    int idUsunietegoAdresata;
    idUsunietegoAdresata = usunAdresata();
    plikZAdresatami.ustawIdOstatniegoAdresata(plikZAdresatami.podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresataZPliku(idUsunietegoAdresata));
}

int AdresatMenadzer::usunAdresata(){
    int idUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> pobierzId() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't')
            {
                plikZAdresatami.usunWybranegoAdresataZPliku(idUsuwanegoAdresata);
                adresaci.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                return idUsuwanegoAdresata;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return 0;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
    return 0;
}

int AdresatMenadzer::podajIdWybranegoAdresata(){
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

void AdresatMenadzer::edytujAdresata()
{
    system("cls");
    int idEdytowanegoAdresata = 0;

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;

            switch (wybierzOpcjeZMenuEdycja())
            {
            case '1':
                cout << "Podaj nowe imie: ";
                adresaci[i].ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie()));
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                adresaci[i].ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie()));
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail(MetodyPomocnicze::wczytajLinie());
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres(MetodyPomocnicze::wczytajLinie());
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

void AdresatMenadzer::zaktualizujDaneWybranegoAdresata(Adresat adresat){

    plikZAdresatami.edytujAdresataWPliku(adresat);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

char AdresatMenadzer::wybierzOpcjeZMenuEdycja(){
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
} */
