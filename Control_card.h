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

    void set_first_attacker(int);
    ///getter

    int get_power(int)const;

    int get_shir_zan_size()const;

    int get_most_powerful()const;

    bool get_winner()const;

    int get_biggest_card()const;

    int get_first_attacker()const;

    ///methods
    void show_power()const;

    void calculate_yellow_card_power(const Gameplay,int);

    void calculate_purple_card_power(const Gameplay,int);//set power by purple cards

    void set_bahar_power(const Gameplay,int);

    void set_biggest_card(const Gameplay);//set the biggest played soldier card in game

    void set_zemestan_power( const Gameplay,int);//set power when is zemestan

    void set_battle_city_chooser();

    void set_shir_zan_effect();


private:
    bool winner = false;
    vector<int> power;
    vector<int> shir_zan_numbers;
    static int biggest_played_card;
    static int most_powerful;
    static int first_attacker;
    int battle_city_choser = 0;
};

#endif
