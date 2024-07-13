#include "Saved_game.h"

using namespace std;

    Saved_Game::Saved_Game(){}

    ///method

    void Saved_Game::saving_the_player_identity(const Players &play)
    {

        output_player_identity.open("saved_game_identity.txt");
        output_player_identity << play.get_number_of_player() << endl;
        for(int i = 0 ; i < play.get_number_of_player() ; i++)
        {
            output_player_identity << play.get_name(i)<<endl;
            output_player_identity << play.get_age(i) << endl;
            output_player_identity << play.get_color(i) << endl;
            output_player_identity << play.get_conquer_cities_number(i) << endl;
        }
        output_player_identity.close();

    }

    void Saved_Game::saving_gamplay_cards(const int number_of_players,const vector<Gameplay>& game_gameplay)
    {
        output_gameplay_cards.open("gameplay_cards.txt");
        output_gameplay_play_card.open("gameplay_play_card.txt");
        for(int i = 0 ; i < number_of_players ;i++)
        {
            for(int j = 0 ; j < game_gameplay[i].get_cards_size() ;j++)
            {
                output_gameplay_cards << game_gameplay[i].get_cards_data(j)<< " ";
            }
            output_gameplay_cards << endl << "player" <<endl;
        }

        for(int i = 0 ; i < number_of_players ;i++)
        {
            for(int j = 0 ; j < game_gameplay[i].get_play_cards() ;j++)
            {
                output_gameplay_play_card << game_gameplay[i].get_play_cards_data(j)<< " ";
            }
            output_gameplay_play_card << endl << "player" <<endl;
        }

        output_gameplay_cards.close();
        output_gameplay_play_card.close();
    }

    void Saved_Game::saving_gamplay_data(const int number_of_players,const vector<Gameplay>& game_gameplay,const Rish_Sefid& rish_sefid)
    {
        output_gameplay_data.open("gameplay_data");
        output_gameplay_data << game_gameplay[0].get_bahar() << endl;
        output_gameplay_data << game_gameplay[0].get_zemestan() << endl;
        output_gameplay_data << game_gameplay[0].get_passed_players() << endl;
        output_gameplay_data << game_gameplay[0].get_index_yellow_card() << endl;
        output_gameplay_data << game_gameplay[0].get_index_purple_card() << endl;
        output_gameplay_data << game_gameplay[0].get_empty_hand_players() << endl;
        output_gameplay_data << number_of_players << endl;

        for(int i = 0; i < number_of_players ; i++)
        {
            output_gameplay_data << game_gameplay[i].get_pass() <<endl;
            output_gameplay_data << game_gameplay[i].get_pass_counted() <<endl;
            output_gameplay_data << "player" <<endl;
        }

        output_gameplay_data << rish_sefid.get_last_played_card_index() << endl;
        output_gameplay_data << rish_sefid.get_biggest_card_value() << endl;
        output_gameplay_data << rish_sefid.get_used_rish_sefid_card() << endl;
        output_gameplay_data.close();
    }

    void Saved_Game::saving_control_data(const int number_of_player,const Control_Cards& game_control)
    {
        output_control_data.open("control_data.txt");

        output_control_data << number_of_player <<endl;
        output_control_data << game_control.get_biggest_card() <<endl;
        output_control_data << game_control.get_shir_zan_got_used() <<endl;
        output_control_data << game_control.get_passed_players_number() << endl;
        for(int i = 0; i < game_control.get_passed_players_number() ;i++)
        {
            output_control_data << game_control.get_passed_players_data(i) << endl;
        }
        output_control_data.close();
    }

    void Saved_Game::saving_cities_data(const int number_of_player,const War_Sign& warzone,const Peace_Sign& peacezone,const vector<City>& game_city)
    {
        output_cities_data.open("city_data.txt");

        output_cities_data << peacezone.get_peace_sign() <<endl;
        output_cities_data << warzone.get_war_sign() << endl;
        output_cities_data << number_of_player << endl;

        for(int i = 0; i < number_of_player ; i++)
        {
            for(int j = 0 ; j < game_city[i].get_size_of_city() ;j++)
            {
                output_cities_data << game_city[i].get_city(j) << endl;
            }
            output_cities_data << "player" << endl;
        }
        output_cities_data.close();
    }



    void Saved_Game::uploading_the_player_identity(Players& play)
    {
        input_player_identity.open("saved_game_identity.txt");
        int number_of_player = 0;
        int number_of_cities = 0;
        string name;
        int age = 0;
        string color;
        input_player_identity >> number_of_player;
        play.set_player(number_of_player);

        for(int i = 0; i < number_of_player ;i++)
        {
            input_player_identity >> name;
            input_player_identity >> age;
            input_player_identity >> color;
            input_player_identity >> number_of_cities;
            play.set_name(name);
            play.set_age(age);
            play.set_color(color);
            play.set_conquer_cities_number(number_of_cities);
            play.add_index_of_players();
        }
        input_player_identity.close();
    }



    void Saved_Game::uploading_gamplay_cards(const int number_of_player,vector<Gameplay>& game_gameplay)
    {
        input_gameplay_cards.open("gameplay_cards.txt");
        input_gameplay_play_card.open("gameplay_play_card.txt");
        string card_reader;

        for(int i = 0 ; i < number_of_player ; i++)
        {
            input_gameplay_cards >> card_reader;
            while( card_reader != "player")
            {
                game_gameplay[i].set_cards(card_reader);
                input_gameplay_cards >> card_reader;
            }
        }
        for(int i = 0 ; i < number_of_player ; i++)
        {
            input_gameplay_play_card >> card_reader;
            while( card_reader != "player")
            {
                game_gameplay[i].add_play_cards(card_reader);
                input_gameplay_play_card >> card_reader;
            }
        }
        input_gameplay_cards.close();
        input_gameplay_play_card.close();
    }



    void Saved_Game::uploading_gamplay_data(const int number_of_player,vector<Gameplay>& game_gameplay,Rish_Sefid& rish_sefid)
    {
        input_gameplay_data.open("gameplay_data.txt");
        bool bool_reader;
        int int_reader = 0;

        input_gameplay_data >>  bool_reader;
        game_gameplay[0].set_bahar(bool_reader);
        input_gameplay_data >> bool_reader;
        game_gameplay[0].set_zemestan(bool_reader);
        input_gameplay_data >> int_reader;
        game_gameplay[0].add_passed_players_number(int_reader);
        input_gameplay_data >> int_reader;
        game_gameplay[0].set_index_yellow_card(int_reader);
        input_gameplay_data >> int_reader;
        game_gameplay[0].set_index_purple_card(int_reader);
        input_gameplay_data >> int_reader;
        game_gameplay[0].set_empty_hand_players(int_reader);
        input_gameplay_data >> int_reader;
        game_gameplay[0].set_players_turn(int_reader);

        for(int i = 0; i < number_of_player ; i++)
        {
            input_gameplay_data >> bool_reader;
            game_gameplay[i].set_pass(bool_reader);
            input_gameplay_data >> bool_reader;
            game_gameplay[i].set_pass_counted(bool_reader);
        }

        input_gameplay_data >> int_reader;
        rish_sefid.set_last_played_card_index(int_reader);
        input_gameplay_data >> int_reader;
        rish_sefid.set_biggest_card_value(int_reader);
        input_gameplay_data >> bool_reader;
        rish_sefid.set_used_rish_sefid_card(bool_reader);

        input_gameplay_data.close();
    }