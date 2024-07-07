#include <iostream>
#include <ctime>
#include <conio.h>
#include "Menu.h"
#include "Player.h"
#include "Gameplay.h"
#include "Print_game.h"
#include "War_sign.h"
#include "Control_card.h"
#include "City.h"
#include "Print_game.h"

class Game{
public:
    Game()
    {
        open_the_menu();
    }
///getter
    bool get_exit_game()
    {
        return exit;
    }
///method
    void open_the_menu()
    {
        bool flag = user.action();
        if(!flag)
        {
            user.ending();
            exit = true;
        }
    }
    void setting_game()
    {
        Players play;
        vector <City> game_city;
        for(int i = 0 ; i< play.get_number_of_player();i++)
        {
            City x;
            game_city.push_back(x);
        }


        vector <Gameplay> game_gameplay( play.get_number_of_player() );
        for(int i = 0; i < play.get_number_of_player(); i++)
        {
            Gameplay b;
            game_gameplay.push_back(b);
        }

        for(int i = 0; i< play.get_number_of_player() ; i++)
        {
            game_gameplay[i].setting_card(game_card,play.get_conquer_cities_number(i) );
        }

        game_started(play,game_city,game_gameplay);

    }

    void game_started(Players play,vector <City> game_city,vector <Gameplay> game_gameplay)
    {
        while(!end_of_game)
        {
            if( game_gameplay[0].get_empty_hand_players() >= (play.get_number_of_player() - 1) )
            {
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
            vector <Control_Cards> game_control( play.get_number_of_player() );
            for(int i = 0; i < play.get_number_of_player(); i++)
            {
                Control_Cards b;
                game_control.push_back(b);
            }

            for(int i = 0 ;i < play.get_number_of_player();i++)
            {
                game_gameplay[i].print_cards(i,play);///this function is only for print
            }

            int players_index = game_gameplay[0].get_first_attacker();///the first_attacker is index of first person who start the game so to continue in order we set Players_index and use it for++ in"for" only
            system("cls");
            warzone.define_war_sign();

            for(int i = 0; i < play.get_number_of_player();i++)//to check that player can Enter a name of a EMPTY city
            {
                while(game_city[i].check_taken_cities( warzone.get_war_sign() ) )
                {
                        cout << "Invalid City!!" << endl;
                        i = 0;
                        warzone.define_war_sign();

                }
            }



            for(int i =0; i< play.get_number_of_player() ;i++)
            {
                if( game_gameplay[i].get_bahar() )
                {
                    game_control[i].calculate_yellow_card_power( game_gameplay[i] );
                    game_control[i].calculate_purple_card_power( game_gameplay[i] );
                    game_control[i].set_bahar_power( game_gameplay[i] );
                }
                else if (game_gameplay[i].get_zemestan() )
                {
                    game_control[i].calculate_yellow_card_power( game_gameplay[i] );
                    game_control[i].set_zemestan_power( game_gameplay[i] );
                    game_control[i].calculate_purple_card_power( game_gameplay[i] );
                }
                else
                {
                    game_control[i].calculate_yellow_card_power( game_gameplay[i] );
                    game_control[i].calculate_purple_card_power( game_gameplay[i] );
                }
            }

            system("cls");
            for(int i =0 ; i< play.get_number_of_player() ; i++)
            {
                game_gameplay[i].re_set_pass();
                if (game_control[i].get_power() > game_control[i].get_most_powerful() )
                {
                    game_control[i].set_most_powerful( game_control[i].get_power() );
                    game_gameplay[i].set_first_attacker(i);
                    game_control[i].set_winner(true);

                }
            }
            system("cls");
            cout << "Army_power in order from Player1 to Player" <<play.get_number_of_player()<<endl;
            for(int i =0 ; i < play.get_number_of_player();i++)
            {
                cout << game_control[i].get_power()<<"  ";
            }
            getch();
            if ( game_control[game_gameplay[0].get_first_attacker()].get_winner() )
            {
                game_map.round_end( game_gameplay[0].get_first_attacker() );
                play.set_conquer_cities_number( game_gameplay[0].get_first_attacker() );
                game_city[game_gameplay[0].get_first_attacker()].set_city( warzone.get_war_sign() );
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
            winner = false;

            game_control[0].re_set_most_powerful();
            game_gameplay[0].set_seasons();
            game_control[0].set_biggest_card_played();
        }//end_of_game while

    }












private:
    Menus user;
    War_Sign warzone;
    Card game_card;
    Print_Game game_map;
    bool winner = false;
    bool end_of_game = false;
    bool exit = false;

};
using namespace std;

int main()
{
    srand(time(0));
    Game game_start;
    if( game_start.get_exit_game() )
    {
        return 0;
    }

    Players play;

    War_Sign warzone;

    vector <City> game_city;
    for(int i = 0 ; i< play.get_number_of_player();i++)
    {
        City x;
        game_city.push_back(x);
    }

    Card game_card;

    bool winner = false;
    bool end_of_game = false;
    Print_Game game_map;

    vector <Gameplay> game_gameplay( play.get_number_of_player() );
    for(int i = 0; i < play.get_number_of_player(); i++)
    {
        Gameplay b;
        game_gameplay.push_back(b);
    }

    for(int i = 0; i< play.get_number_of_player() ; i++)
    {
        game_gameplay[i].setting_card(game_card,play.get_conquer_cities_number(i) );
    }

    while(!end_of_game)
    {
        if( game_gameplay[0].get_empty_hand_players() >= (play.get_number_of_player() - 1) )
        {
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
        vector <Control_Cards> game_control( play.get_number_of_player() );
        for(int i = 0; i < play.get_number_of_player(); i++)
        {
            Control_Cards b;
            game_control.push_back(b);
        }

        for(int i = 0 ;i < play.get_number_of_player();i++)
        {
            game_gameplay[i].print_cards(i,play);///this function is only for print
        }

        int players_index = game_gameplay[0].get_first_attacker();///the first_attacker is index of first person who start the game so to continue in order we set Players_index and use it for++ in"for" only
        system("cls");
        warzone.define_war_sign();

        for(int i = 0; i < play.get_number_of_player();i++)//to check that player can Enter a name of a EMPTY city
        {
            while(game_city[i].check_taken_cities( warzone.get_war_sign() ) )
            {
                    cout << "Invalid City!!" << endl;
                    i = 0;
                    warzone.define_war_sign();

            }
        }


        while(!winner)
        {
            for(players_index ; players_index < play.get_number_of_player(); players_index++)
            {
                game_map.showing_map( play.get_number_of_player(),warzone.get_war_sign(),game_gameplay,game_city);
                game_gameplay[players_index].show_saturation(players_index);
                game_control[players_index].set_biggest_card(game_gameplay[players_index]);
                game_gameplay[players_index].check_empty_cards();

                if(game_gameplay[players_index].get_pass() == true && game_gameplay[players_index].get_pass_counted() == false)
                {
                    game_gameplay[players_index].set_pass_counted(true);//to sure that we already count this pass
                    game_gameplay[players_index].set_passed_players();
                }
                if( game_gameplay[players_index].get_help() )
                {
                    game_gameplay[players_index].set_help(false);
                    players_index--;
                }
            }
            players_index = 0;//to restart
            if (game_gameplay[players_index].get_passed_players() >= play.get_number_of_player() )
            {//to end the round on fight in a city
                game_gameplay[players_index].re_set_passed_players();
                winner = true;
                break;
            }
        }//winner while

        for(int i =0; i< play.get_number_of_player() ;i++)
        {
            if( game_gameplay[i].get_bahar() )
            {
                game_control[i].calculate_yellow_card_power( game_gameplay[i] );
                game_control[i].calculate_purple_card_power( game_gameplay[i] );
                game_control[i].set_bahar_power( game_gameplay[i] );
            }
            else if (game_gameplay[i].get_zemestan() )
            {
                game_control[i].calculate_yellow_card_power( game_gameplay[i] );
                game_control[i].set_zemestan_power( game_gameplay[i] );
                game_control[i].calculate_purple_card_power( game_gameplay[i] );
            }
            else
            {
                game_control[i].calculate_yellow_card_power( game_gameplay[i] );
                game_control[i].calculate_purple_card_power( game_gameplay[i] );
            }
        }

        system("cls");
        for(int i =0 ; i< play.get_number_of_player() ; i++)
        {
            game_gameplay[i].re_set_pass();
            if (game_control[i].get_power() > game_control[i].get_most_powerful() )
            {
                game_control[i].set_most_powerful( game_control[i].get_power() );
                game_gameplay[i].set_first_attacker(i);
                game_control[i].set_winner(true);

            }
        }
        system("cls");
        cout << "Army_power in order from Player1 to Player" <<play.get_number_of_player()<<endl;
        for(int i =0 ; i < play.get_number_of_player();i++)
        {
            cout << game_control[i].get_power()<<"  ";
        }
        getch();
        if ( game_control[game_gameplay[0].get_first_attacker()].get_winner() )
        {
            game_map.round_end( game_gameplay[0].get_first_attacker() );
            play.set_conquer_cities_number( game_gameplay[0].get_first_attacker() );
            game_city[game_gameplay[0].get_first_attacker()].set_city( warzone.get_war_sign() );
        }


        for(int k = 0; k < play.get_number_of_player() ;k++)
        {
            if (play.get_conquer_cities_number(k) >= 3)
            {
                if(game_city[k].set_adjacent_cities() )
                {//end of game by adjacent
                    end_of_game = true;
                    game_map.winner_player(k);
                    return 0;
                }
                if(play.get_conquer_cities_number(k) >= 5)
                {//end of game by taking the citys
                    end_of_game = true;
                    game_map.winner_player(k);
                    return 0;
                }
            }
        }
        winner = false;

        game_control[0].re_set_most_powerful();
        game_gameplay[0].set_seasons();
        game_control[0].set_biggest_card_played();
    }//end_of_game while
}
