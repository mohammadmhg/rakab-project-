#include <vector>
#include "Menu.h"
#include "Player.h"
#include "Card.h"
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

using namespace std;

class Gameplay{///this class is for Gameplay during each round and setting Cards and Played Cards for User and Controlling every thing related to Cards in a round
    public:
    ///constructor
    Gameplay();
    Gameplay(string,string);

    ///setter
    void set_help(bool);

    void set_first_attacker(int);

    void set_cards(string);

    void set_played_card(string);

    void set_pass_counted(bool);

    void set_seasons();

    void set_passed_players();

    void re_set_passed_players();
    ///getter
    int get_passed_players()const;

    bool get_help()const ;

    int get_first_attacker()const;

    bool get_pass_counted() const;

    bool get_bahar()const ;

    bool get_zemestan() const;

    int get_play_cards() const;

    string get_play_cards_data(int &) const;

    bool get_pass()const;

    ///method
    void print_cards(const int,const Players);
    void show_saturation(int);
    void setting_card(const Card,const int);

protected:
    vector <string> cards;
    vector <string> play_cards;
private:

    void matarsak();
    void cards_helping_menus(string&);
    void input_chosen_card(string);
    int get_chosen_card();
    bool check_exist_card(string);
    void show_cards_array()const;

    Menus menu;
    int chosen_card = 0;
    bool getting_help = false;
    static bool is_bahar;
    static bool is_zemestan;

    static int first_attacker;
    static int passed_players;
    static int index_yellow_card;
    static int index_purple_card;
    bool pass = false;
    bool pass_counted = false;
};





#endif // GAMEPLAY_H
