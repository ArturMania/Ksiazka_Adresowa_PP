#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <sstream>
#include <string>
#include "Users.h"

using namespace std;

struct KsiazkaAdresowa {
    int id,idUzytkownikaKsiazkiAdresowej;
    string imie,nazwisko,nrtelefonu,email,adres;
};

/*struct Uzytkownik {
    int idUzytkownika;
    string nazwa,haslo;

};

int rejestracjaUzytkownika(vector<Uzytkownik>&uzytkownicy) {
    system ("cls");
    string nazwa,haslo;
    int idUzytkownika,i;
    fstream plikuzytkownicy;
    cout<<"Podaj nazwe uzytkownika ktora chcesz zarejestrowac: "<<endl;
    cin>>nazwa;
    while(i<uzytkownicy.size()) {
        if(uzytkownicy[i].nazwa==nazwa) {
            cout<<"Podany login jest juz zajety. Podaj inna nazwe uzykownika: "<<endl;
            cin>>nazwa;
        } else {
            i++;
        }
    }
    cout<<"Podaj haslo: "<<endl;
    cin>>haslo;
    Uzytkownik Dane;
    if(uzytkownicy.size()==0) {
        idUzytkownika=1;
    } else {
        idUzytkownika=uzytkownicy[uzytkownicy.size()-1].idUzytkownika+1;
    }
    Dane.idUzytkownika=idUzytkownika;
    Dane.nazwa=nazwa;
    Dane.haslo=haslo;
    uzytkownicy.push_back(Dane);
    plikuzytkownicy.open("Uzytkownicy.txt",ios::out|ios::app);
    if(plikuzytkownicy.good()) {
        plikuzytkownicy<<idUzytkownika<<"|"<<nazwa<<"|"<<haslo<<"|"<<endl;
    } else {
        cout<<"Nie istnieje plik Uzytkownicy.txt"<<endl;
    }
    plikuzytkownicy.close();
    return uzytkownicy.size();
}

void wczytywanieUzytkownikow(vector<Uzytkownik>&uzytkownicy) {
    int idUzytkownika,pozycja;
    string wczytywaneDane,linia;
    Uzytkownik Dane;
    fstream plik;
    string nazwa,haslo;
    plik.open("Uzytkownicy.txt",ios::in);

    while(getline(plik,linia)) {
        if(linia=="")
            continue;
        stringstream liniaSS (linia);
        while(getline(liniaSS,wczytywaneDane,'|')) {
            switch(pozycja) {
            case 0:
                Dane.idUzytkownika=stoi(wczytywaneDane);
                break;
            case 1:
                Dane.nazwa = wczytywaneDane;
                break;
            case 2:
                Dane.haslo = wczytywaneDane;
                break;
            }
            pozycja++;
        }
        pozycja=0;
        uzytkownicy.push_back(Dane);
    }
    plik.close();
}

int logowanieUzytkownika(vector<Uzytkownik>&uzytkownicy) {
    string nazwa,haslo;
    int i=0;
    system ("cls");
    cout<<"Podaj login:";
    cin>>nazwa;
    while(i<uzytkownicy.size()) {
        if(nazwa==uzytkownicy[i].nazwa) {
            cout<<"Wprowadz haslo:";
            cin>>haslo;
            if(uzytkownicy[i].haslo==haslo) {
                cout<<"Zalogowano!"<<endl;
                Sleep(1000);
                return uzytkownicy[i].idUzytkownika;
            } else {
                cout<<"Niepoprawne haslo!"<<endl;
                Sleep(1500);
                return 0;
            }
        }
        i++;
    }
    cout<<"Niepoprawny login!"<<endl;
    Sleep(1500);
    return 0;
}

void zmianaHasla(vector<Uzytkownik>&uzytkownicy,int idZalogowanegoUzytkownika) {
    system ("cls");
    string haslo;
    cout<<"Podaj nowe haslo: ";
    cin>>haslo;
    for(int i=0; i<uzytkownicy.size(); i++) {
        if(uzytkownicy[i].idUzytkownika==idZalogowanegoUzytkownika) {
            uzytkownicy[i].haslo=haslo;
            fstream plik;
            plik.open("Uzytkownicy.txt",ios::out);
            for(int i=0; i<uzytkownicy.size(); i++) {
                plik<<uzytkownicy[i].idUzytkownika<<"|";
                plik<<uzytkownicy[i].nazwa<<"|";
                plik<<uzytkownicy[i].haslo<<"|"<<endl;
            }
            plik.close();
            cout<<"Haslo zostalo zmienione"<<endl;
            Sleep(1500);
        }
    }
}
*/
void wczytywanieKsiazkiAdresowej(vector <KsiazkaAdresowa>&adresaci) {
    KsiazkaAdresowa Dane;
    fstream plik;
    string wczytywanDane,linia;
    int pozycja=0,id;
    string imie,nazwisko,nrtelefonu,email,adres;
    plik.open("KsiazkaAdresowa.txt",ios::in);
    while(getline(plik,linia)) {
        if(linia=="")
            continue;
        stringstream liniaSS (linia);
        while(getline(liniaSS,wczytywanDane,'|')) {
            switch(pozycja) {
            case 0:
                Dane.id=stoi(wczytywanDane);
                break;
            case 1:
                Dane.idUzytkownikaKsiazkiAdresowej=stoi(wczytywanDane);
                break;
            case 2:
                Dane.imie = wczytywanDane;
                break;
            case 3:
                Dane.nazwisko = wczytywanDane;
                break;
            case 4:
                Dane.nrtelefonu = wczytywanDane;
                break;
            case 5:
                Dane.email = wczytywanDane;
                break;
            case 6:
                Dane.adres = wczytywanDane;
                break;
            }
            pozycja++;
        }
        pozycja=0;
        adresaci.push_back(Dane);
    }
    plik.close();
}
void wczytywanieKsiazkiAdresowejUzytkownika(vector <KsiazkaAdresowa>&adresaci,int idZalogowanegoUzytkownika) {
    KsiazkaAdresowa Dane;
    fstream plik;
    string wczytywanDane,linia;
    int pozycja=0,id;
    string imie,nazwisko,nrtelefonu,email,adres;
    plik.open("KsiazkaAdresowa.txt",ios::in);
    while(getline(plik,linia)) {
        if(linia=="")
            continue;
        stringstream liniaSS (linia);
        while(getline(liniaSS,wczytywanDane,'|')) {
            switch(pozycja) {
            case 0:
                Dane.id=stoi(wczytywanDane);
                break;
            case 1:
                Dane.idUzytkownikaKsiazkiAdresowej=stoi(wczytywanDane);
                break;
            case 2:
                Dane.imie = wczytywanDane;
                break;
            case 3:
                Dane.nazwisko = wczytywanDane;
                break;
            case 4:
                Dane.nrtelefonu = wczytywanDane;
                break;
            case 5:
                Dane.email = wczytywanDane;
                break;
            case 6:
                Dane.adres = wczytywanDane;
                break;
            }
            pozycja++;
        }
        pozycja=0;
        if(Dane.idUzytkownikaKsiazkiAdresowej==idZalogowanegoUzytkownika) {
            adresaci.push_back(Dane);
        }
    }
    plik.close();
}

