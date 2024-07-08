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

    ///getter

    int Rish_Sefid::get_last_played_card_index()
    {
        return last_played_card_index;
    }

    bool Rish_Sefid::get_rish_sefid_card()
    {
        return rish_sefid_card;
    }

    ///method

    void Rish_Sefid::setting_rish_sefid(int biggest_played_card,vector <string> &play_cards)
    {
        if( biggest_played_card == 0)
        {
            return;
        }



    }

