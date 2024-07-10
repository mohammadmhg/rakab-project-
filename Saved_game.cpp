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

    void Saved_Game::saving_gamplay_data(const vector<Gameplay>& game_gameplay)
    {

    }


