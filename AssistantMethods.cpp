#include "AssistantMethods.h"

string AssistantMethods::konwerjsaIntNaString(int liczba) {
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string AssistantMethods::wczytajLinie() {
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
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

int AssistantMethods::konwersjaStringNaInt(string liczba) {
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}

string AssistantMethods::pobierzLiczbe(string tekst, int pozycjaZnaku) {
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true) {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int AssistantMethods::wczytajLiczbeCalkowita(){
    string wejscie = "";
    int liczba = 0;

    while(true){
        getline(cin, wejscie);
        stringstream myStream(wejscie);
        if(myStream >> liczba){
            break;
        }
        cout << "To nie jest liczba. Wpisz ponownie." << endl;
    }
    return liczba;
}

string AssistantMethods::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst){
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}
