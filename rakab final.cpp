#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdlib>
using namespace std;
class Menus_of_game{///for setting the menus of game only
public:

    void Start_menu(){
        system("cls");
        cout <<endl << " Welcome to rakab Game!!"<<endl << endl<< "*********************" << endl<<endl;
        cout << "  1-Start the game" << endl << "  2-Menu of opsions" << endl << "  3-Exit" << endl<<endl;
        cout << "*********************"<<endl;
    }
    void Start_War(int number){
        system("cls");
        cout << "The Player"<<number <<" have The War_sign!"<< endl;
        cout << "Please Enter the name of an empty city you want to Attack: "<< endl;
    }
    void Menu_of_opsions(){// print the options and explain the game
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
    void Bahar_Menu(){//explain bahar card
        system("cls");
        cout << "Bahar:After playing this card,the army of players or player that played the highest Yellow card(cards) will increase 3" << endl;
        cout << "more to each card.Remmember that even after battle ends in a city,the Bahar card will remains until Zemestan!!"<< endl;
        cout << "Press x or X to Exit: "<<endl;
        Exit();
    }
    void Zemestan_Menu(){//explain zemestan card
        system("cls");
        cout<< "Zemestan:If a player played this,All the Yellow cards value will be 1!!(This card do not impact the Purple cards)"<<endl<<endl;
        cout << "Press x or X to Exit: "<<endl;
        Exit();
    }
    void Tabl_Zan_Menu(){//explain tabl_zan card
        system("cls");
        cout << "Tabl_zan:if a player use this card in battle,his army strength will boost double!!(but after using this card once,the"<<endl;
        cout <<"army s strength will not increase one more!!)"<<endl;
        cout << "Press x or X to Exit: "<<endl;
        Exit();
    }
    void Shah_dokht_Menu(){//explain shah_dokht card
        system("cls");
        cout << "Shah_dokht:this card increase the army power 10 more (no other cards can effect this card,Even Zemesta!!)"<<endl;
        cout << "Press x or X to Exit: "<<endl;
        Exit();
    }
    void Matarsak_Menu(){//explain matarsak card
        system("cls");
        cout << "Matarsak:if some player want to return his Yellow played card,he can use Matarsak card, but this card only effects"<<endl;
        cout <<"on Yellow cards!"<<endl;
        cout << "Press x or X to Exit: "<<endl;
        Exit();
    }
    void Non_Existed_Card(){
        cout << "ENTER THE CARD: "<<endl;
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
    void Exit(){// Exit the game before start
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
        cout << "Enter the name and age and color of each person in the Game please: "<<endl;
    }

};



class ID_Player{// this class is for taking the ID of a player during the game
public:
     ///constructor
    ID_Player(){}
    ID_Player(int data1,string data2,string data3): age(data1), name(data2), color(data3){}
    ///setter
    void SetageP(int number){
        this->age = number;
    }
    void SetnameP(string ntemp){
        this->name = ntemp;
    }
    void Setcolor(string temp){
        this->color = temp;
    }
    void SetNon_Neighbor_city(){
        this->Non_Neighbor_city = Non_Neighbor_city + 1;
    }

    ///getter
    string Getname(){
        return name;
    }
    int Getage(){
        return age;
    }
    string Getcolor(){
        return color;
    }
    int GetNon_Neighbor_city(){
        return Non_Neighbor_city;
    }
    ///method
    void Defind_players(){// this method is for taking the name and age and color of each player
        int temp1;
        string temp2;
        string temp3;
        system("cls");
        cout << "Enter the name and age and color of each person in the Game please : "<<endl;
        cout << "Enter Name: "<<endl;
        cin >> temp2;
        cout <<"Enter age: "<<endl;
        cin>> temp1;
        cout <<"Enter color: "<<endl;
        cin >> temp3;
        SetnameP(temp2);
        SetageP(temp1);
        Setcolor(temp3);
    }
private:
    int age = 0;
    string name;
    string color;
    int Non_Neighbor_city =0;
};



class War_sign{//this class is for the war_sing in map
public:
     ///constructor
    War_sign(){}
    War_sign(string data): War(data){}
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
        while(temp!="BELLA" && temp!="CALINE" && temp!="ENNA" && temp!="ATELA" && temp!="PLADACI" && temp!="BORGE" && temp!="DIMASE" && temp!="MORINA" && temp!="OLIVADI" && temp!="ROLLO" && temp!="TALMONE"
        && temp!="ARMENTO" && temp!="LIA" && temp!="ELINIA") {
            cout <<"WRONG NAME!!"<<endl;
            cin>>temp;
        }
        SetWar(temp);
    }
private:
    string War;
};





class Peace_sign{//this class is for the peace_sing in map
public:
    ///constructor
    Peace_sign(){}
    Peace_sign(string Player_name): Peace(Player_name){}
    ///setter
    void Setpeace(string city){
        this->Peace = city;
    }
    ///getter
    string Getpeace(){
        return Peace;
    }
    ///method
    void Setsign(){
        cout << "Please Enter the city that you want to no one Attack to it: "<< endl;
        string temp;
        cin >> temp;
        Setpeace(temp);
    }
private:
    string Peace;
};




class Yellow_card{//this class is for setting the soldier(yellow)cards in game
public:
///constructor
    Yellow_card(){}
    Yellow_card(int number): Number(number){}
///getter
    int GetNumber(){
        return Number;
    }
///method
    void Setcard(){
        this->Number = rand() % 10 + 1;
    }

private:
    int Number = 0;

};