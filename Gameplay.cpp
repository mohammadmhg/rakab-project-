#include <iostream>
#include <vector>
#include <string>
#include "Gameplay.h"
#include "Player.h"
#include "Menu.h"

using namespace std;



    ///constructor
    Gameplay::Gameplay()
    {
        play_cards.resize(10);
        cards.resize(10);
    }
    Gameplay::Gameplay(string card,string played_card)
    {
        Gameplay::set_cards(card);
        Gameplay::set_played_card(played_card);

    }
    ///setter

    void Gameplay::set_help(bool help)
    {
        this->getting_help = help;
    }

    void Gameplay::set_first_attacker(int number)
    {
        this->first_attacker = number;
    }

    void Gameplay::set_cards(string card)
    {
        cards.push_back(card);
    }

    void Gameplay::set_played_card(string card)
    {//setting the paled card and check the season
        play_cards.push_back(card);
        if(card == "bahar"){
            is_bahar = true;
            is_zemestan = false;
        }
        if(card == "zemestan"){
            is_bahar = false;
            is_zemestan = true;
        }
        if(card == "matarsak"){

        }
    }

    void Gameplay::set_pass_counted(bool pass)
    {
        this->pass_counted = pass;
    }

    void Gameplay::set_seasons()
    {//re_setting the bahar and zemestan
        is_bahar = false;
        is_zemestan = false;
    }

    void Gameplay::set_passed_players()
    {
        this->passed_players = passed_players + 1;
    }

    void Gameplay::re_set_passed_players()
    {
        this->passed_players = 0;
    }

    ///getter
    int Gameplay::get_passed_players() const
    {
        return passed_players;
    }

    bool Gameplay::get_help() const
    {
        return getting_help;
    }

    int Gameplay::get_first_attacker() const
    {
        return first_attacker;
    }

    bool Gameplay::get_pass_counted() const
    {
        return pass_counted;
    }

    bool Gameplay::get_bahar() const
    {
        return is_bahar;
    }

    bool Gameplay::get_zemestan() const
    {
        return is_zemestan;
    }

    int Gameplay::get_play_cards() const
    {
        return play_cards.size();
    }

    string Gameplay::get_play_cards_data(int &i) const
    {
        return play_cards[i];
    }

    bool Gameplay::get_pass() const
    {
        return pass;
    }


    void Gameplay::show_cards_array() const
    {//showing the unplaed cards
        for(int i = 0 ; i < cards.size(); i++)
        {
            cout << cards[i] << '\t';
        }
    }

    ///method

    void Gameplay::print_cards()
    {//print the cards for each player
        system("cls");
        cout <<"We want to show the Player"<<i+1<<" Card(press any key): "<<endl;
        getch();
        cout << "Name: " << Player_ID.Getname() << "\tage: " << Player_ID.Getage() <<"\tColor : " << Player_ID.Getcolor() <<"\tCards: " <<endl;
        Show_Array();
        getch();
        cout << endl<<endl;
    }

    void Gameplay::show_saturation()
    {//print the available cards for player and taking his input
        cout <<endl<< "Player Turn : " << Player_ID.Getname()<<endl;
        if(Pass){
            cout << "\t Player has Passed the round!!"<<endl;
            getch();
            return;
        }
        cout << "The player available Cards are : " << endl<<endl;
        Gameplay::Show_Array();
        cout << endl<<endl<<"Please Enter the value of The Card That you want to play(Enter 0 or say pass if You want to Pass): " <<endl;
        string temp;
        getline(cin,temp);
        while(Check_Exist_Card(temp)==true&&temp!="help"&&temp!="pass"&&temp!="matarsak"&&temp!="shir_dokht"&&temp!="bahar"&&temp!="zemestan"&&temp!="tabl_zan"
              &&temp!="help bahar"&&temp!="help matarsak"&&temp!="help shir_dokht"&&temp!="help zemestan"&&temp!="help tabl_zan"&&temp!="0"){
            Non_Existed_Card();
            getline(cin,temp);
        }
        if(temp == "pass"|| temp == "0"){
            Pass = true;
            return;
        }
        if(temp == "help"){
            Sethelp(true);
            Menu_of_opsions();
            return;
        }
        if(temp=="help bahar"||temp=="help matarsak"||temp=="help shir_dokht"||temp=="help zemestan"||temp=="help tabl_zan"){
            Sethelp(true);
            Cards_helping_Menus(temp);
            return;
        }

        Gameplay::CinChosen_Card(temp);
        cout << "The Played Card is : " << Cards[Getchosen_card() - 1]<<endl;
        getch();
        Played_Card(Cards[Gameplay::Getchosen_card() - 1]);
        Cards[Getchosen_card() - 1] = "Empty";
    }

    void Gameplay::matarsak()
    {//handle the matarsak card(matarsak card only impact during the game and after the round ends is useless so we handle it here)
        cout << "You select matarsak! Your Played cards are: "<<endl;
        for(int i =0 ;i < play_cards.size() ; i++)
        {
            cout << play_cards[i] << '\t';
        }

        cout<<endl << "Please Enter the Value of The soldier Card you Want to Put Back:(only inter Value of card if there is no soldier card Enter 0)"<<endl;
        string temp;
        cin>> temp;

        while(temp != "0"&&temp != "1"&&temp !="2"&&temp != "3"&&temp != "4"&&temp != "5"&&temp != "6"&&temp != "7"&&temp != "8"&&temp != "9"&&temp != "10")
        {
            cout <<"ONLY SOLDIERS PLEASE!!"<<endl;
            cin>> temp;
        }

        if(temp == "0")
        {
            return;
        }

        if(temp != "0" && Play_cards.size() == 1){
            cout << "PLAY 0 IF THERE IS NO CARD PLEASE!!"<<endl;
            getch();
            return;
        }

        while(stoi(temp) < 1 || stoi(temp) > 10)
        {
            cout <<"Error!!you Entered The wrong Value!!"<< endl;
            cin>> temp;
        }

        for(int i =0 ;i < play_cards.size() ; i++)
        {
            if(play_cards[i] == temp)
            {
                play_cards[i] = "Empty";
                Gameplay::set_cards(temp);
                break;
            }
        }
    }

    void Gameplay::cards_helping_menus(string &temp)
    {//check the input to show help menu
        if(temp == "help bahar"){
            menu.bahar_help();
            return;
        }
        if(temp=="help matarsak"){
            menu.matarsak_help();
            return;
        }
        if(temp == "help zemestan"){
            menu.zemestan_help();
            return;
        }
        if(temp == "help tabl_zan"){
            menu.tabl_zan_help();
            return;
        }
        if(temp == "help shir_dokht"){
            menu.shir_dokht_help();
            return;
        }

    }

    void Gameplay::cinchosen_card(string temp)
    {//setting the index of chosen card by player
        for(int i =0 ; i < cards.size();i++)
        {
            if(cards[i] == temp){
                chosen_card = i+1;
                break;
            }
        }
    }

    int Gameplay::Getchosen_card()
    {
        return Chosen_card;
    }

    bool Gameplay::Check_Exist_Card(string Chosen)
    {//check that input from player is correct
        for(int i = 0 ; i < cards.size() ; i++)
        {
            if(chosen == Cards[i] && chosen != "Empty")
            {
                return false;
            }
        }
        return true;
    }

