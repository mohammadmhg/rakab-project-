#include "Print_game.h"
#include <conio.h>

using namespace std;

    Print_Game::Print_Game(){}

    void Print_Game::showing_map(const int number,const string show_city,const vector <Gameplay> play,const vector <City> cities)
    {
        system("cls");
        bool temp_flag = true;
        for (int i = 0 ; i < number ;i++)
        {
            if (temp_flag)
            {
                cout << "Player"<<i+1<<" Played Cards:\t";
                temp_flag = false;
            }

            for (int j = 0; j < play[i].get_play_cards();j++)
            {
                if (play[i].get_play_cards_data(j) == "Empty")
                {
                    continue;
                }
                cout << play[i].get_play_cards_data(j)<<'\t';
            }
            cout <<endl<<endl;
            temp_flag = true;
        }

        cout << "--------------------------------------------------"<<endl<<endl;
        for(int x = 0; x < number ;x++)
        {
            if(temp_flag)
            {
                cout << "Player" << x+1<<": ";
                temp_flag = false;
            }
            cities[x].show_taken_cities();
            cout << endl<<endl;
            temp_flag = true;
        }
        Print_Game::show_players(number,show_city);
    }

    void Print_Game::show_players(const int number,const string show_city)
    {
        cout << "--------------------------------------------------"<<endl<<endl;
        for(int i = 0; i< number ;i++)
        {
            if(number % 2 == 0)
            {
                if(i % 2 == 0)
                {
                    cout <<endl<<endl<<endl;
                }

                cout << "        Player"<<i + 1<<"      ";
            }

            if(number % 2 != 0)
            {
                if(i == 3)
                {
                    cout <<endl<<endl<<endl;
                }
                if( i == 0)
                {
                    cout << "                        Player"<<i + 1<<endl<<endl<<endl;
                }
                if(i != 0)
                {
                    cout << "  Player"<<i+1 << "                                    ";
                }
            }
        }
        cout <<endl<<endl<<"             The City in War is "<< show_city<<endl;

        cout << "--------------------------------------------------";
    }

    void Print_Game::winner_player(int number)
    {
        system("cls");
        cout << "\tTHE WAR ENDS!!!WINNER IS PLAYER"<<number + 1<<endl<<endl;
        cout <<"<  THANK YOU FOR PAYING>";

    }
    void Print_Game::round_end(int number)
    {
        system("cls");
        cout <<"THIS WAR END HERE!! Player" << number << " Is winner of this battle!!"<<endl<<endl;
        cout << "\tNEW ROUND BEGINS!!FIGHT"<<endl;
        getch();

    }

