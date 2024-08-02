#include "Red_card.h"

using namespace std;

int Red_Card::index_red_card = 0;


    Red_Card::Red_Card(){}

    ///setter

    void Red_Card::set_index_red_card()
    {
        index_red_card++;
        if(index_red_card == 8)
        {
            index_red_card = 0;
        }
    }

    void Red_Card::set_used_herkol(bool card)
    {
        used_herkol = card;
    }

    void Red_Card::set_used_kooh_shekan(bool card)
    {
        used_kooh_shekan = card;
    }

    void Red_Card::set_used_rooh_jangal(bool card)
    {
        used_rooh_jangal = card;
    }

    ///getter

    int Red_Card::get_index_red_card() const
    {
        return index_red_card;
    }

    bool Red_Card::get_used_herkol() const
    {
        return used_herkol;
    }

    bool Red_Card::get_used_kooh_shekan() const
    {
        return used_kooh_shekan;
    }

    bool Red_Card::get_used_rooh_jangal() const
    {
        return used_rooh_jangal;
    }




