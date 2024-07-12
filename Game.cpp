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
