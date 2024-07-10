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

    void saving_gamplay_data(const int,const vector<Gameplay>&);





private:
    ofstream output_player_identity;
    ofstream output_gameplay_cards;
    ofstream output_gameplay_play_card;
    ofstream output_gameplay_data;
};





#endif