void dodajKontakt(vector <KsiazkaAdresowa>&adresaci,int idZalogowanegoUzytkownika) {
    string imie,nazwisko,nrtelefonu,email,adres;
    int osobaID=0;
    wczytywanieKsiazkiAdresowej(adresaci);
    system ("cls");
    cout<<"Podaj Imie:";
    cin>>imie;
    cout<<"Podaj Nazwisko:";
    cin>>nazwisko;
    cout<<"Podaj numer telefonu:";
    cin.sync();
    getline(cin,nrtelefonu);
    cout<<"Podaj adres email:";
    cin>>email;
    cout<<"Podaj adres:";
    cin.sync();
    getline(cin,adres);
    KsiazkaAdresowa Dane;
    if(adresaci.size()==0) {
        osobaID=1;
    } else {
        osobaID=adresaci[adresaci.size()-1].id+1;
    }
    Dane.imie=imie;
    Dane.nazwisko=nazwisko;
    Dane.nrtelefonu=nrtelefonu;
    Dane.email=email;
    Dane.adres=adres;
    Dane.id=osobaID;
    Dane.idUzytkownikaKsiazkiAdresowej=idZalogowanegoUzytkownika;
    adresaci.push_back(Dane);
    fstream plik;
    plik.open("KsiazkaAdresowa.txt",ios::out|ios::app);
    if(plik.good()) {
        plik<<osobaID<<"|"<<idZalogowanegoUzytkownika<<"|"<<imie<<"|"<<nazwisko<<"|"<<nrtelefonu<<"|"<<email<<"|"<<adres<<"|"<<endl;
        cout<<"Osoba "<<imie<<" "<<nazwisko<<" zapisano w rejestrze"<<endl;
        Sleep(1000);
    } else {
        cout<<"Nie istnieje plik KsiazkaAdresowa.txt"<<endl;
    }
    plik.close();
}

