
#include <ctime>
#include <conio.h>
#include "Menu.h"
#include "Rish_sefid.h"
#include "Peace_sign.h"
#include "Player.h"
#include "Gameplay.h"
#include "Print_game.h"
#include "War_sign.h"
#include "Control_card.h"
#include "City.h"

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
        Control_Cards game_control{ play.get_number_of_player() };
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

            for(int i = 0 ;i < play.get_number_of_player();i++)
            {
                game_gameplay[i].print_cards(i,play);///this function is only for print
            }

            if( rish_sefid_handel.get_used_rish_sefid_card() )
            {
                rish_sefid_handel.set_used_rish_sefid_card(false);
                peacezone.define_peace_sign(rish_sefid_handel.get_last_played_card_index() );
            }

            validation_of_peace_sign(game_city,play);
            system("cls");
            warzone.define_war_sign();
            for(int i = 0; i < play.get_number_of_player();i++)//to check that player can Enter a name of a EMPTY city
            {
                while(game_city[i].check_taken_cities( warzone.get_war_sign(),peacezone.get_peace_sign() ) )
                {
                        cout << "Invalid City!!" << endl;
                        i = 0;
                        warzone.define_war_sign();
                }
            }
            starting_the_round(game_gameplay,game_control,play,game_city);
            set_power_of_army(game_gameplay,game_control,play);
            set_most_powerful_army(game_gameplay,game_control,play);
            show_power_of_army(game_control,play);
            set_winner_of_battle(game_gameplay,game_control,play,game_city);

            winner = false;
            game_control.re_set_most_powerful( play.get_number_of_player() );
            game_gameplay[0].set_seasons();
            game_control.set_biggest_card_played();
        }//end_of_game while
    }

    void starting_the_round(vector <Gameplay> &game_gameplay,Control_Cards &game_control,Players &play,vector <City> &game_city)
    {
        int players_index = game_control.get_first_attacker();///the first_attacker is index of first person who start the game so to continue in order we set Players_index and use it for++ in"for" only
        while(!winner)
        {
            for(players_index ; players_index < play.get_number_of_player(); players_index++)
            {
                game_map.showing_map( play.get_number_of_player(),warzone.get_war_sign(),game_gameplay,game_city);
                game_gameplay[players_index].show_saturation(players_index,play.get_number_of_player(),game_control.get_biggest_card() );
                game_control.set_biggest_card(game_gameplay[players_index]);
                game_gameplay[players_index].check_empty_cards();

                if(game_gameplay[players_index].get_pass() == true && game_gameplay[players_index].get_pass_counted() == false)
                {
                    game_gameplay[players_index].set_pass_counted(true);//to sure that we already count this pass
                    game_gameplay[players_index].set_passed_players();
                    game_control.set_handel_passed_players(players_index);
                }
                if (rish_sefid_handel.get_rish_sefid_card() )
                {
                    game_gameplay[players_index].handel_rish_sefid(play.get_number_of_player(),game_gameplay);
                    rish_sefid_handel.set_rish_sefid_card(false);
                }
                if( game_gameplay[players_index].get_help() )
                {
                    game_gameplay[players_index].set_help(false);
                    players_index--;
                }
                if( game_gameplay[players_index].get_parcham_dar() )
                {
                    game_gameplay[players_index].re_set_parcham_dar();
                    winner = true;//ending while
                }
            }
            players_index = 0;//to restart
            if (game_gameplay[players_index].get_passed_players() >= play.get_number_of_player() )
            {//to end the round on fight in a city
                game_gameplay[players_index].re_set_passed_players();
                winner = true;
            }
        }//winner while

    }

    void set_power_of_army(vector <Gameplay> &game_gameplay,Control_Cards &game_control,Players &play)
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

    void set_most_powerful_army(vector <Gameplay> &game_gameplay,Control_Cards &game_control,Players &play)
    {
            system("cls");
            for(int i =0 ; i< play.get_number_of_player() ; i++)
            {
                game_gameplay[i].re_set_pass();
            }
            game_control.set_battle_city_chooser();
            game_control.set_winner(true);
    }

    void show_power_of_army(Control_Cards &game_control,Players &play)
    {
        system("cls");
        cout << "Army_power in order from Player1 to Player" <<play.get_number_of_player()<<endl;
        game_control.show_power();
    }

    void set_winner_of_battle(vector <Gameplay> &game_gameplay,Control_Cards &game_control,Players &play,vector <City> &game_city)
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

    void validation_of_peace_sign(vector <City> &game_city,Players &play)
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

private:
    Menus user;
    War_Sign warzone;
    Card game_card;
    Print_Game game_map;
    Peace_Sign peacezone;
    Rish_Sefid rish_sefid_handel;
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
    game_start.setting_game();
    return 0;
}
