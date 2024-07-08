#include "Rish_sefid.h"
#include <string>
#include <iostream>

using namespace std;

int Rish_Sefid::last_played_card_index = 0;
bool Rish_Sefid::rish_sefid_card = false;

    ///constructor

    Rish_Sefid::Rish_Sefid(){}

    ///getter

    int Rish_Sefid::get_last_played_card_index()
    {
        return last_played_card_index;
    }

    bool Rish_Sefid::get_rish_sefid_card()
    {
        return rish_sefid_card;
    }