void zapisZmianPliku(vector <KsiazkaAdresowa>&adresaci,int idAdresata,int typOperacji) {
    string liniaTekstu="";
    fstream plik;
    plik.open("KsiazkaAdresowa.txt",ios::in);

    fstream plikTymczasowy;
    plikTymczasowy.open("KsiazkaAdresowa_tymczasowy.txt",ios::out);

    if(plik.good()==true) {
        if(typOperacji==0) {
            while(getline(plik,liniaTekstu)) {
                if(atoi(liniaTekstu.substr(0, 1).c_str())!=idAdresata) {
                    plikTymczasowy<<liniaTekstu<<endl;
                }
            }
        } else {
            while(getline(plik,liniaTekstu)) {
                if(atoi(liniaTekstu.substr(0, 1).c_str())==idAdresata) {
                    int i=0;
                    for(int i=0; i<adresaci.size(); i++) {
                        if((adresaci)[i].id==idAdresata) {
                            break;
                        }
                    }

                    plikTymczasowy<<adresaci[i].id<<"|";
                    plikTymczasowy<<adresaci[i].idUzytkownikaKsiazkiAdresowej<<"|";
                    plikTymczasowy<<adresaci[i].imie<<"|";
                    plikTymczasowy<<adresaci[i].nazwisko<<"|";
                    plikTymczasowy<<adresaci[i].nrtelefonu<<"|";
                    plikTymczasowy<<adresaci[i].email<<"|";
                    plikTymczasowy<<adresaci[i].adres<<"|"<<endl;

                } else {
                    plikTymczasowy<<liniaTekstu<<endl;
                }
            }
        }
    }
    plik.close();
    plikTymczasowy.close();
    remove("KsiazkaAdresowa.txt");
    rename("KsiazkaAdresowa_tymczasowy.txt","KsiazkaAdresowa.txt");
}

void wyswietlDaneJednejOsoby(KsiazkaAdresowa adresat) {
    cout<<"ID: "<<adresat.id<<endl;
    cout<<"ID Uzytkownika: "<<adresat.idUzytkownikaKsiazkiAdresowej<<endl;
    cout<<"Imie: "<<adresat.imie<<endl;
    cout<<"Nazwisko: "<<adresat.nazwisko<<endl;
    cout<<"Numer Telefonu: "<<adresat.nrtelefonu<<endl;
    cout<<"Email: "<<adresat.email<<endl;
    cout<<"Adres: "<<adresat.adres<<endl<<endl;
}

