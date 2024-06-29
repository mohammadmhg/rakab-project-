#include <iostream>
#include <vector>

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
    Players(int,string,string);
    ///setter
    void set_ageP(int);
    void set_nameP(string);
    void set_color(string);
    void set_taken_cities(int);
    void set_player(int);
    ///getter
    string Getname() const;

    int getage() const;
    string getcolor() const;
    int get_taken_cities();
    int get_player();
    ///method
    void Sort_Array(Players &);
    void Defind_players();
    void SetUsers_player();

private:
    vector <Identity> players;
    int taken_cities;
    int number_of_players;

};



#endif
