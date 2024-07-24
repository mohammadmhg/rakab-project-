#include <vector>
#include <string>
#include "Menu.h"
#include "Player.h"
#include "Rish_sefid.h"
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
    void set_players_turn(int);

    void set_help(bool);

    void set_cards(string);

    void set_played_card(string);

    void set_pass_counted(bool);

    void set_bahar(bool);

    void set_zemestan(bool);

    void add_passed_players_number(int);

    void set_index_yellow_card(int);

    void set_pass(bool);

    void set_index_purple_card(int);

    void re_set_data();

    void set_passed_players();

    void re_set_pass();

    void re_set_empty_hand_players();

    void set_empty_hand_players(int);

    void add_play_cards(string);
    ///getter
    int get_passed_players()const;

    bool get_help()const ;

    bool get_parcham_dar()const;

    bool get_pass_counted() const;

    bool get_bahar()const ;

    bool get_zemestan() const;

    int get_play_cards() const;

    string get_play_cards_data(int &) const;

    bool get_pass()const;

    int get_empty_hand_players() const;

    string get_cards_data(int &) const;

    int get_cards_size()const;

    int get_index_purple_card()const;

    int get_index_yellow_card()const;

    int get_players_turn()const;

    ///method
    void print_cards(const int,const Players);
    void show_saturation(int,int,int);
    void setting_card(const Card,const int);
    void check_empty_cards(int,vector <Gameplay>);
    void handel_rish_sefid(int,vector <Gameplay> &);



private:

    void matarsak();
    void cards_helping_menus(string&);
    void input_chosen_card(string);
    int get_chosen_card();
    bool check_exist_card(string);
    bool check_exist_played_card(string)const;
    void show_cards_array()const;
    void validation_of_input(string&);
    void setting_the_input_card();
    void define_players_turn(int,int);


    vector <string> cards;
    vector <string> play_cards;
    Menus menu;
    int chosen_card = 0;
    bool getting_help = false;
    static bool is_bahar;
    static bool is_zemestan;
    Rish_Sefid rish_sefid_handel;
    static int passed_players;
    static int index_yellow_card;
    static int index_purple_card;
    static int empty_hand_players;
    static int players_turn;
    static bool used_parcham_dar;
    bool pass = false;
    bool pass_counted = false;
};





#endif // GAMEPLAY_H
