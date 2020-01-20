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

string AssistantMethods::convertionFloatOnString(float floatNumber) {
    ostringstream ss;
    ss << floatNumber;
    string str = ss.str();
    return str;
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

string AssistantMethods::getNumberFromText(string text, int charPosition) {
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
