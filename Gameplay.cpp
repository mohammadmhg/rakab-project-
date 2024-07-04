#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <conio.h>
#include "Gameplay.h"
#include "Player.h"
#include "Menu.h"

using namespace std;



    ///constructor
    Gameplay::Gameplay()
    {
        play_cards.resize(10);
        cards.resize(10);
        is_bahar = false;
        is_zemestan = false;
        first_attacker = 0;
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
            Gameplay::matarsak();
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
    {
        for(int i = 0 ; i < cards.size(); i++)
        {
            cout << cards[i] << '\t';
        }
    }

    ///method
    void Gameplay::setting_card(const Card card_setter,const int conquer_cities_number)
    {
        if(index_purple_card > 20)
        {
            index_purple_card = 0;
        }
        if(index_yellow_card > 47)
        {
            index_yellow_card = 0;
        }
        int Random = rand() % 5;
        for(int i = 0 ; i < 10 + conquer_cities_number ;i++)
        {
            if(Random % 2 == 0)
            {
                cards.push_back(card_setter.get_purple_card(index_purple_card) );
                index_purple_card++;
            }
            else
            {
                int temp_yellow_card = card_setter.get_yellow_card(index_yellow_card);
                string temp_string = to_string(temp_yellow_card);
                cards.push_back( temp_string );
                index_yellow_card++;
            }
        }

    }

    void Gameplay::print_cards(const int index,const Players play)
    {//print the cards for each player
        system("cls");
        cout <<"We want to show the Player"<<index+1<<" Card(press any key): "<<endl;
        getch();
        cout << "Name: " << play.get_name(index) << "\tage: " << play.get_age(index) <<"\tColor : " << play.get_color(index) <<"\tCards: " <<endl;
        Gameplay::show_cards_array();
        getch();
        cout << endl<<endl;

    }

    void Gameplay::show_saturation(int number)
    {//print the available cards for player and taking his input
        cout <<endl<< "Player Turn Player: " << number +1 <<endl;
        if(pass){
            cout << "\t Player has Passed the round!!"<<endl;
            getch();
            return;
        }
        cout << "The player available Cards are : " << endl<<endl;
        Gameplay::show_cards_array();
        cout << endl<<endl<<"Please Enter the value of The Card That you want to play(Enter 0 or say pass if You want to Pass): " <<endl;
        string input;
        getline(cin,input);
        while(check_exist_card(input)==true&&input!="help"&&input!="pass"&&input!="matarsak"&&input!="shir_dokht"&&input!="bahar"&&input!="zemestan"&&input!="tabl_zan"
              &&input!="help bahar"&&input!="help matarsak"&&input!="help shir_dokht"&&input!="help zemestan"&&input!="help tabl_zan"&&input!="0")
        {
            menu.non_existed_card();
            getline(cin,input);
        }
        if(input == "pass"|| input == "0")
        {
            pass = true;
            return;
        }
        if(input == "help")
        {
            set_help(true);
            menu.menu_of_opsions();
            return;
        }
        if(input=="help bahar"||input=="help matarsak"||input=="help shir_dokht"||input=="help zemestan"||input=="help tabl_zan")
        {
            set_help(true);
            cards_helping_menus(input);
            return;
        }

        Gameplay::input_chosen_card(input);
        cout << "The Played Card is : " << cards[get_chosen_card() - 1]<<endl;
        getch();
        set_played_card(cards[Gameplay::get_chosen_card() - 1]);
        cards[Gameplay::get_chosen_card() - 1] = "Empty";
    }

    void Gameplay::matarsak()
    {//handle the matarsak card(matarsak card only impact during the game and after the round ends is useless so we handle it here)
        cout << "You select matarsak! Your Played cards are: "<<endl;
        for(int i =0 ;i < play_cards.size() ; i++)
        {
            cout << play_cards[i] << '\t';
        }

        cout<<endl << "Please Enter the Value of The soldier Card you Want to Put Back:(only inter Value of card if there is no soldier card Enter 0)"<<endl;
        string input;
        cin>> input;

        while(input != "0"&&input != "1"&&input !="2"&&input != "3"&&input != "4"&&input != "5"&&input != "6"&&input != "7"&&input != "8"&&input != "9"&&input != "10")
        {
            cout <<"ONLY SOLDIERS PLEASE!!"<<endl;
            cin>> input;
        }

        if(input == "0")
        {
            return;
        }

        if(input != "0" && play_cards.size() == 1){
            cout << "PLAY 0 IF THERE IS NO CARD PLEASE!!"<<endl;
            getch();
            return;
        }

        while(stoi(input) < 1 || stoi(input) > 10)
        {
            cout <<"Error!!you Entered The wrong Value!!"<< endl;
            cin>> input;
        }

        for(int i =0 ;i < play_cards.size() ; i++)
        {
            if(play_cards[i] == input)
            {
                play_cards[i] = "Empty";
                Gameplay::set_cards(input);
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

    void Gameplay::input_chosen_card(string temp)
    {//setting the index of chosen card by player
        for(int i =0 ; i < cards.size();i++)
        {
            if(cards[i] == temp){
                chosen_card = i+1;
                break;
            }
        }
    }

    int Gameplay::get_chosen_card()
    {
        return chosen_card;
    }

    bool Gameplay::check_exist_card(string chosen)
    {//check that input from player is correct
        for(int i = 0 ; i < cards.size() ; i++)
        {
            if(chosen == cards[i] && chosen != "Empty")
            {
                return false;
            }
        }
        return true;
    }

