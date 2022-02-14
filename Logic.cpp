#include "Logic.h"
  Logic::Logic() {
    iloscZadan =1;
     Zadanie *tabZad[iloscZadan];
}
void Logic::wyswietlZadania(string data) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    cout<< "----------------------------------------------"<<endl;
    cout<<"         ZADANIA DO WYKONANIA NA DZIEN " << data <<":" <<endl;
    if (iloscZadanNaDzien(data) != 0){
        for(int i =0; i<lista.size();i++)
            if(lista[i].getData()==data)
                cout<< lista[i].getTrescZadania() << + "O PRIORYTECIE : " + lista[i].getPriorytet() <<endl;
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
        cout << "                 BRAK ZADAN " << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
void Logic::wyswietlenieZadaniaNaKonkretnyDzien(){
    string Data;
    Data = pobranieDaty();
    wyswietlZadania(Data);
}
void Logic::wyswietlMenu() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"----------------------------------------------"<<endl;
    cout<<"MENU WYBORU"<<endl;
    cout<<"1.Dodaj zadanie na dany dzien"<<endl;
    cout<<"2.Pokaz zadanie zdefiniowane na dany dzien"<<endl;
    cout<<"3.Pokaz wszystkie zadania"<<endl;
    cout<<"4.Usun zadanie"<<endl;
    cout<<"5.Usun zadania z dnia"<<endl;
    cout<<"6.Wyjscie z programu"<<endl;
    cout<<"----------------------------------------------"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
void Logic::dodajZadanie( ) {
    string zad,data;
    int prior;
    data=pobranieDaty();
    cout<<"Podaj tresc zadania: "<<endl;
    cin.sync();
    getline(cin, zad);
    prior=pobraniePriorytetu();
    lista.push_back(Zadanie (data,zad,prior));
}
void Logic::usunZadanie(){
    string data;
    data=pobranieDaty();
    int n=0;
    int wybor;

    for(int i =0; i<lista.size();i++)
        if(lista[i].getData()==data)
            lista[i].numer =++n;
    if (n>0){
        cout<< "Podaj numer zadania, ktore chcesz usunac :"<<endl;
        for(int i =0; i<lista.size();i++)
            if(lista[i].getData()==data)
                cout<< lista[i].numer <<"."<<lista[i].getTrescZadania()<<endl;
        cin>>wybor;
        for(int i =0; i<lista.size();i++)
               if (lista[i].numer==wybor)
                 lista.erase(lista.begin()+i);
    }else
        cout << " W tym dniu nie ma zadan do wykonania zadan"<<endl;
    for(int i =0; i<lista.size();i++)
            lista[i].numer =0;
}
void Logic::usunZadaniaZDnia() {
    string data;
    cout << "Z ktorego dnia chcesz usunac zadanie? (format daty: DD.MM.YYYY)"<<endl;
    data=pobranieDaty();
    for(int i =0; i<lista.size();i++)
        if(lista[i].getData()==data)
            lista.erase(lista.begin()+i);
    cout << " Zadania z dnia "<< data << " zostaly usuniete"<<endl;
}
bool Logic::koniecProgramu() {
    char a;
    cout<<" Czy na pewno chcesz wyjsc? Jesli tak to wpisz 'T' i naczisnij ENTER"<<endl;
    cin>>a;
    a= tolower(a);
    if(a =='t')
         return false;
}
void Logic:: save() {
    ofstream plik("plik.txt");
    for(vector<Zadanie>::iterator i = lista.begin();i<lista.end();i++)
        plik<<i->toString();
    plik.close();
}
void Logic::load() {
    ifstream plik("plik.txt");
    while(plik){
        string i,n;
        int p;
        plik>>i>>n>>p;
        Zadanie tmp(i,n,p);
        lista.push_back(tmp);
    }
}
string Logic::dzisiejszaData() {
    string s;
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    if (now->tm_mday <10)
        s="0"+to_string(now->tm_mday)+".";
    else
        s=to_string(now->tm_mday)+".";
    if (now->tm_mon <10)
        s= s + "0"+to_string(now->tm_mon +1) +".";
    else
        s= s +to_string(now->tm_mon +1) +".";
    s=s +to_string(now->tm_year + 1900);
    return s;
}
int Logic::iloscZadanNaDzien(string dzien) {
    int ilosc =0;
    for (int i = 0; i < lista.size(); ++i)
        if (lista[i].getData()==dzien)
            ilosc++;
    return ilosc;
}
void Logic::wyswietlWszystkieZadania() {
 cout<<"Wszystkie zadania do wykonania:"<<endl;
    if (!lista.empty())
        for (int i = 0; i < lista.size(); ++i)
            cout<< "Zadanie o priorytecie: "<<lista[i].getPriorytet()<<" z dnia "<< lista[i].getData() <<" : "<<lista[i].getTrescZadania()<<endl;
    else
        cout<< "Nie ma zadan";
}
bool Logic::sprawdzenieDaty(string s) {
    string current;
    int num;
    istringstream iss(s);
    vector<int> vinput;
    while(getline(iss, current, '.')) {
        try{
            num = stoi(current);
        }
        catch(exception & ) {
            cout<<"Nieprawidlowy format";
        };
        vinput.push_back(num);
    }
    if (vinput.size()!=3)
        return false;
           else if (!(vinput[0] >0 && vinput[0] < 31))
                return false;
            else if (!(vinput[1] >0 && vinput[1] < 13))
                return false;
                else if (!(vinput[2] >2021 && vinput[2] < 3000))
                    return false;
                    else
                        return true;
}
string Logic::pobranieDaty() {
    string str;
    do{
        cout<<"Podaj date : (format daty: DD.MM.YYYY)"<<endl;
        cin>>str;
        if (!sprawdzenieDaty(str))
            cout<<"Nieprawidlowa data" << endl;
    } while (!sprawdzenieDaty(str));
    return str;
}
bool Logic::sprawdzeniePriorytetu(int priorytet) {
    if (priorytet >0 && priorytet < 10)
        return true;
    else
        return false;
}
int Logic::pobraniePriorytetu() {
    int prio;
    do{
        cout<<"Podaj priorytet : (od 1 do 9)"<<endl;
        cin>>prio;
        if (!sprawdzeniePriorytetu(prio))
            cout<<"Nieprawidlowy priorytet" << endl;
    } while (!sprawdzeniePriorytetu(prio));
    return prio;
}
Logic::~Logic() {
    destroy(lista.begin(), lista.end());
}
