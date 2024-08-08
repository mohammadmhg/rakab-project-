#include "Upload_game.h"

using namespace std;

    Upload_Game::Upload_Game(){}

    void Upload_Game::uploading_the_player_identity(Players& play)
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

    void Upload_Game::uploading_gamplay_cards(const int number_of_player,vector<Gameplay>& game_gameplay)
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

    void Upload_Game::uploading_gamplay_data(const int number_of_player,vector<Gameplay>& game_gameplay,Rish_Sefid& rish_sefid,Handle_Data& game_data)
    {
        input_gameplay_data.open("gameplay_data.txt");
        bool bool_reader;
        int int_reader = 0;

        input_gameplay_data >>  bool_reader;
        game_data.set_bahar(bool_reader);
        input_gameplay_data >> bool_reader;
        game_data.set_zemestan(bool_reader);
        input_gameplay_data >> int_reader;
        game_gameplay[0].add_passed_players_number(int_reader);
        input_gameplay_data >> int_reader;
        game_data.set_index_yellow_card(int_reader);
        input_gameplay_data >> int_reader;
        game_data.set_index_purple_card(int_reader);
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

    void Upload_Game::uploading_control_data(const int number_of_player,Control_Cards& game_control)
    {
        game_control.setting_size(number_of_player);
        input_control_data.open("control_data.txt");
        int int_reader = 0;
        int index_passed_players = 0;
        bool bool_reader = 0;

        input_control_data >> int_reader;
        game_control.set_lucky_number(int_reader);
        input_control_data >> int_reader;
        game_control.set_biggest_card_played(int_reader);
        input_control_data >> bool_reader;
        game_control.set_shir_zan_got_used(bool_reader);
        input_control_data >> int_reader;
        for(int i = 0; i < int_reader; i++)
        {
            input_control_data >> index_passed_players;
            game_control.set_handel_passed_players(index_passed_players);
        }
        input_control_data.close();
    }

    void Upload_Game::uploading_cities_data(const int number_of_player,War_Sign &warzone,Peace_Sign &peacezone,vector <City> &game_city)
    {
        input_cities_data.open("city_data.txt");
        string city_reader;

        input_cities_data >> city_reader;
        peacezone.set_peace_sign(city_reader);
        input_cities_data >> city_reader;
        warzone.set_war_sign(city_reader);

        for(int i = 0; i < number_of_player ; i++)
        {
             input_cities_data >> city_reader;
             while( city_reader != "player")
             {
                 game_city[i].set_city(city_reader);
                 input_cities_data >> city_reader;
             }
        }
        input_cities_data.close();
    }

    void Upload_Game::uploading_red_cards_data(const int number_of_players,vector <City>& game_city)
    {
        input_red_cards_data.open("red_cards.txt");
        string string_reader;
        int int_reader = 0;

        for(int i = 0 ; i < number_of_players ; i++)
        {
            for(int j = 0 ; j < 15 ; j++)
            {
                for( int k = 1 ; k < game_city[i].get_red_cities_size(j) ; k++)
                {
                    input_red_cards_data >> string_reader;
                    game_city[i].set_red_cities(j,k,string_reader);
                }
                input_red_cards_data >> int_reader;
                game_city[i].set_taken_cities_number(j,int_reader);
            }
        }
        input_red_cards_data.close();
    }

