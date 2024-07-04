#ifndef CONTROL_CARD_H
#define CONTROL_CARD_H

class Control_Cards{///this class this for controlling the power of each player army(include normal and some spacial cards related to Army power)
public:
    ///constructor
    Control_Cards();
    Control_Cards(int,bool);
    ///setter
    void set_biggest_card_played();

    void set_power(int);

    void set_winner(bool);

    void set_most_powerful();

    void re_set_most_powerful();
    ///getter

    int get_power();

    int get_most_powerful();

    bool get_winner();

    int get_biggest_card();

#endif
