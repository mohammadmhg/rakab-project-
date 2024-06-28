#include "Menu.h"
#include <iostream>
#include <conio.h>
using namespace std;
    void Menus::start_menu()
    {
        system("cls");
        cout <<endl << " Welcome to rakab Game!!"<<endl << endl<< "*********************" << endl<<endl;
        cout << "  1-Start the game" << endl << "  2-Menu of opsions" << endl << "  3-Exit" << endl<<endl;
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
        cout << "Welcome to rakab game,Here is information of the rules: "<<endl;
        cout << "There are tow type of card in the game: Yellow(Soldier) and Purple(Spacial):" << endl <<endl;
        cout <<"\t*****************" << endl<<endl;
        cout << "Yellow card: this cards are the soldeir that we use to attack a city to win the war"<<endl << "there are 58 Yellow card in this game that numbered from 1 to 10" << endl;
        cout<<"\t-------------------------"<<endl;
        cout << "When a player has more soldier in the battle,he take over the city and if he take 3 adjacent city or 5 other city,he"<<endl;
        cout <<"wins the game!!" << endl<<endl;
        cout <<"\t*****************" << endl<< endl;
        cout << "Purple cards: there are 52 spacial card in the game that can effect in the result of battle: " << endl;
        cout<<"\t-------------------------"<<endl;
        cout << "Matarsak:if some player want to return his Yellow played card,he can use Matarsak card, but this card only effects"<<endl;
        cout <<"on Yellow cards!"<<endl;
        cout<<"\t-------------------------"<<endl;
        cout << "Tabl_zan:if a player use this card in battle,his army strength will boost double!!(but after using this card once,the"<<endl;
        cout <<"army s strength will not increase one more!!)"<<endl;
        cout<<"\t-------------------------"<<endl;
        cout << "Shah_dokht:this card increase the army power 10 more (no other cards can effect this card,Even Zemesta!!)"<<endl;
        cout<<"\t-------------------------"<<endl;
        cout << "Bahar:After playing this card,the army of players or player that played the highest Yellow card(cards) will increase 3" << endl;
        cout << "more to each card.Remmember that even after battle ends in a city,the Bahar card will remains until Zemestan!!"<< endl;
        cout <<"(the Shah_dokht card dosent count!)"<<endl;
        cout<<"\t-------------------------"<<endl;
        cout<< "Zemestan:If a player played this,All the Yellow cards value will be 1!!(This card do not impact the Purple cards)"<<endl<<endl;
        cout <<"\t*****************" << endl;
        cout << "Press x or X to Exit: "<<endl;
        exit();
    }

    void Menus::bahar_help()
    {
        system("cls");
        cout << "Bahar:After playing this card,the army of players or player that played the highest Yellow card(cards) will increase 3" << endl;
        cout << "more to each card.Remmember that even after battle ends in a city,the Bahar card will remains until Zemestan!!"<< endl;
        cout << "Press x or X to Exit: "<<endl;
        exit();
    }

    void Menus::zemestan_help()
    {
        system("cls");
        cout<< "Zemestan:If a player played this,All the Yellow cards value will be 1!!(This card do not impact the Purple cards)"<<endl<<endl;
        cout << "Press x or X to Exit: "<<endl;
        exit();
    }

    void Menus::tabl_zan_help()
    {
        system("cls");
        cout << "Tabl_zan:if a player use this card in battle,his army strength will boost double!!(but after using this card once,the"<<endl;
        cout <<"army s strength will not increase one more!!)"<<endl;
        cout << "Press x or X to Exit: "<<endl;
        exit();
    }

    void Menus::shah_dokht_help()
    {
        system("cls");
        cout << "Shir_dokht:this card increase the army power 10 more (no other cards can effect this card,Even Zemesta!!)"<<endl;
        cout << "Press x or X to Exit: "<<endl;
        exit();
    }

    void Menus::matarsak_help()
    {
        system("cls");
        cout << "Matarsak:if some player want to return his Yellow played card,he can use Matarsak card, but this card only effects"<<endl;
        cout <<"on Yellow cards!"<<endl;
        cout << "Press x or X to Exit: "<<endl;
        exit();
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
            while(number > 3 || number < 1){
                cin >> number;
            }
            if(number == 1){
                return true;
            }
            if(number == 2){
                menu_of_opsions();
            }
            if(number == 3){
                return false;
            }

        }
        return true;

    }
    void Menus::exit()
    {
        char user = getch();
        while(user != 'x' && user != 'X'){
            cout <<"Unknown input!!!try again"<<endl;
            char user = getch();
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
