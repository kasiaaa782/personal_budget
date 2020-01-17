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
        cout << "PRZYCHODY: " << endl;
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
}

float IncomesMenager::sumOfIncomesOfCurrentMonth(){
    float sum = 0;
    string currentMonth = AssistantMethods::getMonthFromDate(AssistantMethods::getCurrentDate());
    string month;
    if(!incomes.empty()){
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            month = AssistantMethods::getMonthFromDate(AssistantMethods::changeDateOnString(itr -> getDate()));
            if(month == currentMonth){
                sum = sum + itr->getAmount();
            }
        }
    }
    return sum;
}

void IncomesMenager::printIncomesOfPreviousMonth(){

    string previousMonth = AssistantMethods::getMonthFromDate(AssistantMethods::getDateOfPreviousMonth());
    string month;
    if(!incomes.empty()){
        cout << "PRZYCHODY: " << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            month = AssistantMethods::getMonthFromDate(AssistantMethods::changeDateOnString(itr -> getDate()));
            if(month == previousMonth){
                printIncomeData(*itr);
            }
        }
        cout << endl;
    }
    else{
        cout << endl << "Nie wprowadzono zadnych przychodow." << endl << endl;
    }
}

float IncomesMenager::sumOfIncomesOfPreviousMonth(){
    float sum = 0;
    string previousMonth = AssistantMethods::getMonthFromDate(AssistantMethods::getDateOfPreviousMonth());
    string month;
    if(!incomes.empty()){
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            month = AssistantMethods::getMonthFromDate(AssistantMethods::changeDateOnString(itr -> getDate()));
            if(month == previousMonth){
                sum = sum + itr->getAmount();
            }
        }
    }
    return sum;
}
