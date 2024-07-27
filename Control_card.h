#include "Gameplay.h"
#ifndef CONTROL_CARD_H
#define CONTROL_CARD_H

using namespace std;


class Control_Cards{///this class this for controlling the power of each player army(include normal and some spacial cards related to Army power)
public:
    ///constructor
    Control_Cards();
    Control_Cards(int);
    ///setter
    void set_biggest_card_played(int);

    void set_power(int);

    void set_winner(bool);

    void set_most_powerful(int);

    void re_set_data(int);

    void set_first_attacker(int);

    void set_handel_passed_players(int);

    void set_shir_zan_got_used(bool);

    void setting_size(int);

    void set_lucky_number(int);

    void set_battle_city(int);
    ///getter

    int power_size()const;

    int get_passed_players_data(int)const;

    int get_power(int)const;

    int get_shir_zan_size()const;

    int get_most_powerful()const;

    bool get_winner()const;

    int get_biggest_card()const;

    int get_first_attacker()const;

    bool get_shir_zan_got_used()const;

    int get_battle_city_chooser() const;

    int get_passed_players_number()const;

    int get_lucky_number()const;

    ///methods
    void show_power()const;

    void calculate_yellow_card_power(const Gameplay,int);

    void calculate_purple_card_power(const Gameplay,int);//set power by purple cards

    void set_bahar_power(const Gameplay,int);

    void set_biggest_card(const Gameplay);//set the biggest played soldier card in game

    void set_zemestan_power( const Gameplay,int);//set power when is zemestan

    void setting_battle_city_chooser();

    void set_shir_zan_effect();

    int check_handel_passed_players(int);

    void setting_parcham_dar_effect(int,int);

    void define_lucky_number();

    void setting_lucky_number_effect();


private:
    bool winner = false;
    vector<int> power;
    vector<int> shir_zan_numbers;
    int biggest_played_card = 0;
    int first_attacker = 0;
    int battle_city_chooser = 0;
    int lucky_number = 0;
    bool shir_zan_got_used = false;
    vector <int> handel_passed_players;
};

#endif
