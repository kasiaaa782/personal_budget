#ifndef ASSISTANTMETHODS.H
#define ASSISTANTMETHODS

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

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
};

#endif
