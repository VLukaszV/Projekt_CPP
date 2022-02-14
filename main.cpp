#include <iostream>
#include "Logic.h"
#include "Zadania.h"
using namespace std;

int main() {
    int wybor;
    Logic logika;
    logika.load();
    bool wyjscie =true;
    do {
        logika.wyswietlZadania(logika.dzisiejszaData());
        logika.wyswietlMenu();
        cout << "Prosze podac numer: " << endl;
        cin >> wybor;
        switch (wybor) {
            case 1:
                logika.dodajZadanie();
                break;
            case 2:
                logika.wyswietlenieZadaniaNaKonkretnyDzien();
                break;
            case 3:
                logika.wyswietlWszystkieZadania();
                break;
            case 4:
                logika.usunZadanie();
                break;
            case 5:
                logika.usunZadaniaZDnia();
                break;
            case 6:
                wyjscie =logika.koniecProgramu();
               break;
        }
    } while (wyjscie);
    logika.save();
    return 0;
}
