//
// Created by l_w on 11.02.2022.
//

#ifndef ZADANIE_3_PROJEKTOWE_ZADANIA_H
#define ZADANIE_3_PROJEKTOWE_ZADANIA_H
#include <ctime>
#include <iostream>
using namespace std;

class Zadanie {
private:
    string data;
    string trescZadania;
    int priorytet;
public:
    Zadanie(string data, string trescZadania, int priorytet) ;
    int numer=0;
    string getData() ;
    string getTrescZadania() ;
    int getPriorytet() ;
    string toString();
};

#endif //ZADANIE_3_PROJEKTOWE_ZADANIA_H
