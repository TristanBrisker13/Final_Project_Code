#ifndef LOGIN_REGISTRATION_PROJECT_SYSTEM_H
#define LOGIN_REGISTRATION_PROJECT_SYSTEM_H
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
using namespace std;

class system{
private:
    string username, username2, username3, password, password2, password3,useless;
public:
    int choice;
    int result;
    bool cin_fail;
    int confirmation[];

    void write_to_file(string username)
    {
        ofstream writefile;
        string file = username+".txt";
        writefile.open(file.c_str());
        writefile << password;
        writefile.close();
        main_menu();
    }

    void login()
    {
        cout << "PLease enter your username:" << endl;
        cout <<"Username:";
        cin >> username2;

        fstream ReadFile;
        ReadFile.open(username2+".txt");

        if(ReadFile)
        {
            ReadFile.close();
            CheckPassword2();
        }

        else
        {
            cout << "\nThere are no accounts with that username" << endl;
            cout << "Please try logging in again from the beginning\n" << endl;
            main_menu();
        }
    }

    void register_password()
    {
        cout << "Please enter the password:" << endl;
        cin >> password;
        cout << "Please renter your password:" << endl;
        cin >> password2;


        if (password == password2)
        {
            cout << "Your account has been successfully created!\n" << endl;
            cin.clear();
            cin.ignore(10000,'\n');
            write_to_file(username);
            std::exit(1);
        }

        else;
        {
            cout << "Sorry invalid" << endl;
            register_password();
        }
    }
    void register_me()
    {
        cout << "Please enter in the username you would like to use: " << endl;
        cin >> username;

        fstream ReadFile;
        ReadFile.open(username+".txt");

        if(ReadFile)
        {
            ReadFile.close();
            cout << "Select a different username as this one is already taken\n" << endl;
            register_me();
        }
        else
        {
            ReadFile.close();
            cout << "\nUsername - \""<< username << "\"\nConfirm? \n\n[1] Yes\n[2] No" << endl;
            cin >> confirmation[0];

            if (confirmation[0] == 1)
            {
                register_password();
            }

            else if(confirmation[0] == 2)
            {
                cout << "No problem. We will erase the username\n" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                register_me();
            }
        }
    }

    void exit()
    {
        std::exit(0);
    }

    void CheckPassword()
    {
        string pass,pass2;
        fstream ReadFile2;
        ReadFile2.open(username3+".txt",ios::in);
        cout << "Password (Case sensitive):";
        cin >> pass;
        while(getline(ReadFile2, pass2)) //read a line of text from file into our line variable
        {
            if (pass == pass2) //if we find our text in line
            {
                cout << "\nAre you sure you want to delete this account (This is permanent and cannot be undone!)\n[1] Yes\n[2] No\n";
                cin >> result;
                if (result == 1)
                {
                    ReadFile2.close();
                    break; //no need to read the other lines
                }
                if (result == 2)
                {
                    ReadFile2.close();
                    cout << "Ok we will cancel this process for you!" << endl;
                    cout << "Your account has not been deleted\n" << endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                    main_menu();
                }
            }
            else if (pass != pass2)
            {
                ReadFile2.close();
                cout << "This is the incorrect password" << endl;
                cout << "Please enter in the correct password\n" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                main_menu();
            }
        }
    }

    void CheckPassword2()
    {
        string pass,pass2;
        fstream ReadFile2;
        ReadFile2.open(username2+".txt",ios::in);
        cout << "Password (Case sensitive):";
        cin >> pass;
        while(getline(ReadFile2, pass2)) //read a line of text from file into our line variable
        {
            if (pass == pass2) //if we find our text in line
            {
                cout << "You have been successfully logged in!" << endl;
                cout << "\n";
                cout << "Welcome " << username2 << "!";
                std::exit(1);
            }
            else if (pass != pass2)
            {
                ReadFile2.close();
                cout << "This is the incorrect password" << endl;
                cout << "Please enter in the correct password\n" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                main_menu();
            }
        }
    }
    void Delete()
    {
        cout << "\nIn order to delete your account, we will need the username and password" << endl;
        cout << "Username:";
        cin >> username3;

        fstream ReadFile;
        ReadFile.open(username3+".txt");

        if(ReadFile)
        {
            ReadFile.close();
            CheckPassword();
            std::filesystem::remove(username3+".txt");
            cout << "Your account has been successfully deleted!\n" << endl;
            main_menu();
        }

        else
        {
            cout << "\nThere are no accounts with that username" << endl;
            cout << "Please try again from the beginning\n" << endl;
            main_menu();
        }

    }

    void main_menu()
    {
        cout << "Would you like to log in, register, or delete an account?\n[1] Login\n[2] Register\n[3] Delete Account\n[4] Exit" << endl;
        cin >> choice;
        do{
            cin_fail = cin.fail();
            cin.clear();
            cin.ignore(10000,'\n');
        }while(cin_fail);
        {
            switch(choice)
            {
                case 1:
                    login();
                    break;
                case 2:
                    register_me();
                    break;
                case 3:
                    Delete();
                case 4:
                    exit();
                default:
                    cout << "This is not a valid choice\n" << endl;
                    main_menu();
            }
        }
    }
};
#endif //LOGIN_REGISTRATION_PROJECT_SYSTEM_H
