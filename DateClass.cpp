#include "DateClass.h"

bool DateClass::checkFormatDate(string dateStr){
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

int DateClass::amountOfDaysInMonth(int monthNumber, int year) {
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

bool DateClass::checkIfYearIsLeapYear(int year) {
    if((year%4 == 0) && (year%100 != 0) || (year%400 == 0))
        return true;
    else
        return false;
}

string DateClass::getEnteredDateFromUser() {
    string dateStr;
    cout << endl << "Wybierz date formatu RRRR-MM-DD: ";
    dateStr = AssistantMethods::loadLine();
    string yearStr, monthStr, dayStr;
    while(DateClass::checkFormatDate(dateStr)==false){
        cout << "Podaj ponownie date: ";
        cin >> dateStr;
    }
    return dateStr;
}

string DateClass::getCurrentDate(){
    //format RRRR-MM-DD
    string dateStr, year, month, day;
    SYSTEMTIME st;
    GetLocalTime(&st); // unsigned short
    year = AssistantMethods::convertionUnsignedShortOnString(st.wYear);
    month = AssistantMethods::convertionUnsignedShortOnString(st.wMonth);
    day = AssistantMethods::convertionUnsignedShortOnString(st.wDay);
    if(month.size() == 1){
        month = "0" + month;
    }
    if(day.size() == 1){
        day = "0" + day;
    }
    dateStr = year + "-" + month + "-" + day;
    return dateStr;
}

int DateClass::changeDateOnIntWithoutDashes(string dateStr){
    //format YYYYMMDD
    int date = 0;
    dateStr.erase(4,1);
    dateStr.erase(6,1);
    date = atoi(dateStr.c_str());
    return date;
}

int DateClass::changeDateOnInt(string dateStr){
    int date = 0;
    dateStr.erase(4,1);
    dateStr.erase(6,1);
    date = atoi(dateStr.c_str());
    return date;
}

string DateClass::changeDateOnString(int dateInt){
    string date = "";
    date = AssistantMethods::convertionIntOnString(dateInt);
    date.insert(4,"-");
    date.insert(7,"-");
    return date;
}

string DateClass::getYearFromDate(string date){
    string year;
    date.erase(4,6);
    year = date;
    return year;
}

string DateClass::getMonthFromDate(string date){
    string month;
    date.erase(0,5);
    date.erase(2,3);
    month = date;
    return month;
}

string DateClass::getDayFromDate(string date){
    string day;
    date.erase(0,8);
    day = date;
    return day;
}

bool DateClass::sortByDateForIncomes(Income date1, Income date2){
    return date1.getDate() < date2.getDate();
}

bool DateClass::sortByDateForExpenses(Expense date1, Expense date2){
    return date1.getDate() < date2.getDate();
}

string DateClass::getDateOfPreviousMonth() {
    //format RRRR-MM-DD
    string date, year, month, day;
    SYSTEMTIME st;
    GetSystemTime(&st); // unsigned short
    year = AssistantMethods::convertionUnsignedShortOnString(st.wYear);
    month = AssistantMethods::convertionUnsignedShortOnString(st.wMonth - 1);
    if(month == "0") {
        year = AssistantMethods::convertionUnsignedShortOnString(st.wYear-1);
    }
    day = AssistantMethods::convertionUnsignedShortOnString(st.wDay);
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
