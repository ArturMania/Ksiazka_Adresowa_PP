#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class UsersInterface {
private:
    struct User {
        int userID=0;
        string name="",password="";
    };
    string name,password,line;
    User userTemplate;
    int i=0;
    int nrLine=1;
    fstream file;
public:
    vector<User> users;
    int loggedUserId=0;

    UsersInterface();
    int login();
    void registration();
    void passwordChange();
    void loadUsersFile();
};
