#include <iostream>
#include <algorithm>


#include "Player.h"

using namespace std;


    Players::Players(){}

    Players::Players(int age,string name,string color,int number_of_players): number_of_players(number_of_players)
    {

    }
    ///setter
    void Players::set_age(int number)
    {
        this->players[index_of_players].age = number;
    }

    void Players::set_name(string data)
    {
        this->players[index_of_players].name = data;
    }

    void Players::set_color(string data)
    {
        this->players[index_of_players].color = data;
    }

    void Players::set_conquer_cities_number(int index)
    {
        this->conquer_cities_number[index] = conquer_cities_number[index] + 1;
    }

    void Players::set_player(int number)
    {
        this->number_of_players = number;
        players.resize(number);
        conquer_cities_number.resize(number);
    }

    void Players::add_index_of_players()
    {
        index_of_players++;
    }

    void Players::add_conquer_cities_number(int number)
    {
        conquer_cities_number[index_of_players] = number;
    }

    ///getter
    string Players::get_name(int index) const
    {
        return players[index].name;
    }

    int Players::get_age(int index) const
    {
        return players[index].age;
    }

    string Players::get_color(int index) const
    {
        return players[index].color;
    }

    int Players::get_conquer_cities_number(int index) const
    {
        return conquer_cities_number[index];
    }

    int Players::get_number_of_player() const
    {
        return number_of_players;
    }

    ///method

    void Players::sort_array()

    {//sort arr by age
        sort(players.begin(),players.end(),[](Identity& temp1,Identity& temp2){
            return temp1.age < temp2.age;
        });
    }

    void Players::defind_players()
    {//taking the name,age and color data by user
        string temp_name;
        int temp_age;
        string temp_color;


        for ( int i = 0; i < number_of_players ; i++)
        {
        system("cls");
        cout << "Enter the name and age and color of each person in the Game please : "<<endl;

        cout << "Enter Name: "<<endl;
        cin >> temp_name;
        cout <<"Enter age: "<<endl;
        cin >> temp_age;
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
            cin >> temp_color;
        }


        Players::set_name(temp_name);
        Players::set_age(temp_age);
        Players::set_color(temp_color);
        index_of_players++;
        }
        Players::sort_array();
    }

    void Players::set_player_correct(){
        menu.enter_players();
        int temp_players;
        cin >> temp_players;
        while(temp_players > 6 || temp_players < 3){
            cout << "The number of Players is not valid!!"<<endl;
            cin >> temp_players;
        }
        Players::set_player(temp_players);
        Players::defind_players();
    }

    bool Players::check_age(int temp_age)
    {//for validation age
        if (temp_age > 120 || temp_age < 1)
        {
            return true;
        }
        return false;
    }

    bool Players::check_color(string &temp_color)
    {//for validation color
        transform(temp_color.begin(),temp_color.end(),temp_color.begin(), ::toupper);
        for (int i =0 ; i < number_of_players ; i++)
        {
            if (players[i].color == temp_color)
            {
                return true;
            }
        }
        return false;
    }
