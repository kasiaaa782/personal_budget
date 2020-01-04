#ifndef ASSISTANTMETHODS.H
#define ASSISTANTMETHODS

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class AssistantMethods{

public:
    static string konwerjsaIntNaString(int liczba);
    static string wczytajLinie();
    static char wczytajZnak();
    static int konwersjaStringNaInt(string liczba);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static int wczytajLiczbeCalkowita();
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
};

#endif
