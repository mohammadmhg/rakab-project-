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
            output_gameplay_cards << endl << "player"<<i<<endl;
        }

        for(int i = 0 ; i < number_of_players ;i++)
        {
            for(int j = 0 ; j < game_gameplay[i].get_play_cards() ;j++)
            {
                output_gameplay_play_card << game_gameplay[i].get_play_cards_data(j)<< " ";
            }
            output_gameplay_play_card << endl << "player"<<i<<endl;
        }
    }

    void Saved_Game::saving_gamplay_data(const int number_of_players,const vector<Gameplay>& game_gameplay)
    {
        output_gameplay_data.open("gameplay_data");

        output_gameplay_data << game_gameplay[0].get_bahar() << endl;
        output_gameplay_data << game_gameplay[0].get_zemestan() << endl;
        output_gameplay_data << game_gameplay[0].get_passed_players() << endl;
        output_gameplay_data << game_gameplay[0].get_index_yellow_card() << endl;
        output_gameplay_data << game_gameplay[0].get_index_purple_card() << endl;
        output_gameplay_data << game_gameplay[0].get_empty_hand_players() << endl;

    }






