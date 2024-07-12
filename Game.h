#include "Menu.h"
#include "Rish_sefid.h"
#include "Peace_sign.h"
#include "Player.h"
#include "Gameplay.h"
#include "Print_game.h"
#include "War_sign.h"
#include "Control_card.h"
#include "City.h"
#include "Saved_game.h"
#ifndef GAME_H
#define GAME_H

class Game{
public:
    Game();
///getter
    bool get_exit_game()const;

///method
    void open_the_menu();

    void setting_game();

    void continue_the_last_game();

    void game_started();

    void starting_the_round(int);

    void set_power_of_army();

    void set_most_powerful_army();

    void show_power_of_army();

    void set_winner_of_battle();

    void validation_of_peace_sign();

    void saving_the_game_data();

private:
    Menus user;
    War_Sign warzone;
    Card game_card;
    Print_Game game_map;
    Peace_Sign peacezone;
    Rish_Sefid rish_sefid_handel;
    Saved_Game game_saver;
    Players play;
    vector <Gameplay> game_gameplay;
    Control_Cards game_control;
    vector <City> game_city;
    bool winner = false;
    bool end_of_game = false;
    bool exit = false;

};

#endif
