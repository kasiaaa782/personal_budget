#ifndef ASSISTANTMETHODS.H
#define ASSISTANTMETHODS.H

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <windows.h>

using namespace std;

class AssistantMethods{

public:
    static string convertionIntOnString(int intVar);
    static int convertionStringOnInt(string number);
    static string convertionUnsignedShortOnString(unsigned short var);
    static float convertionStringOnFloat(string numberStr);
    static string convertionFloatOnString(float floatNumber);
    static string loadLine();
    static char loadChar();
    static int loadIntegerNumber();
    static string changeFirstLetterOnUppercaseAndOthersOnLowercase(string text);
    static string getNumberFromText(string text, int charPosition);
    static float getFloatNumber();
};

#endif
