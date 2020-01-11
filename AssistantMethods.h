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
    static string IntOnStringConvertion(int number);
    static string loadLine();
    static char loadChar();
    static int StringOnIntConvertion(string number);
    static string getNumber(string text, int charPosition);
    static int loadIntegerNumber();
    static string changeFirstLetterOnUppercaseAndOthersOnLowercase(string text);
    static bool checkFormatDate(string dateStr);
    static int amountOfDaysInMonth(int monthNumber, int year);
    static bool checkIfYearIsLeapYear(int year);
    static int getDateFromSelectedPeriod();
    static int getCurrentDate();
    static string convertUnsignedShortOnString(unsigned short var);
    static float convertionStringOnFloat(string numberStr);
    static float getFloatNumber();
};

#endif
