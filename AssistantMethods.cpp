#include "AssistantMethods.h"

string AssistantMethods::convertionIntOnString(int intVar)
{
    ostringstream ss;
    ss << intVar;
    string str = ss.str();
    return str;
}

int AssistantMethods::convertionStringOnInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;
    return numberInt;
}

string AssistantMethods::convertionUnsignedShortOnString(unsigned short var) {
    ostringstream ss;
    ss << var;
    string str = ss.str();
    return str;
}

float AssistantMethods::convertionStringOnFloat(string numberStr) {
    float number;
    istringstream iss(numberStr);
    iss >> number;
    return number;
}

string AssistantMethods::loadLine() {
    string input = "";
    getline(cin, input);
    return input;
}

char AssistantMethods::loadChar() {
    string input = "";
    char varChar  = {0};
    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            varChar = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return varChar;
}

string AssistantMethods::getNumber(string text, int charPosition) {
    string number = "";
    while(isdigit(text[charPosition]) == true) {
        number += text[charPosition];
        charPosition ++;
    }
    return number;
}

int AssistantMethods::loadIntegerNumber(){
    string input = "";
    int number = 0;
    while(true){
        getline(cin, input);
        stringstream myStream(input);
        if(myStream >> number){
            break;
        }
        cout << "To nie jest liczba. Wpisz ponownie." << endl;
    }
    return number;
}

string AssistantMethods::changeFirstLetterOnUppercaseAndOthersOnLowercase(string text){
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

bool AssistantMethods::checkFormatDate(string dateStr){
    //format YYYY-MM-DD
    string yearStr, monthStr, dayStr;
    int yearInt, monthInt, dayInt;
    int amountDays;

    if(dateStr.length() < 10 || dateStr[4] != '-' || dateStr[7] != '-' ){
        cout << "Niepoprawny format!" << endl;
        return false;
    }

    yearStr = dateStr.substr(0,4);
    monthStr = dateStr.substr(5,2);
    dayStr = dateStr.substr(8,2);
    yearInt = atoi(yearStr.c_str());
    monthInt = atoi(monthStr.c_str());
    dayInt = atoi(dayStr.c_str());

    if ((yearInt < 2000) || (monthInt > 12) || (dayStr.length() > 31)){
        cout << "Niepoprawna data!" << endl;
        return false;
    } else {
        amountDays = amountOfDaysInMonth(monthInt, yearInt);
        if (amountDays < dayInt ) {
            cout << "Niepoprawna data!" << endl;
            return false;
        }
    }
    return true;
}

int AssistantMethods::amountOfDaysInMonth(int monthNumber, int year) {
    int daysNumber;
    switch(monthNumber) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        daysNumber = 31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        daysNumber = 30;
        break;

    case 2: {
        if(checkIfYearIsLeapYear(year))
            daysNumber = 29;
        else
            daysNumber = 28;
        break;
    }
    default:
        cout << "Niepoprawny numer miesiaca!" << endl;
    }
    return daysNumber;
}

bool AssistantMethods::checkIfYearIsLeapYear(int year) {
    if((year%4 == 0) && (year%100 != 0) || (year%400 == 0))
        return true;
    else
        return false;
}

string AssistantMethods::getDateFromSelectedPeriod() {
    string dateStr;
    cout << endl << "Wybierz date formatu RRRR-MM-DD: ";
    dateStr = AssistantMethods::loadLine();
    string yearStr, monthStr, dayStr;
    while(AssistantMethods::checkFormatDate(dateStr)==false){
        cout << "Podaj ponownie date: ";
        cin >> dateStr;
    }
    return dateStr;
}

string AssistantMethods::getCurrentDate(){
    //format RRRR-MM-DD
    string dateStr, year, month, day;
    SYSTEMTIME st;
    GetLocalTime(&st); // unsigned short
    year = convertionUnsignedShortOnString(st.wYear);
    month = convertionUnsignedShortOnString(st.wMonth);
    day = convertionUnsignedShortOnString(st.wDay);
    if(month.size() == 1){
        month = "0" + month;
    }
    if(day.size() == 1){
        day = "0" + day;
    }
    dateStr = year + "-" + month + "-" + day;
    return dateStr;
}

float AssistantMethods::getFloatNumber() {
    float numberFloat;
    string number;
    cin >> number;
    for(int i = 0; i < number.length(); i++) {
        if(number[i] == ',') {
            number[i] = '.';
        }
    }
    numberFloat = convertionStringOnFloat(number);
    return numberFloat;
}

int AssistantMethods::changeDateOnIntWithoutDashes(string dateStr){
    //format YYYYMMDD
    int date = 0;
    dateStr.erase(4,1);
    dateStr.erase(6,1);
    date = atoi(dateStr.c_str());
    return date;
}

int AssistantMethods::changeDateOnInt(string dateStr){
    int date = 0;
    dateStr.erase(4,1);
    dateStr.erase(6,1);
    date = atoi(dateStr.c_str());
    return date;
}

string AssistantMethods::changeDateOnString(int dateInt){
    string date = "";
    date = convertionIntOnString(dateInt);
    date.insert(4,"-");
    date.insert(7,"-");
    return date;
}

string AssistantMethods::getMonthFromDate(string date){
    string month;
    date.erase(0,5);
    date.erase(2,3);
    month = date;
    return month;
}

bool AssistantMethods::sortByDateForIncomes(Income date1, Income date2){
    return date1.getDate() < date2.getDate();
}

bool AssistantMethods::sortByDateForExpenses(Expense date1, Expense date2){
    return date1.getDate() < date2.getDate();
}

string AssistantMethods::getDateOfPreviousMonth() {
    //format RRRR-MM-DD
    string date, year, month, day;
    SYSTEMTIME st;
    GetSystemTime(&st); // unsigned short
    year = convertionUnsignedShortOnString(st.wYear);
    month = convertionUnsignedShortOnString(st.wMonth - 1);
    if(month == "0") {
        year = convertionUnsignedShortOnString(st.wYear-1);
    }
    day = convertionUnsignedShortOnString(st.wDay);
    if(month.size() == 1) {
        month = "0" + month;
    }
    if(day.size() == 1) {
        day = "0" + day;
    }
    if(month == "00") {
        month ="12";
    }
    date = year + "-" + month + "-" + day;
    return date;
}
