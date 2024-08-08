#include <iostream>
#include <string>
#include <ctime>

#include "Card.h"

using namespace std;

    Card::Card()
    {
        Card::set_yellow_card();
        Card::set_purple_card();
        Card::set_red_card();
    }

    Card::Card(string name,string number)
    {
        yellow_cards.push_back(number);
        purple_cards.push_back(name);
    }

    ///setter

    void Card::set_yellow_card()
    {
        Card::define_yellow_cards(10,"1");//set soldier with 1 power
        Card::define_yellow_cards(8,"2");//set soldier with 2 power
        Card::define_yellow_cards(8,"3");//set soldier with 3 power
        Card::define_yellow_cards(8,"4");//set soldier with 4 power
        Card::define_yellow_cards(8,"5");//set soldier with 5 power
        Card::define_yellow_cards(8,"6");//set soldier with 6 power
        Card::define_yellow_cards(8,"10");//set soldier with 10 power

        Card::shuffle_yellow_cards();
    }

    void Card::set_purple_card()
    {
        Card::define_purple_cards(16,"matarsak");//set matarsak
        Card::define_purple_cards(3,"bahar");//set bahar
        Card::define_purple_cards(3,"zemestan");//set zemestan
        Card::define_purple_cards(6,"rish_sefid");//set rish_sefid
        Card::define_purple_cards(3,"shir_dokht");//set shir_dokht
        Card::define_purple_cards(2,"rakhsh_sefid");//set rakhsh_sefid
        Card::define_purple_cards(6,"tabl_zan");//set tabl_zan
        Card::define_purple_cards(12,"shir_zan");//set shir_zan
        Card::define_purple_cards(3,"parcham_dar");//set parcham_dar

        Card::shuffle_purple_cards();
    }

    void Card::set_red_card()
    {
        define_red_cards(3,"rooh_jangal");// set rooh_jangal
        define_red_cards(3,"herkol");//set herkol
        define_red_cards(3,"kooh_shekan");//set kooh_shekan

        shuffle_red_cards();
    }

    ///getter

    string Card::get_yellow_card(int index) const
    {
        return yellow_cards[index];
    }

    string Card::get_purple_card(int index) const
    {
        return purple_cards[index];
    }

    string Card::get_red_card(int index) const
    {
        return red_cards[index];
    }
    ///method

    void Card::shuffle_purple_cards()
    {
        srand(time(0));

        for(int i = 0; i < 53 ;i++)
        {
            int Shuff = rand() % 10 + 1;
            if(i == Shuff)
            {
                continue;
            }
            swap(purple_cards[i],purple_cards[Shuff]);
        }
    }

    void Card::shuffle_red_cards()
    {
        for(int i = 0; i < 9 ;i++)
        {
            int Shuff = rand() % 8 + 1;
            if(i == Shuff)
            {
                continue;
            }
            swap(red_cards[i],red_cards[Shuff]);
        }
    }

    void Card::shuffle_yellow_cards()
    {

        for(int i = 0; i < 57 ;i++)
        {
            int Shuff = rand() % 10 + 1;
            if(i == Shuff)
            {
                continue;
            }
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

    void Card::define_red_cards(int index,string name)
    {
        for(int i = 0; i < index ; i++)
        {
            red_cards.push_back(name);
        }
    }

    void Card::define_yellow_cards(int index,string number)
    {
        for(int i = 0; i < index ;i++)
        {
            yellow_cards.push_back(number);
        }
    }

