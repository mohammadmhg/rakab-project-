#include "Rish_sefid.h"
#include "Peace_sign.h"
#include "Player.h"
#include "Gameplay.h"
#include "Print_game.h"
#include "War_sign.h"
#include "Control_card.h"
#include "City.h"
#include <fstream>

#ifndef SAVED_GAME_H
#define SAVED_GAME_H

class Saved_Game{
public:
    Saved_Game();

    ///method
    void saving_the_player_identity(const Players&);

    void saving_gamplay_cards(const int,const vector<Gameplay>&);

    void saving_gamplay_data(const int,const vector<Gameplay>&,const Rish_Sefid&);

    void saving_control_data(const int,const Control_Cards&);

    void saving_cities_data(const int,const War_Sign&,const Peace_Sign&,const vector<City>&);

    void uploading_the_player_identity(Players&);

    void uploading_gamplay_cards(const int,vector<Gameplay>&);

    void uploading_gamplay_data(const int,vector<Gameplay>&,Rish_Sefid&);

    void uploading_control_data(const int,Control_Cards&);

    void uploading_cities_data(const int,War_Sign&,Peace_Sign&,vector<City>&);

private:
    ofstream output_player_identity;
    ofstream output_gameplay_cards;
    ofstream output_gameplay_play_card;
    ofstream output_gameplay_data;
    ofstream output_control_data;
    ofstream output_cities_data;

    ifstream input_player_identity;
    ifstream input_gameplay_cards;
    ifstream input_gameplay_play_card;
    ifstream input_gameplay_data;
    ifstream input_control_data;
    ifstream input_cities_data;

};





#endif
