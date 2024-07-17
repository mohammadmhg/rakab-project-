#include <ctime>
#include <conio.h>
#include "Game.h"

using namespace std;

    Game::Game()
    {
        open_the_menu();
    }

    ///getter
    bool Game::get_exit_game()const
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
        Upload_Game game_upload;
        game_upload.uploading_the_player_identity(play);
        for(int i = 0; i < play.get_number_of_player() ;i++)
        {
            Gameplay x;
            game_gameplay.push_back(x);
        }
        game_upload.uploading_gamplay_cards(play.get_number_of_player(),game_gameplay);
        game_upload.uploading_gamplay_data(play.get_number_of_player(),game_gameplay,rish_sefid_handel);
        game_control.setting_size(play.get_number_of_player());
        game_upload.uploading_control_data(play.get_number_of_player(),game_control);
        for(int i = 0 ; i< play.get_number_of_player();i++)
        {
            City z;
            game_city.push_back(z);
        }
        game_upload.uploading_cities_data(play.get_number_of_player(),warzone,peacezone,game_city);
        int players_index = game_gameplay[0].get_players_turn();///the first_attacker is index of first person who start the game so to continue in order we set Players_index and use it for++ in"for" only
        starting_the_round(players_index);
    }

    void Game::game_started()
    {
        while(!end_of_game)
        {
            if( game_gameplay[0].get_empty_hand_players() >= (play.get_number_of_player() - 1) )
            {
                game_gameplay[0].re_set_empty_hand_players();
                game_gameplay.clear();
                for(int i = 0; i < play.get_number_of_player(); i++)
                {
                    Gameplay b;
                    game_gameplay.push_back(b);
                }
                for(int i = 0; i< play.get_number_of_player() ; i++)
                {
                    game_gameplay[i].setting_card(game_card,play.get_conquer_cities_number(i) );
                }
            }

            for(int i = 0 ;i < play.get_number_of_player();i++)
            {
                game_gameplay[i].print_cards(i,play);///this function is only for print
            }

            if( rish_sefid_handel.get_used_rish_sefid_card() )
            {
                rish_sefid_handel.set_used_rish_sefid_card(false);
                peacezone.define_peace_sign(rish_sefid_handel.get_last_played_card_index() );
                validation_of_peace_sign();
            }

            system("cls");
            warzone.define_war_sign( game_control.get_battle_city_chooser() );
            for(int i = 0; i < play.get_number_of_player();i++)//to check that player can Enter a name of a EMPTY city
            {
                while(game_city[i].check_taken_cities( warzone.get_war_sign(),peacezone.get_peace_sign() ) )
                {
                        cout << "Invalid City!!" << endl;
                        i = 0;
                        warzone.define_war_sign( game_control.get_battle_city_chooser() );
                }
            }
            int players_index = game_control.get_first_attacker();///the first_attacker is index of first person who start the game so to continue in order we set Players_index and use it for++ in"for" only
            starting_the_round(players_index);
            set_power_of_army();
            set_most_powerful_army();
            show_power_of_army();
            set_winner_of_battle();

            winner = false;
            game_control.re_set_most_powerful( play.get_number_of_player() );
            game_gameplay[0].set_seasons();
            game_control.set_biggest_card_played(0);
        }//end_of_game while
    }

    void Game::starting_the_round(int players_index)
    {
        while(!winner)
        {
            for(players_index ; players_index < play.get_number_of_player(); players_index++)
            {
                saving_the_game_data();
                game_map.showing_map( play.get_number_of_player(),warzone.get_war_sign(),game_gameplay,game_city);
                game_gameplay[players_index].show_saturation(players_index,play.get_number_of_player(),game_control.get_biggest_card() );

                if(game_gameplay[players_index].get_pass() == true && game_gameplay[players_index].get_pass_counted() == false)
                {
                    game_gameplay[players_index].set_pass_counted(true);//to sure that we already count this pass
                    game_gameplay[players_index].set_passed_players();
                    game_control.set_handel_passed_players(players_index);
                }
                if (rish_sefid_handel.get_rish_sefid_card() )
                {
                    game_gameplay[players_index].handel_rish_sefid(play.get_number_of_player(),game_gameplay);
                    game_control.set_biggest_card_played(0);
                    rish_sefid_handel.set_rish_sefid_card(false);
                }

                game_control.set_biggest_card(game_gameplay[players_index]);//set the biggest played card

                if( game_gameplay[players_index].get_help() )
                {
                    game_gameplay[players_index].set_help(false);
                    players_index--;
                }
                if( game_gameplay[players_index].get_parcham_dar() )
                {
                    winner = true;//ending while
                    game_gameplay[players_index].re_set_parcham_dar();
                    break;
                }
            }
            players_index = 0;//to restart
            if (game_gameplay[players_index].get_passed_players() >= play.get_number_of_player() )
            {//to end the round on fight in a city
                game_gameplay[players_index].re_set_passed_players();
                game_gameplay[players_index].check_empty_cards(play.get_number_of_player(),game_gameplay);
                winner = true;
            }
        }//winner while

    }

    void Game::set_power_of_army()
    {

        for(int i =0; i< play.get_number_of_player() ;i++)
            {
                if( game_gameplay[i].get_bahar() )
                {
                    game_control.calculate_yellow_card_power( game_gameplay[i],i );
                    game_control.calculate_purple_card_power( game_gameplay[i],i );
                    game_control.set_bahar_power( game_gameplay[i],i );
                }
                else if (game_gameplay[i].get_zemestan() )
                {
                    game_control.calculate_yellow_card_power( game_gameplay[i],i );
                    game_control.set_zemestan_power( game_gameplay[i],i );
                    game_control.calculate_purple_card_power( game_gameplay[i],i );
                }
                else
                {
                    game_control.calculate_yellow_card_power( game_gameplay[i],i );
                    game_control.calculate_purple_card_power( game_gameplay[i],i );
                }
            }

    }

    void Game::set_most_powerful_army()
    {
            system("cls");
            for(int i =0 ; i< play.get_number_of_player() ; i++)
            {
                game_gameplay[i].re_set_pass();
            }
            game_control.set_battle_city_chooser();
            if( game_control.get_shir_zan_got_used() )
            {
                game_control.set_shir_zan_effect();
            }
    }

    void Game::show_power_of_army()
    {
        system("cls");
        cout << "Army_power in order from Player1 to Player" <<play.get_number_of_player()<<endl;
        game_control.show_power();
    }

    void Game::set_winner_of_battle()
    {
            getch();
            if ( game_control.get_winner() )
            {
                game_map.round_end( game_control.get_first_attacker() );
                play.set_conquer_cities_number( game_control.get_first_attacker() );
                game_city[game_control.get_first_attacker()].set_city( warzone.get_war_sign() );
            }
            for(int k = 0; k < play.get_number_of_player() ;k++)
            {
                if (play.get_conquer_cities_number(k) >= 3)
                {
                    if(game_city[k].set_adjacent_cities() )
                    {//end of game by adjacent
                        game_map.winner_player(k);
                        end_of_game = true;
                    }
                    if(play.get_conquer_cities_number(k) >= 5)
                    {//end of game by taking the citys
                        game_map.winner_player(k);
                        end_of_game = true;
                    }
                }
            }
    }

    void Game::validation_of_peace_sign()
    {
        string temp_war = "none";
        for(int i = 0; i < play.get_number_of_player();i++)//to check that player can Enter a name of a EMPTY city
        {
                while(game_city[i].check_taken_cities( peacezone.get_peace_sign(),temp_war ) )
                {
                        cout << "Invalid City!!" << endl;
                        i = 0;
                        peacezone.define_peace_sign( rish_sefid_handel.get_last_played_card_index() );
                }
        }
    }

    void Game::saving_the_game_data()
    {
        game_saver.saving_the_player_identity(play);
        game_saver.saving_gamplay_cards(play.get_number_of_player(),game_gameplay);
        game_saver.saving_gamplay_data(play.get_number_of_player(),game_gameplay,rish_sefid_handel);
        game_saver.saving_control_data(play.get_number_of_player(),game_control);
        game_saver.saving_cities_data(play.get_number_of_player(),warzone,peacezone,game_city);
    }
