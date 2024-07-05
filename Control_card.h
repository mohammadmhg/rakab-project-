#include <iostream>
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

    int get_power();

    int get_most_powerful();

    bool get_winner();

    int get_biggest_card();

    ///methods
    void calculate_yellow_card_power();

    void calculate_purple_card_power();//set power by purple cards

    void set_bahar_power();

    void set_biggest_card();//set the biggest played soldier card in game

    void set_zemestan_ppwer();//set power when is zemestan

private:
    bool winner = false;
    int power = 0;
    static int biggest_played_card;
    static int most_powerful;
};
int Control_Cards::biggest_played_card = 0;
int Control_Cards::most_powerful = 0;;
#endif
