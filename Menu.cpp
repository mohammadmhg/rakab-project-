#include "Menu.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
using namespace std;

    void Menus::set_loading_game(bool upload)
    {
        upload_game = upload;
    }

    bool Menus::get_loading_game()const
    {
        return upload_game;
    }

    void Menus::start_menu()
    {
        system("cls");
        cout <<endl << " Welcome to rakab Game!!"<<endl << endl<< "*********************" << endl<<endl;
        cout << "  1-Start the game" << endl << "  2-Menu of opsions" << endl << "  3-Exit" << endl << "  4-Load last game" << endl<<endl;
        cout << "*********************"<<endl;
    }

    void Menus::start_war(int number)
    {
        system("cls");
        cout << "The Player"<<number <<" have The War_sign!"<< endl;
        cout << "Please Enter the name of an empty city you want to Attack: "<< endl;
    }

    void Menus::menu_of_opsions()
    {// print the options and explain the game
        system("cls");
        HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(a,6);
        fstream in;
        in.open("menu.txt",ios::in);
        string line;
        while ( getline(in,line) )
        {
            cout << line <<endl;
        }
        SetConsoleTextAttribute(a,7);
        Menus::exit();
    }

    void Menus::bahar_help()
    {
        system("cls");
        fstream in;
        in.open("menu.txt",ios::in);
        string line;
        while ( getline(in,line) )
        {
            if (line == "Bahar")
            {
                while ( getline(in,line) )
                {
                    if (line == "&&")
                    {
                        break;
                    }
                    cout << line << endl;

                }

            }

        }
        Menus::exit();
    }

    void Menus::zemestan_help()
    {
        system("cls");
        fstream in;
        in.open("menu.txt",ios::in);
        string line;
        while ( getline(in,line) )
        {
            if (line == "Zemestan")
            {
                while ( getline(in,line) )
                {
                    if (line == "&&")
                    {
                        break;
                    }
                    cout << line << endl;

                }

            }

        }
        Menus::exit();
    }

    void Menus::tabl_zan_help()
    {
        system("cls");
        fstream in;
        in.open("menu.txt",ios::in);
        string line;
        while ( getline(in,line) )
        {
            if (line == "Tabl_zan")
            {
                while ( getline(in,line) )
                {
                    if (line == "&&")
                    {
                        break;
                    }
                    cout << line << endl;

                }

            }

        }
        Menus::exit();
    }

    void Menus::shir_dokht_help()
    {
        system("cls");
        fstream in;
        in.open("menu.txt",ios::in);
        string line;
        while ( getline(in,line) )
        {
            if (line == "Shir_dokht")
            {
                while ( getline(in,line) )
                {
                    if (line == "&&")
                    {
                        break;
                    }
                    cout << line << endl;

                }

            }

        }
        Menus::exit();
    }

    void Menus::matarsak_help()
    {
        system("cls");
        fstream in;
        in.open("menu.txt",ios::in);
        string line;
        while ( getline(in,line) )
        {
            if (line == "Matarsak")
            {
                while ( getline(in,line) )
                {
                    if (line == "&&")
                    {
                        break;
                    }
                    cout << line << endl;

                }

            }

        }
        Menus::exit();
    }

    void Menus::rish_sefid_help()
    {
        system("cls");
        fstream in;
        in.open("menu.txt",ios::in);
        string line;
        while ( getline(in,line) )
        {
            if (line == "Rish_sefid")
            {
                while ( getline(in,line) )
                {
                    if (line == "&&")
                    {
                        break;
                    }
                    cout << line << endl;

                }

            }

        }
        Menus::exit();
    }

    void Menus::parcham_dar_help()
    {
        system("cls");
        fstream in;
        in.open("menu.txt",ios::in);
        string line;
        while ( getline(in,line) )
        {
            if (line == "Parcham_dar")
            {
                while ( getline(in,line) )
                {
                    if (line == "&&")
                    {
                        break;
                    }
                    cout << line << endl;

                }

            }

        }
        Menus::exit();
    }

    void Menus::shir_zan_help()
    {
        system("cls");
        fstream in;
        in.open("menu.txt",ios::in);
        string line;
        while ( getline(in,line) )
        {
            if (line == "Shir_zan")
            {
                while ( getline(in,line) )
                {
                    if (line == "&&")
                    {
                        break;
                    }
                    cout << line << endl;

                }

            }

        }
        Menus::exit();
    }

    void Menus::non_existed_card()
    {
        cout << "ENTER THE CRAD PLEASE: "<<endl;
    }

    bool Menus::action()
    {//to handle the user selected number to enter the game or enter the menu or exit
        bool flag = true;
        while(flag){
            start_menu();
            int number;
            cin >> number;
            while(number > 4 || number < 1)
            {
                cin >> number;
            }
            if(number == 1)
            {
                return true;
            }
            if(number == 2)
            {
                menu_of_opsions();
            }
            if(number == 3)
            {
                return false;
            }
            if(number == 4)
            {
                upload_game = true;
                return true;
            }

        }
        return true;

    }
    void Menus::exit()
    {
        cout << "Press x or X to Exit:"<<endl;
        char user = getch();
        while(user != 'x' && user != 'X')
        {
            cout <<"Unknown input!!!try again"<<endl;
            user = getch();
        }
        system("cls");
    }

    void Menus::ending()
    {
        system("cls");
        cout << "\tYou Exited the Game!!";
    }

    void Menus::enter_players()
    {
        system("cls");
        cout << "Enter the number of players you want to play with:(must be between 3 to 6): "<<endl;
    }

    void Menus::enter_details()
    {
        system("cls");
        cout << "Enter the name and age and color of each person in the Game please: "<<endl;
    }
