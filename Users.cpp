#include <iostream>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <vector>
#include "Users.h"

using namespace std;

UsersInterface::UsersInterface() {

}

void UsersInterface::loadUsersFile() {
    nrLine=0;
    string loadedData;
    file.open("Uzytkownicy.txt",ios::in);

    while(getline(file,line)) {
        if(line=="")
            continue;
        stringstream lineSS (line);
        while(getline(lineSS,loadedData,'|')) {
            switch(nrLine) {
            case 0:
                userTemplate.userID=stoi(loadedData);
                break;
            case 1:
                userTemplate.name = loadedData;
                break;
            case 2:
                userTemplate.password = loadedData;
                break;
            }
            nrLine++;
        }
        nrLine=0;
        users.push_back(userTemplate);
    }
    file.close();
}

void UsersInterface::registration() {
    system ("cls");
    i=0;
    cout<<"Podaj nazwe uzytkownika ktora chcesz zarejestrowac: "<<endl;
    cin>>name;
    while(i<users.size()) {
        if(users[i].name==name) {
            cout<<"Podany login jest juz zajety. Podaj inna nazwe uzykownika: "<<endl;
            cin>>name;
        } else {
            i++;
        }
    }
    cout<<"Podaj haslo: "<<endl;
    cin>>password;
    if(users.size()==0) {
        userTemplate.userID=1;
    }
    //UWAGA TU BYL WARUNEK ELSE, JAKBY COS NIE DZIALALO Z IDUSERA
    userTemplate.userID=users.size()+1;
    userTemplate.name=name;
    userTemplate.password=password;
    users.push_back(userTemplate);
    file.open("Uzytkownicy.txt",ios::out|ios::app);
    if(file.good()) {
        file<<userTemplate.userID<<"|"<<name<<"|"<<password<<"|"<<endl;
    } else {
        cout<<"Nie istnieje plik Uzytkownicy.txt"<<endl;
    }
    file.close();
}

int UsersInterface::login() {
    int i=0;
    system ("cls");
    cout<<"Podaj login:";
    cin>>name;
    while(i<users.size()) {
        if(name==users[i].name) {
            cout<<"Wprowadz haslo:";
            cin>>password;
            if(users[i].password==password) {
                cout<<"Zalogowano!"<<endl;
                Sleep(1000);
                return users[i].userID;
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

void UsersInterface::passwordChange() {
    system ("cls");
    cout<<"Podaj nowe haslo: ";
    cin>>password;
    for(int i=0; i<users.size(); i++) {
        if(users[i].userID==loggedUserId) {
            users[i].password=password;
            file.open("Uzytkownicy.txt",ios::out);
            for(int i=0; i<users.size(); i++) {
                file<<users[i].userID<<"|";
                file<<users[i].name<<"|";
                file<<users[i].password<<"|"<<endl;
            }
            file.close();
            cout<<"Haslo zostalo zmienione"<<endl;
            Sleep(1500);
        }
    }
}

