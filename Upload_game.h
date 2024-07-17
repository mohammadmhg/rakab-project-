#include "Rish_sefid.h"
#include "Peace_sign.h"
#include "Player.h"
#include "Gameplay.h"
#include "Print_game.h"
#include "War_sign.h"
#include "Control_card.h"
#include "City.h"
#include <fstream>

#ifndef UPLOAD_GAME_H
#define UPLOAD_GAME_H

using namespace std;

class Upload_Game{

public:
    Upload_Game();

    void uploading_the_player_identity(Players&);

    void uploading_gamplay_cards(const int,vector<Gameplay>&);

    void uploading_gamplay_data(const int,vector<Gameplay>&,Rish_Sefid&);

    void uploading_control_data(const int,Control_Cards&);

    void uploading_cities_data(const int,War_Sign &,Peace_Sign &,vector <City> &);

private:
    ifstream input_player_identity;
    ifstream input_gameplay_cards;
    ifstream input_gameplay_play_card;
    ifstream input_gameplay_data;
    ifstream input_control_data;
    ifstream input_cities_data;

};



#endif
