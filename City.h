#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <vector>
#ifndef CITY_H
#define CITY_H
using namespace std;

struct Red_color_city{

    vector <vector<string>> red_cities = {
    {"BELLA","ghale","kohestan"},
    {"LIA","ghale","jangal"},
    {"ATELA","jangal","kohestan"},
    {"CALINE"},
    {"BORGE","ghale"},
    {"PLADACI"},
    {"DIMASE","kohestan"},
    {"MORINA","kohestan","ghale","jangal"},
    {"OLIVADI","ghale"},
    {"ROLLO","ghale"},
    {"TALMONE","jangal"},
    {"ARMENTO","jangal","ghale"},
    {"ENNA"},
    {"ELINIA","jangal","kohestan"},
    {"ATEN",}

    };

    vector <int> taken_cities_number = {7,6,5,0,4,0,3,9,4,4,2,6,0,5,0};
};

class City{//to control the Map of game and the citys(include every methods and datas needed for controlling the citys)
public:
    City();

    ///setter

    void set_city(string);
    void set_red_cities(int,int,string);
    void set_taken_cities_number(int,int);
    ///getter

    string get_city(int)const;
    int get_size_of_city()const;
    string get_red_cities(int,int)const;
    int get_taken_cities_number(int)const;
    int get_red_cities_size(int)const;
    ///method

    void show_taken_cities() const;
    bool check_taken_cities(string,string);//check that player do not enter a name of a taken city
    bool set_adjacent_cities();//check adjacent for the taken citys by a player
    void setting_herkol_effect(string);
    void setting_kooh_shekan_effect(string);
    void setting_rooh_jangal_effect(string);
    bool open_city(string);

private:

    Red_color_city spacial_cities;
    vector <string>taken_city;
    void check_second_adjacent(int &,int,unordered_map<string, vector<string>>,string,int);

};


#endif
