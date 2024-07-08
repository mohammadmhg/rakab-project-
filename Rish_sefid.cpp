#include "Rish_sefid.h"
#include <iostream>

using namespace std;

int Rish_Sefid::last_played_card_index = 0;
bool Rish_Sefid::rish_sefid_card = false;
int Rish_Sefid::number_of_players = 0;
int Rish_Sefid::biggest_card_value = 0;

    ///constructor

    Rish_Sefid::Rish_Sefid(){}

    ///setter

    void Rish_Sefid::set_biggest_card_value(int number)
    {
        biggest_card_value = number;
    }

    void Rish_Sefid::set_number_of_players(int number)
    {
        number_of_players = number;
    }

    void Rish_Sefid::set_last_played_card_index(int number)
    {
        last_played_card_index = number;
    }

    void Rish_Sefid::set_rish_sefid_card(bool card)
    {
        rish_sefid_card = card;
    }

    ///getter

    int Rish_Sefid::get_last_played_card_index()
    {
        return last_played_card_index;
    }

    bool Rish_Sefid::get_rish_sefid_card()
    {
        return rish_sefid_card;
    }

    int Rish_Sefid::get_number_of_players()
    {
        return number_of_players;
    }
    ///method

    void Rish_Sefid::setting_rish_sefid(vector <string> &play_cards)
    {

        for (int i = 0; i < play_cards.size() ;i++)
        {
            if(play_cards[i] == "1"||play_cards[i] == "2"||play_cards[i] == "3"||play_cards[i] == "4"||play_cards[i] == "5"||play_cards[i] == "6"||play_cards[i] == "7"||
               play_cards[i] == "8"||play_cards[i] == "9"||play_cards[i] == "10" )
            {
                if( stoi(play_cards[i]) == biggest_card_value )
                {
                    play_cards[i] = "Empty";
                }
            }
        }
        number_of_players++;

    }

