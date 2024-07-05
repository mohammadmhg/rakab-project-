#include <iostream>
#include <string>
#include <vector>
#include "Control_card.h"





using namespace std;

    ///constructor
    Control_Cards::Control_Cards(){}
    Control_Cards::Control_Cards(int temp_power,bool temp_winner)
    {
        Control_Cards::set_winner(temp_winner);
        Control_Cards::set_power(temp_power);
    }
    ///setter
    void Control_Cards::set_biggest_card_played()
    {
        biggest_played_card = 0;
    }
    void Control_Cards::set_power(int number)
    {
        this->power += number;
    }

    void Control_Cards::set_winner(bool flag)
    {
        this->winner = flag;
    }

    void Control_Cards::set_most_powerful(int number)
    {
        this->most_powerful = number;
    }

    void Control_Cards::re_set_most_powerful()
    {
        most_powerful = 0;
    }

    ///getter

    int Control_Cards::get_power()
    {
        return power;
    }

    int Control_Cards::get_most_powerful()
    {
        return most_powerful;
    }

    bool Control_Cards::get_winner()
    {
        return winner;
    }

    int Control_Cards::get_biggest_card()
    {
        return biggest_played_card;
    }



