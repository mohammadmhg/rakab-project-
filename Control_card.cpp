#include <iostream>
#include <string>
#include <vector>
#include "Control_card.h"




int Control_Cards::biggest_played_card = 0;
int Control_Cards::first_attacker = 0;




using namespace std;

    ///constructor
    Control_Cards::Control_Cards()
    {
    }
    Control_Cards::Control_Cards(int temp_size)
    {
        power.resize(temp_size);
        shir_zan_numbers.resize(temp_size);
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

    void Control_Cards::setting_size(int temp_size)
    {
        power.resize(temp_size);
        shir_zan_numbers.resize(temp_size);
    }

    void Control_Cards::set_power(int number)
    {
        this->power.push_back(number);
    }

    void Control_Cards::set_winner(bool flag)
    {
        this->winner = flag;
    }


    void Control_Cards::re_set_most_powerful(int number)
    {
        shir_zan_numbers.clear();
        shir_zan_numbers.resize(number);
        winner = false;
        shir_zan_got_used = false;
        power.clear();
        power.resize(number);
        handel_passed_players.clear();
    }

    void Control_Cards::set_handel_passed_players(int index_of_player)
    {
        handel_passed_players.push_back(index_of_player);
    }

    ///getter
    int Control_Cards::get_shir_zan_size()const
    {
        return shir_zan_numbers.size();
    }

    int Control_Cards::get_passed_players_number()const
    {
        return handel_passed_players.size();
    }

    int Control_Cards::get_passed_players_data(int index) const
    {
        return handel_passed_players[index];
    }

    int Control_Cards::get_first_attacker() const
    {
        return first_attacker;
    }

    int Control_Cards::get_power(int index) const
    {
        return power[index];
    }

    bool Control_Cards::get_winner() const
    {
        return winner;
    }

    int Control_Cards::get_biggest_card() const
    {
        return biggest_played_card;
    }

    int Control_Cards::power_size() const
    {
        return power.size();
    }

    bool Control_Cards::get_shir_zan_got_used()const
    {
        return shir_zan_got_used;
    }

    int Control_Cards::get_battle_city_chooser() const
    {
        return battle_city_chooser;
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
                shir_zan_got_used = true;
            }
        }
        power[index_of_player] = power[index_of_player] + temp_shir_zan;
        power[index_of_player] = power[index_of_player] + temp_shir_dokht;
        shir_zan_numbers[index_of_player] = temp_shir_zan;

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
        for(int i = 0; i < power.size() ;i++)
        {
            for(int j = i+1 ;j < power.size() ;j++)
            {
                if( power[i] == power[j] && power[i] == biggest_power)
                {
                    int first_player = check_handel_passed_players(i);
                    int second_player = check_handel_passed_players(j);
                    if( first_player > second_player)
                    {
                        first_attacker = i;
                    }
                    if( first_player < second_player)
                    {
                        first_attacker = j;
                    }
                }
            }
        }
        battle_city_chooser = first_attacker;
    }

    void Control_Cards::set_shir_zan_effect()
    {
        int biggest_shir_zan = 0;
        for(int i = 0; i < shir_zan_numbers.size() ;i++)
        {
            if( shir_zan_numbers[i] > biggest_shir_zan)
            {
                biggest_shir_zan = shir_zan_numbers[i];
                battle_city_chooser = i;
            }
        }

        for(int i = 0; i < shir_zan_numbers.size() ;i++)
        {
            for(int j = i+1 ;j < shir_zan_numbers.size() ;j++)
            {
                if( shir_zan_numbers[i] == shir_zan_numbers[j] && shir_zan_numbers[i] == biggest_shir_zan)
                {
                    battle_city_chooser = first_attacker;
                }
            }
        }

    }

    int Control_Cards::check_handel_passed_players(int index_of_player)
    {
        for(int k = 0; k < handel_passed_players.size() ;k++)
        {
            if( handel_passed_players[k] == index_of_player)
            {
                return k;
            }
        }
        return 0;
    }






