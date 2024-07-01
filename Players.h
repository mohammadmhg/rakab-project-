#include <iostream>
#include <vector>
#include <string>

#ifndef PLAYERS_H
#define PLAYERS_H

using namespace std;
struct Identity{
    string name;
    int age;
    string color;
};

class Players{
public:
    ///constructor
    Players();
    Players(int,string,string,int);
    ///setter
    void set_age(int);
    void set_name(string);
    void set_color(string);
    void set_conquer_cities_number();
    void set_player(int);
    ///getter
    string get_name(int) const;
    int get_age(int) const;
    string get_color(int) const;
    int get_conquer_cities_number() const;
    int get_number_of_player() const;
    ///method
    void sort_array();
    void defind_players();
    void set_player_correct();

private:
    vector <Identity> players;
    int conquer_cities_number;
    int number_of_players;
    int index_of_players = 0;
    bool check_age(int);
    bool check_color(string&);

};



#endif
