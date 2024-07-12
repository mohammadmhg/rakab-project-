#include <ctime>
#include <conio.h>
#include "Game.h"

using namespace std;

    Game::Game()
    {
        open_the_menu();
    }

    ///getter
    bool Game::get_exit_game()
    {
        return exit;
    }
    ///method
    void Game::open_the_menu()
    {
        bool flag = user.action();
        if(!flag)
        {
            user.ending();
            exit = true;
            return;
        }
        if( user.get_loading_game() )
        {//uploading last game and continue it
            continue_the_last_game();
            set_power_of_army();
            set_most_powerful_army();
            show_power_of_army();
            set_winner_of_battle();
            winner = false;
            game_control.re_set_most_powerful( play.get_number_of_player() );
            game_gameplay[0].set_seasons();
            game_control.set_biggest_card_played(0);
            game_started();
        }
        if( user.get_loading_game() == false)//starting a new game
        {
            setting_game();
        }

    }

    void Game::setting_game()
    {
        play.set_player_correct();

        for(int i = 0 ; i< play.get_number_of_player();i++)
        {
            City x;
            game_city.push_back(x);
        }

        for(int i = 0; i < play.get_number_of_player(); i++)
        {
            Gameplay b;
            game_gameplay.push_back(b);
        }

        game_control.setting_size(play.get_number_of_player());

        for(int i = 0; i< play.get_number_of_player() ; i++)
        {
            game_gameplay[i].setting_card(game_card,play.get_conquer_cities_number(i) );
        }

        game_started();

    }

    void Game::continue_the_last_game()
    {
        system("cls");
        game_saver.uploading_the_player_identity(play);
        for(int i = 0; i < play.get_number_of_player() ;i++)
        {
            Gameplay x;
            game_gameplay.push_back(x);
        }
        game_saver.uploading_gamplay_cards(play.get_number_of_player(),game_gameplay);
        game_saver.uploading_gamplay_data(play.get_number_of_player(),game_gameplay,rish_sefid_handel);
        game_control.setting_size(play.get_number_of_player());
        game_saver.uploading_control_data(play.get_number_of_player(),game_control);
        for(int i = 0 ; i< play.get_number_of_player();i++)
        {
            City z;
            game_city.push_back(z);
        }
        game_saver.uploading_cities_data(play.get_number_of_player(),warzone,peacezone,game_city);
        int players_index = game_gameplay[0].get_players_turn();///the first_attacker is index of first person who start the game so to continue in order we set Players_index and use it for++ in"for" only
        starting_the_round(players_index);
    }
