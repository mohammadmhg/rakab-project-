#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
class Menu{///for setting the menu of game
public:
    void Start_menu(){
            system("cls");
            cout << " Welcome to rakab Game!!"<<endl << endl<< "\t ***************" << endl<<endl;
            cout << "\t 1-Start the game" << endl << "\t 2-Menu of opsions" << endl << "\t 3-Exit" << endl<<endl;
            cout << "\t ***************"<<endl;
    }
    void Start_War(){
        cout << "The Player1 have The War_sign!"<< endl;
        cout << "Please Enter the name of an empty city you want to Attack: "<< endl;
    }
    void Menu_of_opsions(){
        system("cls");
        cout << "Welcome to rakab game,Here is information of the rules: "<<endl;
        cout << "There are tow type of card in the game: Yellow(Soldier) and Purple(Spacial):" << endl <<endl;
        cout <<"\t*****************" << endl<<endl;
        cout << "Yellow card: this cards are the soldeir that we use to attack a city to win the war"<<endl << "there are 58 Yellow card in this game that numbered from 1 to 10" << endl;
        cout<<"\t-------------------------"<<endl;
        cout << "When a player has more soldier in the battle,he take over the city and if he take 3 adjacent city or 5 other city,he"<<endl;
        cout <<"wins the game!!" << endl<<endl;
        cout <<"\t*****************" << endl<< endl;
        cout << "Purple cards: there are 52 spacial card in the game that can effect in the result of battle: " << endl;
        cout<<"\t-------------------------"<<endl;
        cout << "Matarsak:if some player want to return his Yellow played card,he can use Matarsak card, but this card only effects"<<endl;
        cout <<"on Yellow cards!"<<endl;
        cout<<"\t-------------------------"<<endl;
        cout << "Tabl_zan:if a player use this card in battle,his army strength will boost double!!(but after using this card once,the"<<endl;
        cout <<"army s strength will not increase one more!!)"<<endl;
        cout<<"\t-------------------------"<<endl;
        cout << "Shah_dokht:this card increase the army power 10 more (no other cards can effect this card,Even Zemesta!!)"<<endl;
        cout<<"\t-------------------------"<<endl;
        cout << "Bahar:After playing this card,the army of players or player that played the highest Yellow card(cards) will increase 3" << endl;
        cout << "more to each card.Remmember that even after battle ends in a city,the Bahar card will remains until Zemestan!!"<< endl;
        cout <<"(the Shah_dokht card dosent count!)"<<endl;
        cout<<"\t-------------------------"<<endl;
        cout<< "Zemestan:If a player played this,All the Yellow cards value will be 1!!(This card do not impact the Purple cards)"<<endl<<endl;
        cout <<"\t*****************" << endl;
        cout << "Press x or X to Exit: "<<endl;
        Exit();
    }
    bool Action(){
        bool flag = true;
        while(flag){
            Start_menu();
            int number;
            cin >> number;
            while(number > 3 || number < 1){
                cin >> number;
            }
            if(number == 1){
                return true;
            }
            if(number == 2){
                Menu_of_opsions();
            }
            if(number == 3){
                return false;
            }

        }
        return true;

    }
    void Exit(){
        char user = getch();
        while(user != 'x' && user != 'X'){
            cout <<"Unknown input!!!try again"<<endl;
            char user = getch();
        }
        system("cls");
    }
    void End(){
        system("cls");
        cout << "\tYou Exited the Game!!";
    }
    void Enter_players(){
        system("cls");
        cout << "Enter the number of players you want to play with:(must be between 3 to 6): "<<endl;
    }
    void Enter_details(){
        system("cls");
        cout << "Enter the name and age and color of each person in the Game please(first enter name second age and third your color): "<<endl;
    }
private:
};



class Game {
public:
    ///setters
    void SetPlayer(int number){
        this->players = number;
    }    
    ///getters
    int GetPlayer(){
        return players;
    }

    ///methods

    void SetUsers_player(){
        int temp_players;
        cin >> temp_players;
        while(temp_players > 6 || temp_players < 3){
            cout << "Error!!"<<endl;
            cin >> temp_players;
        }
        SetPlayer(temp_players);
    }
    
protected:
    int players = 0;
};


istream& operator>>(istream &stream,Game& data){
    int temp;
    stream >> temp;
    data.SetPlayer(temp);
    return stream;
}

class War_sign{
public:
    ///setter
    void SetWar(string city){
        this->War = city;
    }
    ///getter
    string GetWar(){
        return War;
    }
    ///method
    void SetWar_sing(){
        string temp;
        cin>> temp;
        SetWar(temp);
    }
protected:
    string War;
};



class Play_game
{
public:
    ///setter
    void SetChosen_card(int number){
        this->Chosen_card = number;
    }
    ///getter
    int Getchosen_card(){
        return Chosen_card;
    }
    ///method
    void CinChosen_Card(int temp){
        SetChosen_card(temp);
    }

private:
    int Chosen_card = 0;
};



class Army_Power:public Play_game{
public:
///setter
    void SetPower(int& number){
        this->Power += number;
    }
    void SetShah_dokht(int number){
        this->shah_dokht += number;
    }
    void SetWinner(bool flag){
        this->Winner = flag;
    }
    ///getter
    int GetPower(){
        return Power;
    }
    int Getshah_dokht(){
        return shah_dokht;
    }
    bool GetWinner(){
        return Winner;
    }
protected:
    int Power = 0;
private:
    int shah_dokht =0;
    bool Winner = false;
};