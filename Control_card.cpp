#include <iostream>
#include <string>
#include <vector>
#include "Control_card.h"




int Control_Cards::biggest_played_card = 0;
int Control_Cards::most_powerful = 0;
int Control_Cards::first_attacker = 0;




using namespace std;

    ///constructor
    Control_Cards::Control_Cards()
    {
        power.resize(3);
    }
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

    void Control_Cards::set_first_attacker(int number)
    {
        this->first_attacker = number;
    }

    void Control_Cards::set_power(int number)
    {
        this->power.push_back(number);
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
        shir_zan_numbers.clear();
        winner = false;
        power.clear();
    }

    ///getter
    int Control_Cards::get_shir_zan_size()const
    {
        return shir_zan_numbers.size();
    }

    int Control_Cards::get_first_attacker() const
    {
        return first_attacker;
    }

    int Control_Cards::get_power(int index) const
    {
        return power[index];
    }

    int Control_Cards::get_most_powerful() const
    {
        return most_powerful;
    }

    bool Control_Cards::get_winner() const
    {
        return winner;
    }

    int Control_Cards::get_biggest_card() const
    {
        return biggest_played_card;
    }

    ///methods

    void Control_Cards::show_power()const
    {
        for(int i = 0 ; i < power.size() ;i++)
        {
            cout << power[i] << '\t';
        }
    }

    void Control_Cards::calculate_yellow_card_power(const Gameplay game,int index_of_player)
    {//set power by yellow cards

        for(int i = 0 ; i < game.get_play_cards() ;i++)
        {

            if (game.get_play_cards_data(i) != "matarsak"&&game.get_play_cards_data(i) != "shir_dokht"&&game.get_play_cards_data(i) != "tabl_zan"&&game.get_play_cards_data(i) != "bahar"&&
               game.get_play_cards_data(i) !="zemestan"&&game.get_play_cards_data(i) != "Empty"&&game.get_play_cards_data(i) != "rish_sefid"&&game.get_play_cards_data(i) != "parcham_dar"&&
              game.get_play_cards_data(i) != "shir_zan")
            {

                string temp_data = game.get_play_cards_data(i);
                power[index_of_player] = power[index_of_player] + stoi(temp_data);

            }
        }
    }


    void Control_Cards::calculate_purple_card_power(const Gameplay game,int index_of_player)
    {//set power by purple cards
        bool tabl_zan = false;
        int temp_shir_dokht = 0;
        int temp_shir_zan = 0;
        for(int i = 0; i < game.get_play_cards() ;i++)
            {

            if(game.get_play_cards_data(i) == "tabl_zan" && tabl_zan == false)
            {
                tabl_zan = true;
                power[index_of_player] = power[index_of_player] * 2;
            }

            if(game.get_play_cards_data(i) == "shir_dokht")
            {
                temp_shir_dokht = temp_shir_dokht + 10;
            }
            if(game.get_play_cards_data(i) == "shir_zan")
            {
                temp_shir_zan++;
            }
        }
        power[index_of_player] = power[index_of_player] + temp_shir_zan;
        power[index_of_player] = power[index_of_player] + temp_shir_dokht;
        shir_zan_numbers.push_back(temp_shir_zan);

    }

    void Control_Cards::set_bahar_power(const Gameplay game,int index_of_player)
    {//set power when is bahar

        for(int i = 0; i < game.get_play_cards() ;i++)
        {
            if(game.get_play_cards_data(i) != "matarsak"&&game.get_play_cards_data(i) != "shir_dokht"&&game.get_play_cards_data(i) != "tabl_zan"&&game.get_play_cards_data(i) != "bahar"
               &&game.get_play_cards_data(i) !="zemestan"&&game.get_play_cards_data(i) != "Empty"&&game.get_play_cards_data(i) != "rish_sefid"&&game.get_play_cards_data(i) != "shir_zan"&&
               game.get_play_cards_data(i) != "parcham_dar")

            {
                string temp_yellow_card;
                temp_yellow_card = game.get_play_cards_data(i);
                if(biggest_played_card <= stoi( temp_yellow_card ) )
                {
                    power[index_of_player] = power[index_of_player] + 3;
                }

            }
        }
    }

    void Control_Cards::set_biggest_card(const Gameplay game)
    {//set the biggest played soldier card in game
        for(int i = 0; i < game.get_play_cards() ;i++)
        {

            if(game.get_play_cards_data(i) != "matarsak"&&game.get_play_cards_data(i) != "shir_dokht"&&game.get_play_cards_data(i) != "tabl_zan"&&game.get_play_cards_data(i) != "bahar"
               &&game.get_play_cards_data(i) !="zemestan"&&game.get_play_cards_data(i) != "Empty"&&game.get_play_cards_data(i) != "rish_sefid"&&game.get_play_cards_data(i) != "shir_zan"&&
               game.get_play_cards_data(i) != "parcham_dar")
            {
                string temp_yellow_card;
                temp_yellow_card = game.get_play_cards_data(i);
                if( stoi( temp_yellow_card ) > biggest_played_card)
                {
                    biggest_played_card = stoi( temp_yellow_card );
                }

            }
        }
    }

    void Control_Cards::set_zemestan_power(const Gameplay game,int index_of_player)
    {//set power when is zemestan
        for(int i = 0 ; i < game.get_play_cards();i++)
        {
            if(game.get_play_cards_data(i) != "matarsak"&&game.get_play_cards_data(i) != "shir_dokht"&&game.get_play_cards_data(i) != "tabl_zan"&&game.get_play_cards_data(i) != "bahar"
               &&game.get_play_cards_data(i) !="zemestan"&&game.get_play_cards_data(i) != "Empty"&&game.get_play_cards_data(i) != "rish_sefid"&&game.get_play_cards_data(i) != "shir_zan"&&
               game.get_play_cards_data(i) != "shir_zan")
            {
                string temp_yellow_card;
                temp_yellow_card = game.get_play_cards_data(i);
                power[index_of_player] = (power[index_of_player] + 1) - ( stoi(temp_yellow_card) );
            }

        }

    }

    void Control_Cards::set_battle_city_chooser()
    {
        int biggest_power = 0;
        for(int i = 0; i < power.size() ;i++)
        {
            if( power[i] > biggest_power)
            {
                biggest_power = power[i];
                first_attacker = i;
            }
        }
    }

    void Control_Cards::set_shir_zan_effect()
    {

    }




