
#include "Gameplay.h"
#include "City.h"
#ifndef PRINT_GAME_H
#define PRINT_GAME_H
using namespace std;

class Print_Game{//print the map of game in each round and show the informations that are needed
public:
    Print_Game();

    void showing_map(const int,const string,const vector<Gameplay>,const vector<City>);

    void winner_player (int);

    void round_end (int);

private:
    void show_players(int,string);
};

#endif
