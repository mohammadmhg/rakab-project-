#ifndef PLAYERS_H
#define PLAYERS_H
#include <iostream>
using namespace std;


class Players{
public:
    ///constructor
    Players();
    Players(int,string,string);
    ///setter
    void set_ageP(int);
    void set_nameP(string)
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
    void Sort_Array(vector <Players>&);
    void Defind_players();
    void SetUsers_player();

private:
    int age;
    string name;
    string color;
    int taken_cities;
    int players;

};



#endif
