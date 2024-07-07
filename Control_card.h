#include "Gameplay.h"
#ifndef CONTROL_CARD_H
#define CONTROL_CARD_H

using namespace std;


class Control_Cards{///this class this for controlling the power of each player army(include normal and some spacial cards related to Army power)
public:
    ///constructor
    Control_Cards();
    Control_Cards(int,bool);
    ///setter
    void set_biggest_card_played();

    void set_power(int);

    void set_winner(bool);

    void set_most_powerful(int);

    void re_set_most_powerful();
    ///getter

    int get_power()const;

    int get_most_powerful()const;

    bool get_winner()const;

    int get_biggest_card()const;

    ///methods

    void calculate_yellow_card_power(const Gameplay);

    void calculate_purple_card_power(const Gameplay);//set power by purple cards

    void set_bahar_power(const Gameplay);

    void set_biggest_card(const Gameplay);//set the biggest played soldier card in game

    void set_zemestan_power( const Gameplay);//set power when is zemestan


private:
    bool winner = false;
    int power = 0;
    static int biggest_played_card;
    static int most_powerful;
};

#endif
