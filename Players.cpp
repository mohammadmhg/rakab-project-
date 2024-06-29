#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Players.h"

using namespace std;


    Players::Players()
    {
        players[index_of_players].age = 0;
        players[index_of_players].name = "None";
        players[index_of_players].color = "None";
        index_of_players++;
    }
    Players::Players(int age,string name,string color,int number_of_players): number_of_players(number_of_players)
    {

    }
    ///setter
    void Players::set_age(int number){
        this->players[index_of_players].age = number;
    }
    void Players::set_name(string name){
        this->players[index_of_players].name = name;
    }
    void Players::set_color(string color){
        this->players[index_of_players].color = color;
    }
    void Players::set_conquer_cities_number(){
        this->conquer_cities_number = conquer_cities_number + 1;
    }
    void Players::set_player(int number){
        this->number_of_players = number;
    }
    ///getter
    string Players::get_name(int index) const {
        return players[index].name;
    }
    int Players::get_age(int index) const{
        return players[index].age;
    }
    string Players::get_color(int index) const{
        return players[index].color;
    }
    int Players::get_conquer_cities_number() const{
        return conquer_cities_number;
    }
    int Players::get_number_of_player() const{
        return number_of_players;
    }
    ///method

    void Players::sort_array(){
        sort(players.begin(),players.end(),[](Identity& temp1,Identity& temp2){
            return temp1.age < temp2.age;
        });
    }

    void Players::defind_players()
    {
        string temp_name;
        int temp_age;
        string temp_color;

        system("cls");
        cout << "Enter the name and age and color of each person in the Game please : "<<endl;
        cout << "Enter Name: "<<endl;
        cin >> temp_name;
        cout <<"Enter age: "<<endl;
        while( check_age(temp_age) )
        {
            cout << "The Age is not valid!!"<<endl;
            cin >> temp_age;
        }
        cout <<"Enter color: "<<endl;
        cin >> temp_color;
        while ( check_color(temp_color) )
        {
            cout << "The Color is not valid!!"<<endl;
            cin >> temp_age;
        }

        Players::set_name(temp_name);
        Players::set_age(temp_age);
        Players::set_color(temp_color);
        index_of_players++;
    }

    void Players::set_player_correct(){
        int temp_players;
        cin >> temp_players;
        while(temp_players > 6 || temp_players < 3){
            cout << "The number of Players is not valid!!"<<endl;
            cin >> temp_players;
        }
        Players::set_player(temp_players);
    }

    bool Players::check_age(int temp_age)
    {
        if (temp_age > 120 || temp_age < 1)
        {
            return true;
        }
        return false;
    }

    bool Players::check_color(string &temp_color)
    {
        transform(temp_color.begin() , temp_color.end() , temp_color.begin() , ::toupper);

        for (int i =0 ; i < number_of_players ; i++)
        {
            if (players[i].color == temp_color)
            {
                return true;
            }
        }
        return false;
    }
