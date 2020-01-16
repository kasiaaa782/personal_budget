#ifndef ASSISTANTMETHODS.H
#define ASSISTANTMETHODS

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <windows.h>
#include <winbase.h>

using namespace std;

class AssistantMethods{

public:
    static string convertionIntOnString(int intVar);
    static int convertionStringOnInt(string number);
    static string convertionUnsignedShortOnString(unsigned short var);
    static float convertionStringOnFloat(string numberStr);
    static string loadLine();
    static char loadChar();
    static string getNumber(string text, int charPosition);
    static int loadIntegerNumber();
    static string changeFirstLetterOnUppercaseAndOthersOnLowercase(string text);
    static bool checkFormatDate(string dateStr);
    static int amountOfDaysInMonth(int monthNumber, int year);
    static bool checkIfYearIsLeapYear(int year);
    static string getDateFromSelectedPeriod();
    static string getCurrentDate();
    static float getFloatNumber();
    static int changeDateOnIntWithoutDashes(string dateStr);
    static int changeDateOnInt(string dateStr);
    static string changeDateOnString(int dateInt);
};

#endif