void wyswietlKontakty(vector <KsiazkaAdresowa>&adresaci,int idZalogowanegoUzytkownika) {
    system ("cls");
    adresaci.clear();
    wczytywanieKsiazkiAdresowejUzytkownika(adresaci,idZalogowanegoUzytkownika);
    for(int i=0; i<adresaci.size(); i++) {
        if(adresaci[i].idUzytkownikaKsiazkiAdresowej==idZalogowanegoUzytkownika) {
            wyswietlDaneJednejOsoby(adresaci[i]);
        }
    }
    cout<<"Nacisnij dowolny klawisz aby zakonczyc: "<<endl;
    getch();
}
void wyszukajKontaktpoImieniu(vector <KsiazkaAdresowa>&adresaci) {
    int ilosc=0;
    string imie;
    system("cls");
    cout<<"Podaj nazwisko osoby ktorej szukasz: ";
    cin>>imie;
    for(int i=0; i<adresaci.size(); i++) {
        if(imie==adresaci[i].imie) {
            wyswietlDaneJednejOsoby(adresaci[i]);
            ilosc++;
        }
    }
    if(ilosc==0) {
        cout<<"Nie ma osoby o takim nazwisku."<<endl;
    }
    cout<<"Wcisnij dowolny klawisz aby zakonczyc: "<<endl;
    getch();
}

void wyszukajKontaktpoNazwisku(vector <KsiazkaAdresowa>&adresaci) {
    int ilosc=0;
    string nazwisko;
    system("cls");
    cout<<"Podaj nazwisko osoby ktorej szukasz: ";
    cin>>nazwisko;
    for(int i=0; i<adresaci.size(); i++) {
        if(nazwisko==adresaci[i].nazwisko) {
            wyswietlDaneJednejOsoby(adresaci[i]);
            ilosc++;
        }
    }
    if(ilosc==0) {
        cout<<"Nie ma osoby o takim nazwisku."<<endl;
    }
    cout<<"Wcisnij dowolny klawisz aby zakonczyc: "<<endl;
    getch();
}
int usunKontakt(vector <KsiazkaAdresowa>&adresaci) {
    int id,i;
    char wybor;
    system ("cls");
    cout<<"Wprowadz ID adresata ktorego chcesz usunac: "<<endl;
    cin>>id;
    for(i=0; i<adresaci.size(); i++) {
        if((adresaci)[i].id == id) {
            break;
        }
    }
    if(i==adresaci.size()) {
        system( "cls" );
        cout << "Adresat o podanym ID nie istnieje!";
        Sleep(1000);
        system( "cls" );
        return adresaci.size();
    }

    cout<<"Czy napewno chcesz usunac "<<adresaci[i].imie<<" "<<adresaci[i].nazwisko<<" ? (t/n)"<<endl;
    wybor=getch();
    if(wybor=='t') {
        adresaci.erase(adresaci.begin()+(i));
        zapisZmianPliku(adresaci,id,0);
        cout<<"Kontakt usuniety."<<endl;
        Sleep(1000);
        system( "cls" );

    } else {
        cout<<"Adresat nie zostal usuniety."<<endl;
        Sleep(1000);
        system( "cls" );
    }
    return adresaci.size();
}

void edytujKontakt(vector <KsiazkaAdresowa>&adresaci) {
    char wybor;
    int id,i=0;
    system ("cls");
    string imie,nazwisko,nrtelefonu,email,adres;
    cout<<"Podaj ID adresata do edycji: ";
    cin>>id;
    for(i=0; i<adresaci.size(); i++) {
        if((adresaci)[i].id == id) {
            break;
        }
    }
    if(i==adresaci.size()) {
        system( "cls" );
        cout << "Adresat o podanym ID nie istnieje!";
        Sleep(1000);
        system( "cls" );
    }
    if(adresaci[i].id==id) {
        wyswietlDaneJednejOsoby(adresaci[i]);

        cout<<"Edycja adresata:"<<endl;
        cout<<"1. Imie "<<endl;
        cout<<"2. Nazwisko "<<endl;
        cout<<"3. Numer telefonu "<<endl;
        cout<<"4. Adres email "<<endl;
        cout<<"5. Adres "<<endl;
        cout<<"6. Zakoncz edycje "<<endl;
        cin>>wybor;
        while(true) {
            if(wybor=='1') {
                cout<<"Podaj imie: ";
                cin>>imie;
                adresaci[i].imie=imie;
                zapisZmianPliku(adresaci,id,1);
                cout<<"Dane zaktualizowane!";
                getch();
            }
            if(wybor=='2') {
                cout<<"Podaj nazwisko: ";
                cin>>nazwisko;
                adresaci[i].nazwisko=nazwisko;
                zapisZmianPliku(adresaci,id,1);
                cout<<"Dane zaktualizowane!";
                getch();
            }
            if(wybor=='3') {
                cout<<"Podaj numer telegonu: ";
                cin.sync();
                getline(cin,nrtelefonu);
                adresaci[i].nrtelefonu=nrtelefonu;
                zapisZmianPliku(adresaci,id,1);
                cout<<"Dane zaktualizowane!";
                getch();
            }
            if(wybor=='4') {
                cout<<"Podaj email: ";
                cin>>email;
                adresaci[i].email=email;
                zapisZmianPliku(adresaci,id,1);
                cout<<"Dane zaktualizowane!";
                getch();
            }
            if(wybor=='5') {
                cout<<"Podaj adres: ";
                cin.sync();
                getline(cin,adres);
                adresaci[i].adres=adres;
                zapisZmianPliku(adresaci,id,1);
                cout<<"Dane zaktualizowane!";
                getch();;
            }
            return;
        }
    } else {
        cout<<"Nie ma takiego Adresata!"<<endl;
        Sleep(1000);
        return ;
    }
}

