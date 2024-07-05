#include <iostream>
#include <unordered_map>
#include <vector>
#ifndef CITY_H
#define CITY_H
using namespace std;

class City{//to control the Map of game and the citys(include every methods and datas needed for controlling the citys)
public:
    ///setter

    void set_city(string);

    ///getter

    string get_city(int);
    ///method

    void show_taken_city() const;

    bool check_taken_cities(string);//check that player do not enter a name of a taken city

    bool set_adjacent_cities();//check adjacent for the taken citys by a player


private:
    vector <string>taken_city;

    void check_second_adjacent(int &,int,unordered_map<string, vector<string>>,string,int);

};


#endif
