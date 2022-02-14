//
// Created by l_w on 11.02.2022.
//

#include "Zadania.h"

 string Zadanie::getData()  {
    return data;
}

 string Zadanie::getTrescZadania()  {
    return trescZadania;
}

int Zadanie::getPriorytet()  {
    return priorytet;
}

Zadanie::Zadanie(string data, string trescZadania, int priorytet) {
    this->data =data;
    this->trescZadania=trescZadania;
    this->priorytet= priorytet;
}
string Zadanie::toString()
{
    return (data+" "+trescZadania+" "+ to_string(priorytet)+"\n");
}

