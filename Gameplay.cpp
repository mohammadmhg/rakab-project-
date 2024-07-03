#include <iostream>
#include <vector>
#include <string>
#include "Gameplay.h"
#include "Player.h"
#include "Menu.h"

using namespace std;



    ///constructor
    Gameplay::Gameplay(){}
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
