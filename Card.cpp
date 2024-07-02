#include <iostream>
#include <string>
#include <vector>
#include "Card.h"

using namespace std;

    Card::Card()
    {
        Card::set_yellow_card();
        Card::set_purple_card();
    }
    Card::Card(string name,int number)
    {
        yellow_cards.push_back(number);
        purple_cards.push_back(name);
    }
    ///setter

    void Card::set_yellow_card()
    {
        yellow_cards.resize(58);

    }
    void Card::set_purple_card()
    {
        purple_cards.resize(52);
        Card::define_purple_cards(16,"matarsak");//set matarsak
    }
    ///getter

    int Card::get_yellow_card(int index) const
    {
        return yellow_cards[index];
    }
    string Card::get_purple_card(int index) const
    {
        return purple_cards[index];
    }
    ///method

    void Card::shuffle_cards()
    {

    }

    void Card::define_purple_cards(int index,string data)
    {
        for(int i = 0; i < index ;i++)
        {
            purple_cards.push_back(data);
        }

    }

    void Card::define_yellow_cards(int index,int number)
    {

    }

