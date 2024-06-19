#include <iostream>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
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
        cout << "Shir_dokht:this card increase the army power 10 more (no other cards can effect this card,Even Zemesta!!)"<<endl;
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
        cout << "ENTER THE CRAD PLEASE: "<<endl;
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

class Players{// this class is for taking the ID of a player during the game
public:
    ///constructor
    Players(){}
    Players(int data1,string data2,string data3): age(data1), name(data2), color(data3){}
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
    void SetPlayer(int number){//this method is for taking the number of players
        if(number > 6 || number < 3){
            players = 0;
        }
        this->players = number;
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
    int GetPlayer(){
        return players;
    }
    ///method
    void Sort_Array(vector <Players>&Player_ID){//sort players by age
        sort(Player_ID.begin(),Player_ID.end(),[](Players& temp1,Players& temp2){
            return temp1.Getage() < temp2.Getage();
        });
    }
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
    void SetUsers_player(){//checking that players are in right numbers
        int temp_players;
        cin >> temp_players;
        while(temp_players > 6 || temp_players < 3){
            cout << "Error!!"<<endl;
            cin >> temp_players;
        }
        SetPlayer(temp_players);
    }

private:
    int age = 0;
    string name;
    string color;
    int Non_Neighbor_city =0;
    int players = 0;

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
        while(temp!="BELLA"&&temp!="CALINE"&&temp!="ENNA"&&temp!="ATELA"&&temp!="PLADACI"&&temp!="BORGE"&&temp!="DIMASE"&&temp!="MORINA"&&temp!="OLIVADI"&&temp!="ROLLO"&&temp!="TALMONE"
        &&temp!="ARMENTO"&&temp!="LIA"&&temp!="ELINIA"){
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

class Purple_card{//this class is for setting the spacial(purple)cards in game
public:
    ///constructor
    Purple_card(){}
    Purple_card(string name): nameP(name){}
    ///getter
    string GetnamePurple(){
        return nameP;
    }
    ///methods
    void SetPurple_card(int &i,int Shuffle){
        srand(time(0));
        vector <string> Cards = {"matarsak","shir_dokht","tabl_zan","matarsak","matarsak","bahar","zemestan","matarsak","tabl_zan","matarsak","matarsak","shir_dokht","tabl_zan","bahar",
        "matarsak","matarsak","matarsak","shir_dokht","matarsak","tabl_zan","bahar","zemestan","matarsak","matarsak","tabl_zan","matarsak","tabl_zan","zemestan","matarsak","matarsak"
        ,"matarsak"};
        Shuffle_Cards(Cards,Shuffle);
        nameP = Cards[i];
    }
    void Shuffle_Cards(vector <string> &Cards,int &Shuffle){//shuffle the cards with random number
        if(Shuffle > 30){
            Shuffle = rand() % 5 + 1;
        }
        for(int i = 0; i< Cards.size() ;i++){
            swap(Cards[i],Cards[Shuffle]);
        }

    }
private:
    string nameP;

};

class Gameplay: public Menus_of_game{///this class is for Gameplay during each round and setting Cards and Played Cards for User and Controlling every thing related to Cards in a round
    public:
    ///constructor
    Gameplay(){}
    Gameplay(string card,string played_card){
        SetCards(card);
        Played_Card(played_card);
    }
    ///setter
    void Sethelp(bool temp){
        this->Getting_help = temp;
    }
    void SetFirst_Attacker(int number){
        this->First_Attacker = number + 1;
    }
    void SetCards(string a){
        Cards.push_back(a);
    }
    void Played_Card(string name){//setting the paled card and check the season
        Play_cards.push_back(name);
        if(name == "bahar"){
            Is_bahar = true;
            Is_zemestan = false;
        }
        if(name == "zemestan"){
            Is_bahar = false;
            Is_zemestan = true;
        }
        if(name == "matarsak"){
            Matarsak();
        }
    }
    void SetPass_counted(bool temp){
        this->Pass_counted = temp;
    }
    void Set_Seasons(){
        Is_bahar = false;
        Is_zemestan = false;
    }
    void SetPassed_Players(){
        this->Passed_Players = Passed_Players + 1;
    }
    void ReSetPassed_Players(){
        this->Passed_Players = 0;
    }
    ///getter
    int GetPassed_Players(){
        return Passed_Players;
    }
    bool Gethelp(){
        return Getting_help;
    }
    int GetFirst_Attacker(){
        return First_Attacker;
    }
    bool GetPass_counted(){
        return Pass_counted;
    }
    void Show_Array(){//showing the unplaed cards
        for(int i = 0 ; i < Cards.size(); i++){
            cout << Cards[i] << '\t';
        }
    }
    bool Getbahar(){
        return Is_bahar;
    }
    bool Getzemestan(){
        return Is_zemestan;
    }
    int GetPlay_cards(){
        return Play_cards.size();
    }
    string GetPlay_cards_data(int &i){
        return Play_cards[i];
    }
    bool GetPass(){
        return Pass;
    }
    ///method
    void Print(int numbers,int &i,Players &Player_ID){//print the cards for each player
        system("cls");
        cout <<"We want to show the Player"<<i+1<<" Card(press any key): "<<endl;
        getch();
        cout << "Name: " << Player_ID.Getname() << "\tage: " << Player_ID.Getage() <<"\tColor : " << Player_ID.Getcolor() <<"\tCards: " <<endl;
        Show_Array();
        getch();
        cout << endl<<endl;
    }
    void Print_Saturation(Players& Player_ID){//print the available cards for player and taking his input
        cout <<endl<< "Player Turn : " << Player_ID.Getname()<<endl;
        if(Pass){
            cout << "\t Player has Passed the round!!"<<endl;
            getch();
            return;
        }
        cout << "The player available Cards are : " << endl<<endl;
        Show_Array();
        cout << endl<<endl<<"Please Enter the value of The Card That you want to play(Enter 0 or say pass if You want to Pass): " <<endl;
        string temp;
        getline(cin,temp);
        while(Check_Exist_Card(temp)==true&&temp!="help"&&temp!="pass"&&temp!="matarsak"&&temp!="shir_dokht"&&temp!="bahar"&&temp!="zemestan"&&temp!="tabl_zan"
              &&temp!="help bahar"&&temp!="help matarsak"&&temp!="help shir_dokht"&&temp!="help zemestan"&&temp!="help tabl_zan"&&temp!="0"){
            Non_Existed_Card();
            getline(cin,temp);
        }
        if(temp == "pass"|| temp == "0"){
            Pass = true;
            return;
        }
        if(temp == "help"){
            Sethelp(true);
            Menu_of_opsions();
            return;
        }
        if(temp=="help bahar"||temp=="help matarsak"||temp=="help shir_dokht"||temp=="help zemestan"||temp=="help tabl_zan"){
            Sethelp(true);
            Cards_helping_Menus(temp);
            return;
        }

        CinChosen_Card(temp);
        cout << "The Played Card is : " << Cards[Getchosen_card() - 1]<<endl;
        getch();
        Played_Card(Cards[Getchosen_card() - 1]);
        Cards[Getchosen_card() - 1] = "Empty";
    }

    void Matarsak(){//handle the matarsak card(matarsak card only impact during the game and after the round ends is useless so we handle it here)
        cout << "You select matarsak! Your Played cards are: "<<endl;
        for(int i =0 ;i < Play_cards.size() ; i++){
            cout << Play_cards[i] << '\t';
        }
        cout<<endl << "Please Enter the Value of The soldier Card you Want to Put Back:(only inter Value of card if there is no soldier card Enter 0)"<<endl;
        string temp;
        cin>> temp;
        while(temp != "0"&&temp != "1"&&temp !="2"&&temp != "3"&&temp != "4"&&temp != "5"&&temp != "6"&&temp != "7"&&temp != "8"&&temp != "9"&&temp != "10"){
            cout <<"ONLY SOLDIERS PLEASE!!"<<endl;
            cin>> temp;
        }
        if(temp == "0"){
            return;
        }
        if(temp != "0" && Play_cards.size() == 1){
            cout << "PLAY 0 IF THERE IS NO CARD PLEASE!!"<<endl;
            getch();
            return;
        }
        while(stoi(temp) < 1 || stoi(temp) > 10){
            cout <<"Error!!you Entered The wrong Value!!"<< endl;
            cin>> temp;
        }
        for(int i =0 ;i < Play_cards.size() ; i++){
            if(Play_cards[i] == temp){
                Play_cards[i] = "Empty";
                SetCards(temp);
                break;
            }
        }
    }

protected:
    vector <string> Cards;
    vector <string> Play_cards;
private:
    void Cards_helping_Menus(string &temp){//check the input to show help menu
        if(temp == "help bahar"){
            Bahar_Menu();
            return;
        }
        if(temp=="help matarsak"){
            Matarsak_Menu();
            return;
        }
        if(temp == "help zemestan"){
            Zemestan_Menu();
            return;
        }
        if(temp == "help tabl_zan"){
            Tabl_Zan_Menu();
            return;
        }
        if(temp == "help shir_dokht"){
            Shah_dokht_Menu();
            return;
        }

    }
    void CinChosen_Card(string temp){//setting the index of chosen card by player
        for(int i =0 ; i < Cards.size();i++){
            if(Cards[i] == temp){
                Chosen_card = i+1;
                break;
            }
        }
    }
    int Getchosen_card(){
        return Chosen_card;
    }
    bool Check_Exist_Card(string Chosen){//check that input from player is correct
        for(int i = 0 ; i < Cards.size() ; i++){
            if(Chosen == Cards[i]){
                return false;
            }
        }
        return true;
    }
    int Chosen_card = 0;
    bool Getting_help = false;
    static bool Is_zemestan;
    static bool Is_bahar;
    static int First_Attacker;
    static int Passed_Players;
    bool Pass = false;
    bool Pass_counted = false;
};
bool Gameplay::Is_bahar;
bool Gameplay::Is_zemestan;
int Gameplay::First_Attacker;
int Gameplay::Passed_Players;

class Control_Cards:public Gameplay{///this class this for controlling the power of each player army(include normal and some spacial cards related to Army power)
public:
    ///constructor
    Control_Cards(){}
    Control_Cards(string name,string data,int power,bool winner):Gameplay(name,data), Power(power), Winner(winner){}
    ///setter
    void SetBiggest_Card_Played(){
        Biggest_Played_Card = 0;
    }
    void SetPower(int& number){
        this->Power += number;
    }

    void SetWinner(bool flag){
        this->Winner = flag;
    }
    void SetMost_Powerful(int number){
        this->Most_Powerful = number;
    }
    void ReSetMost_Powerful(){
        Most_Powerful = 0;
    }
    ///getter

    int GetPower(){
        return Power;
    }
    int GetMost_Powerful(){
        return Most_Powerful;
    }

    bool GetWinner(){
        return Winner;
    }
    int GetBiggest_Card(){
        return Biggest_Played_Card;
    }
    ///methods
    void Calculate_Yellow_cards(){//set power by yellow cards
        for(int i = 0 ; i < Play_cards.size() ;i++){
            if(Play_cards[i] != "matarsak"&&Play_cards[i] != "shir_dokht"&&Play_cards[i] != "tabl_zan"&&Play_cards[i] != "bahar"&&Play_cards[i] !="zemestan"&&Play_cards[i] != "Empty"){
                Power =Power + stoi(Play_cards[i]);
            }
        }
    }
    void Calculate_Purple_cards(){//set power by purple cards
        bool Tabl_zan = false;
        for(int i = 0; i < Play_cards.size() ;i++){
            if(Play_cards[i] == "tabl_zan" && Tabl_zan == false){
                Tabl_zan = true;
                Power = Power * 2;
            }
            if(Play_cards[i] == "shir_dokht"){
                Power = Power + 10;
            }
        }

    }

    void Setbahar(){//set power when is bahar
        for(int i = 0; i < Play_cards.size() ;i++){
            if(Play_cards[i] != "matarsak"&&Play_cards[i] != "shir_dokht"&&Play_cards[i] != "tabl_zan"&&Play_cards[i] != "bahar"&&Play_cards[i] !="zemestan"&&Play_cards[i] != "Empty"){
                if(Biggest_Played_Card <= stoi( Play_cards[i] ) ){
                    Power = Power + 3;
                }
            }
        }
    }
    void SetBiggest_Card(){//set the biggest played soldier card in game
        for(int i = 0; i < Play_cards.size() ;i++){
            if(Play_cards[i] != "matarsak"&&Play_cards[i] != "shir_dokht"&&Play_cards[i] != "tabl_zan"&&Play_cards[i] != "bahar"&&Play_cards[i] !="zemestan"&&Play_cards[i] != "Empty"){
                if( stoi( Play_cards[i] ) > Biggest_Played_Card){
                    Biggest_Played_Card = stoi( Play_cards[i] );
                }
            }
        }
    }
    void Setzemestan(){//set power when is zemestan
        for(int i = 0 ; i < Play_cards.size();i++){
            if(Play_cards[i] != "matarsak"&&Play_cards[i] != "shir_dokht"&&Play_cards[i] != "tabl_zan"&&Play_cards[i] != "bahar"&&Play_cards[i] !="zemestan"&&Play_cards[i] != "Empty"){
                Power = (Power + 1) - ( stoi(Play_cards[i]) );
            }
        }
    }

private:
    bool Winner = false;
    int Power = 0;
    static int Biggest_Played_Card;
    static int Most_Powerful;
};
int Control_Cards::Biggest_Played_Card;
int Control_Cards::Most_Powerful;


class Citys{//to control the Map of game and the citys(include every methods and datas needed for controlling the citys)
public:
    ///setter
    void Setcitys(string name){
        Taken_city.push_back(name);
    }
    ///getter
    void Getcitys(){//print the taken citys by a player
        for(int i = 0; i < Taken_city.size();i++){
            cout << Taken_city[i]<<" ";
        }
    }
    ///method
    bool Check_Takken_citys(string War_city){//check that player do not enter a name of a taken city

        for(int i = 0 ; i < Taken_city.size() ;i++){
            if(Taken_city[i] == War_city){
                return true;
            }
        }
    return false;
    }
    void Wrong_city(){//check that player do not enter a name of a taken city
        cout << "The city that you choose Has been taken Before!!"<<endl<<"PLEASE ENTER A NAME OF (EMPTY) CITY :("<<endl;
    }
    bool SetMapcitys(){//check adjacent for the taken citys by a player
        unordered_map<string, vector<string>> Mapcitys;
        Mapcitys = {
        {"BELLA", {"CALINE","PLADACI","BORGE"}},
        {"CALINE", {"BELLA","PLADACI","BORGE","ENNA","ATELA"}},
        {"ENNA", {"CALINE","ATELA","BORGE","DIMASE"}},
        {"ATELA", {"CALINE","ENNA","DIMASE"}},
        {"PLADACI", {"BORGE","MORINA","ROLLO"}},
        {"BORGE", {"BELLA","CALINE","ENNA","DIMASE","PLADACI","DIMASE","MORINA","OLIVADI"}},
        {"DIMASE", {"ENNA","ATELA","BORGE","OLIVADI"}},
        {"MORINA", {"PLADACI","BORGE","OLIVADI","ROLLO","TALMONE","ARMENTO"}},
        {"OLIVADI", {"BORGE","DIMASE","MORINA","ARMENTO","LIA"}},
        {"ROLLO", {"PLADACI","MORINA","TALMONE","ELINIA"}},
        {"TALMONE", {"MORINA","ROLLO","ARMENTO","ELINIA"}},
        {"ARMENTO", {"MORINA","OLIVADI","LIA","TALMONE"}},
        {"LIA", {"OLIVADI","ARMENTO"}},
        {"ELINIA", {"ROLLO","TALMONE"}}
        };
        int Adjacent = 0;
        for(int i = 0; i< Taken_city.size();i++){
            auto name = Mapcitys.find(Taken_city[i]);
            Adjacent = 0;
            if(name != Mapcitys.end()){
                for(vector<string>::const_iterator Neighbor = name->second.begin(); Neighbor != name->second.end();Neighbor++){
                    for(int k = i + 1 ; k < Taken_city.size();k++){
                        if(*Neighbor == Taken_city[k]){
                            string Stemp = Taken_city[k];
                            Check_second_adjacent(Adjacent,k,Mapcitys,Stemp,i);
                            if(Adjacent >= 2){
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }


private:
    vector <string>Taken_city;

    void Check_second_adjacent(int &Adjacent,int k,unordered_map<string, vector<string>> Mapcitys,string Stemp,int i){
        for(int z = k + 1; z < Taken_city.size() ;z++){
            auto name1 = Mapcitys.find(Taken_city[z]);
            if(name1 != Mapcitys.end()){
                for(vector<string>::const_iterator Neighbor2 = name1->second.begin(); Neighbor2 != name1->second.end();Neighbor2++){
                    for(int x = 0 ; x < Taken_city.size();x++){
                        if(Taken_city[x] == *Neighbor2){
                            Adjacent++;
                        }
                    }
                }
            }
        }
    }

};
class Print_Map_of_game{//print the map of game in each round and show the informations that are needed
public:
    void Map(int number,string City,vector<Control_Cards> &Play,vector<Citys> citys){
        system("cls");
        bool Pflag = true;
        for(int i = 0 ; i < number ;i++){
            if(Pflag){
                cout << "Player"<<i+1<<" Played Cards:\t";
                Pflag = false;
            }
            for(int j = 0; j < Play[i].GetPlay_cards();j++){
                if(Play[i].GetPlay_cards_data(j) == "Empty"){
                    continue;
                }
                cout << Play[i].GetPlay_cards_data(j)<<'\t';
            }
            cout <<endl<<endl;
            Pflag = true;
        }
        cout << "--------------------------------------------------"<<endl<<endl;
        for(int x = 0; x < citys.size();x++){
            if(Pflag){
                cout << "Player" << x+1<<": ";
                Pflag = false;
            }
            citys[x].Getcitys();
            cout << endl<<endl;
            Pflag = true;
        }
        cout << "--------------------------------------------------"<<endl<<endl;
        for(int i = 0; i< number ;i++){
            if(number % 2 == 0){
                if(i % 2 == 0){
                    cout <<endl<<endl<<endl;
                }
                cout << "        Player"<<i + 1<<"      ";
            }
            if(number % 2 != 0){
                if(i == 3){
                    cout <<endl<<endl<<endl;
                }
                if( i == 0){
                    cout << "                        Player"<<i + 1<<endl<<endl<<endl;
                }
                if(i != 0){
                    cout << "  Player"<<i+1 << "                                    ";
                }
            }
        }
        cout <<endl<<endl<<"             The City in War is "<< City<<endl;
        cout << "--------------------------------------------------";
    }
    void Win(int &number){
        system("cls");
        cout << "\tTHE WAR ENDS!!!WINNER IS PLAYER"<<number + 1<<endl<<endl;
        cout <<"<THANK YOU FOR PAYING>";

    }
    void Round_ends(int number){
        system("cls");
        cout <<"THIS WAR END HERE!! Player" << number<< " Is winner of this battle!!"<<endl<<endl;
        cout << "\tNEW ROUND BEGINS!!FIGHT"<<endl;
        getch();

    }
};


int main(){
    Menus_of_game user;
    bool flag = user.Action();
    if(!flag){
        user.End();
        return 0;
    }
    War_sign Warzone;
    Control_Cards First_player;
    int Shuffle = rand() % 5 + 1;
    Players play;///to set the number of Players
    user.Enter_players();
    play.SetUsers_player();
    vector <Players> Player_ID(play.GetPlayer());
    for(int i = 0; i < play.GetPlayer(); i++){
        Player_ID[i].Defind_players();
    }
    vector <Citys> City;
    for(int i = 0 ; i< play.GetPlayer();i++){
        Citys x;
        City.push_back(x);
    }
    play.Sort_Array(Player_ID);//sort players by age
    srand(time(0));
    vector <Yellow_card> Yellow(58);
    for(int i = 0; i < 58; i++){
        Yellow_card a;
        Yellow.push_back(a);
    }
    for(int i = 0; i < 58; i++){
        Yellow[i].Setcard();
    }
    vector <Purple_card> Purple(31);
    for(int i = 0 ; i < 31 ; i++){
        Purple_card c;
        Purple.push_back(c);
    }
    for(int i = 0 ; i < 31 ; i++){
        Purple[i].SetPurple_card(i,Shuffle);
    }

    bool winner = false;
    bool end_of_game = false;
    Print_Map_of_game game_map;
    First_player.SetFirst_Attacker(0);//setting the first Person who star the game by age
    while(!end_of_game){
        vector <Control_Cards> Pplay(play.GetPlayer());
        for(int i = 0; i < play.GetPlayer(); i++){
            Control_Cards b;
            Pplay.push_back(b);
        }
        for(int i = 0;i < play.GetPlayer() ;i++){///setting cards in random way
            for(int j = 0; j < 10; j++){
                int R = rand() % 28 + 1;
                if(R % 2 == 0){
                  int n = Yellow[R].GetNumber();
                  string tempS  = to_string(n);
                  Pplay[i].SetCards(tempS);
                }
                else{
                    string tempS2  = Purple[R].GetnamePurple();
                    Pplay[i].SetCards(tempS2);
                }
            }
        }
        for(int i = 0 ;i < play.GetPlayer();i++){
            Pplay[i].Print(play.GetPlayer(),i,Player_ID[i]);///this function is only for print
        }
        int Players_index = First_player.GetFirst_Attacker() - 1;///the first_attacker is index of first person who start the game so to continue in order we set Players_index and use it for++ in"for" only
        user.Start_War(First_player.GetFirst_Attacker());
        Warzone.SetWar_sing();
        bool Check_City = true;
        while(Check_City){//to check that player can Enter a name of a EMPTY city
            for(int i = 0; i < play.GetPlayer();i++){
                while(City[i].Check_Takken_citys(Warzone.GetWar()) ){
                    City[i].Wrong_city();
                    Warzone.SetWar_sing();
                }
            }
            Check_City = false;
        }

        while(!winner){
            for(Players_index ; Players_index < play.GetPlayer(); Players_index++){
                game_map.Map(play.GetPlayer(),Warzone.GetWar(),Pplay,City);
                Pplay[Players_index].Print_Saturation(Player_ID[Players_index]);
                Pplay[Players_index].SetBiggest_Card();
                if(Pplay[Players_index].GetPass() == true && Pplay[Players_index].GetPass_counted() == false){
                    Pplay[Players_index].SetPass_counted(true);//to sure that we already count this pass
                    First_player.SetPassed_Players();
                }
                if(Pplay[Players_index].Gethelp()){
                    Pplay[Players_index].Sethelp(false);
                    Players_index--;
                }
            }
            Players_index = 0;//to restart
            if(First_player.GetPassed_Players() >= play.GetPlayer()){//to end the round on fight in a city
                First_player.ReSetPassed_Players();
                winner = true;
                break;
            }
        }//winner while

        for(int i =0; i< play.GetPlayer() ;i++){
            if(Pplay[i].Getbahar() ){
                Pplay[i].Calculate_Yellow_cards();
                Pplay[i].Calculate_Purple_cards();
                Pplay[i].Setbahar();
            }
            else if(Pplay[i].Getzemestan() ){
                Pplay[i].Calculate_Yellow_cards();
                Pplay[i].Setzemestan();
                Pplay[i].Calculate_Purple_cards();
            }
            else{
                Pplay[i].Calculate_Yellow_cards();
                Pplay[i].Calculate_Purple_cards();
            }
        }

        system("cls");
        for(int i =0 ; i< play.GetPlayer() ; i++){
            if(Pplay[i].GetPower() > Pplay[i].GetMost_Powerful()){
                int temp = Pplay[i].GetPower();
                Pplay[i].SetMost_Powerful(temp);
                First_player.SetFirst_Attacker(i);
                Pplay[i].SetWinner(true);
            }
        }
        system("cls");
        cout << "Army_power in order from Player1 to Player" <<play.GetPlayer()<<endl;
        for(int i =0 ; i <play.GetPlayer();i++){
            cout << Pplay[i].GetPower()<<"  ";
        }
        getch();
        if(Pplay[First_player.GetFirst_Attacker() - 1].GetWinner()){
            game_map.Round_ends(First_player.GetFirst_Attacker());
            Player_ID[First_player.GetFirst_Attacker() - 1].SetNon_Neighbor_city();
            City[First_player.GetFirst_Attacker() - 1].Setcitys(Warzone.GetWar());
        }


        for(int k = 0; k < play.GetPlayer();k++){
            if(Player_ID[k].GetNon_Neighbor_city() >= 3){
                if(City[k].SetMapcitys()){//end of game by adjacent
                    end_of_game = true;
                    game_map.Win(k);
                    return 0;
                }
                if(Player_ID[k].GetNon_Neighbor_city() >= 5){//end of game by taking the citys
                    end_of_game = true;
                    game_map.Win(k);
                    return 0;
                }
            }
        }
        winner = false;
        Pplay[0].ReSetMost_Powerful();
        Pplay[0].Set_Seasons();
        Pplay[0].SetBiggest_Card();
    }//end_of_game while

return 0;
}
