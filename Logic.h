#ifndef ZADANIE_3_PROJEKTOWE_LOGIC_H
#define ZADANIE_3_PROJEKTOWE_LOGIC_H
#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <ctime>
#include "Zadania.h"

using namespace std;

class Logic {
private:
    int iloscZadan ;
    bool sprawdzenieDaty(string s);
    bool sprawdzeniePriorytetu(int i);
    int pobraniePriorytetu();
    string pobranieDaty();
public:
    vector <Zadanie> lista;
    Zadanie *tabZad;
    Logic();
    ~Logic();
    void wyswietlZadania(string data);
    void wyswietlenieZadaniaNaKonkretnyDzien();
    void wyswietlMenu();
    void dodajZadanie();
    void usunZadanie();
    void usunZadaniaZDnia();
    void wyswietlWszystkieZadania();
    bool koniecProgramu();
    int iloscZadanNaDzien(string iloscZadan);
    string dzisiejszaData();
    void save();
    void load();
};


#endif //ZADANIE_3_PROJEKTOWE_LOGIC_H
