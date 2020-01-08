#include "AssistantMethods.h"

string AssistantMethods::IntOnStringConvertion(int number) {
    ostringstream ss;
    ss << number;
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

int AssistantMethods::StringOnIntConvertion(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
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
