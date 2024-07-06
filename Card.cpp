#include <iostream>
#include <string>

#include <ctime>
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
        Card::define_yellow_cards(10,1);//set soldier with 1 power
        Card::define_yellow_cards(8,2);//set soldier with 2 power
        Card::define_yellow_cards(8,3);//set soldier with 3 power
        Card::define_yellow_cards(8,4);//set soldier with 4 power
        Card::define_yellow_cards(8,5);//set soldier with 5 power
        Card::define_yellow_cards(8,6);//set soldier with 6 power
        Card::define_yellow_cards(8,10);//set soldier with 10 power
        Card::shuffle_yellow_cards();


    }
    void Card::set_purple_card()
    {
        purple_cards.resize(52);
        Card::define_purple_cards(16,"matarsak");//set matarsak
        Card::define_purple_cards(3,"bahar");//set bahar
        Card::define_purple_cards(3,"zemestan");//set zemestan
        Card::define_purple_cards(3,"shir_dokht");//set shir_dokht
        Card::define_purple_cards(6,"tabl_zan");//set shir_dokht
        Card::shuffle_purple_cards();


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

    void Card::shuffle_purple_cards()
    {

        int Shuff = rand() % 4 + 1;
        for(int i = 0; i < 30 ;i++)
        {
            swap(purple_cards[i],purple_cards[Shuff]);
        }

    }
    void Card::shuffle_yellow_cards()
    {

        int Shuff = rand() % 4 + 1;
        for(int i = 0; i < 50 ;i++)
        {
            swap(yellow_cards[i],yellow_cards[Shuff]);
        }

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

        for(int i = 0; i < index ;i++)
        {
            yellow_cards.push_back(number);
        }

    }