int main() {
    //vector<Uzytkownik>uzytkownicy;
    vector <KsiazkaAdresowa>adresaci;
    int idZalogowanegoUzytkownika=0,liczbaZapisanychAdresow=0;
    UsersInterface usersInterface;
    while(true) {
        usersInterface.loadUsersFile();
        //wczytywanieUzytkownikow(uzytkownicy);
        int liczbaUzytkownikow;
        char wybor;
        if(idZalogowanegoUzytkownika==0) {
            system("cls");
            cout<<"Witaj w Twojej ksiazce adresowej!"<<endl;
            cout<<"1. Logowanie"<<endl;
            cout<<"2. Rejestracja"<<endl;
            cout<<"9. Zakoncz program"<<endl;
            cout<<"ID zalogowanego uzytkownika:"<<idZalogowanegoUzytkownika<<endl;
            cout<<"Twoj wybor: ";
            cin>>wybor;
            switch(wybor) {
            case '1':
                idZalogowanegoUzytkownika=usersInterface.login();
                break;
            case '2':
                usersInterface.registration();
                break;
            case '9':
                cout<<"Do zobaczenia!"<<endl;
                exit(0);
                break;
            }
        } else {
            wczytywanieKsiazkiAdresowejUzytkownika(adresaci,idZalogowanegoUzytkownika);
            liczbaZapisanychAdresow=adresaci.size();
            char wybor;

            system("cls");
            cout<<"1. Dodaj Adresata"<<endl;
            cout<<"2. Wyszukiwanie po Imieniu"<<endl;
            cout<<"3. Wyszukiwanie po Nazwisku"<<endl;
            cout<<"4. Wyswietl wszystkie kontakty"<<endl;
            cout<<"5. Usun adresata"<<endl;
            cout<<"6. Edytuj adresata"<<endl;
            cout<<"7. Zmiana hasla"<<endl;
            cout<<"8. Wyloguj sie"<<endl;
            cout<<"9. Zakoncz program"<<endl;
            cout<<"ID uzytkownika: "<<idZalogowanegoUzytkownika<<endl;
            cout<<"Twoj wybor: ";
            cin>>wybor;
            switch(wybor) {
            case '1':
                dodajKontakt(adresaci,idZalogowanegoUzytkownika);
                break;
            case '2':
                wyszukajKontaktpoImieniu(adresaci);
                break;
            case '3':
                wyszukajKontaktpoNazwisku(adresaci);
                break;
            case '4':
                wyswietlKontakty(adresaci,idZalogowanegoUzytkownika);
                break;
            case '5':
                liczbaZapisanychAdresow=usunKontakt(adresaci);
                break;
            case '6':
                edytujKontakt(adresaci);
                break;
            case '7':
                usersInterface.passwordChange();
                break;
            case '8':
                idZalogowanegoUzytkownika=0;
                break;
            case '9':
                cout<<"Do zobaczenia!"<<endl;
                exit(0);
                break;
            }
        }
    }
    return 0;
}


