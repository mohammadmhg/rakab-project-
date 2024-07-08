#include "Rish_sefid.h"
#include <iostream>

using namespace std;

int Rish_Sefid::last_played_card_index = 0;
bool Rish_Sefid::used_rish_sefid_card = false;
bool Rish_Sefid::rish_sefid_card = false;
int Rish_Sefid::biggest_card_value = 0;

    ///constructor

    Rish_Sefid::Rish_Sefid(){}

    ///setter

    void Rish_Sefid::set_biggest_card_value(int number)
    {
        biggest_card_value = number;
    }


    void Rish_Sefid::set_last_played_card_index(int number)
    {
        last_played_card_index = number;
    }

    void Rish_Sefid::set_rish_sefid_card(bool card)
    {
        rish_sefid_card = card;
    }

    void Rish_Sefid::set_used_rish_sefid_card(bool card)
    {
        used_rish_sefid_card = card;
    }


    ///getter

    int Rish_Sefid::get_last_played_card_index()
    {
        return last_played_card_index;
    }

    bool Rish_Sefid::get_used_rish_sefid_card()
    {
        return used_rish_sefid_card;
    }

    bool Rish_Sefid::get_rish_sefid_card()
    {
        return rish_sefid_card;
    }


    int Rish_Sefid::get_biggest_card_value()
    {
        return biggest_card_value;
    }

