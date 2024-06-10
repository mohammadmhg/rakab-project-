#include <iostream>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
class Menu{///for setting the menu of game
public:

    void Start_menu(){
        system("cls");
        cout << " Welcome to rakab Game!!"<<endl << endl<< "\t ***************" << endl<<endl;
        cout << "\t 1-Start the game" << endl << "\t 2-Menu of opsions" << endl << "\t 3-Exit" << endl<<endl;
        cout << "\t ***************"<<endl;
    }
    void Start_War(int &number){
        system("cls");
        cout << "The Player"<<number <<" have The War_sign!"<< endl;
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
class ID{
public:
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
    void Defind_players(){
        int temp1;
        string temp2;
        string temp3;
        system("cls");
        cout << "Enter the name and age and color of each person in the Game please(first enter name second age and third your color): "<<endl;
        cin >> temp2;
        cin>> temp1;
        cin >> temp3;
        SetnameP(temp2);
        SetageP(temp1);
        Setcolor(temp3);
    }

private:
    int age;
    string name;
    string color;
    int Non_Neighbor_city =0;

};
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
class Play_game{
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
    ///methods
protected:
    int Power = 0;
private:
    int shah_dokht =0;
    bool Winner = false;
};
class Player: public Menu,public War_sign,public Army_Power{
    public:
    ///setter

    void SetCards(string a){
        Cards.push_back(a);
    }
    void Played_Card(string name){
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
    ///getter
    bool GetPass_counted(){
        return Pass_counted;
    }
    void Show_Array(){
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
    void Print(int& numbers,int &i,ID &Player_ID){
        system("cls");
        cout <<"We want to show the Player"<<i+1<<" Card(press any key): "<<endl;
        getch();
        cout << "Name: " << Player_ID.Getname() << "\tage: " << Player_ID.Getage() <<"\tColor : " << Player_ID.Getcolor() <<"\tCards: " <<endl;
        Show_Array();
        getch();
        cout << endl<<endl;
    }
    void Print_Saturation(ID& Player_ID){
        cout <<endl<< "Player Turn : " << Player_ID.Getname()<<endl;
        if(Pass){
            cout << "\th Player Passed!!"<<endl;
            getch();
            return;
        }
        cout << "The player available Cards are : " << endl<<endl;
        Show_Array();
        cout << endl<<endl<<"Please Enter the index of The Card That you want to play(Enter 0 if You want to Pass): " <<endl;
        int temp;
        cin >> temp;
        if(temp == 0){
            Pass = true;
            return;
        }
        while(Cards[temp] == "Empty"){
            cout << "The value of Card is Empty!!so there is no value,Please look Better this time and Enter index of Card: "<<endl;
            cin>> temp;
        }
        while(temp <= 0||temp > 10){
            cout <<"Error!!The index of Cards is Wrong!"<<endl;
            cin>> temp;
        }
        CinChosen_Card(temp);
    }
    void Check_Playing_card(){
        if(Pass){
            return;
        }
        cout << "The Played Card is : " << Cards[Getchosen_card() - 1]<<endl;
        getch();
        Played_Card(Cards[Getchosen_card() - 1]);
        Cards[Getchosen_card() - 1] = "Empty";
    }
    void Calculate_Yellow_cards(){
        for(int i = 0 ; i < Play_cards.size() ;i++){
            if(Play_cards[i] != "matarsak"&&Play_cards[i] != "shah_dokht"&&Play_cards[i] != "tabl_zan"&&Play_cards[i] != "bahar"&&Play_cards[i] !="zemestan"&&Play_cards[i] != "Empty"){
                Army_Power::Power += stoi(Play_cards[i]);
            }
        }
    }
    void Calculate_Purple_cards(){
        bool Tabl_zan = false;
        for(int i = 0; i < Play_cards.size() ;i++){
            if(Play_cards[i] == "tabl_zan" && Tabl_zan == false){
                Tabl_zan = true;
                Army_Power::Power *= 2;
            }
            if(Play_cards[i] == "shah_dokht"){
                Army_Power::SetShah_dokht(10);
            }
        }
        Army_Power::Power += Getshah_dokht();
    }
    void Matarsak(){
        cout << "You select matarsak! Your Played cards are: "<<endl;
        for(int i =0 ;i < Play_cards.size() ; i++){
            cout << Play_cards[i] << '\t';
        }
        cout<<endl << "Please Enter the Value of The soldier Card you Want to Put Back:(only inter Value of card if there is no soldier card Enter 0)"<<endl;
        string temp;
        cin>> temp;
        while(temp != "0"&&temp != "1"&&temp !="2"&&temp != "3"&&temp != "4"&&temp != "5"&&temp != "6"&&temp != "7"&&temp != "8"&&temp != "9"&&temp != "10"){
            cout <<"I SAID ONLY SOLDIERS FOR GOD SAKEEEE!!"<<endl;
            cin>> temp;
        }
        if(temp == "0"){
            return;
        }
        if(temp != "0" && Play_cards.size() == 1){
            cout << "I SAID PLAY 0 IF THERE IS NO CARD GENIUS!!"<<endl;
            getch();
            return;
        }
        while(stoi(temp) < 1 || stoi(temp) > 10){
            cout <<"Error!!you Entered The wrong Value GENIUS!"<< endl;
            cin>> temp;
        }
        for(int i =0 ;i < Play_cards.size() ; i++){
            if(Play_cards[i] == temp){
                Play_cards[i] = "Empty";
                SetCards(temp);
            }
        }
    }
    void SetBiggest_Card(string &Biggest_Card){
        for(int i = 0; i < Play_cards.size() ;i++){
            if(Play_cards[i] != "matarsak"&&Play_cards[i] != "shah_dokht"&&Play_cards[i] != "tabl_zan"&&Play_cards[i] != "bahar"&&Play_cards[i] !="zemestan"&&Play_cards[i] != "Empty"){
                if( Play_cards[i] > Biggest_Card){
                    Biggest_Card = Play_cards[i];
                }
            }
        }
    }
    void Setbahar(string &Biggest_Card){
        for(int i = 0; i < Play_cards.size() ;i++){
            if(Play_cards[i] != "matarsak"&&Play_cards[i] != "shah_dokht"&&Play_cards[i] != "tabl_zan"&&Play_cards[i] != "bahar"&&Play_cards[i] !="zemestan"&&Play_cards[i] != "Empty"){
                if(Biggest_Card == Play_cards[i]){
                    Army_Power::Power += 3;
                }
            }
        }
    }
    void Setzemestan(){
        for(int i = 0 ; i < Play_cards.size();i++){
            if(Play_cards[i] != "matarsak"&&Play_cards[i] != "shah_dokht"&&Play_cards[i] != "tabl_zan"&&Play_cards[i] != "bahar"&&Play_cards[i] !="zemestan"&&Play_cards[i] != "Empty"){
                Army_Power::Power = (Army_Power::Power + 1) - stoi(Play_cards[i]);
            }
        }
    }

protected:
    vector <string> Cards;
    vector <string> Play_cards;
    bool Is_zemestan = false;
    bool Is_bahar = false;
    bool Pass = false;
    bool Pass_counted = false;

};
void Sort_Array(vector <ID>&Player_ID){
        sort(Player_ID.begin(),Player_ID.end(),[](ID& temp1,ID& temp2){
            return temp1.Getage() < temp2.Getage();
        });
}
class Print_Map{
public:
    void Map(int &number,string &city,vector<Player> &Play,vector <vector<string>> &Taken_citys){
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
        bool Cflag = true;
        for(int i = 0; i < number;i++){
            for(int j = 0; j < 5 ;j++){
                if(Cflag){
                    cout << "Player" << i+1<<": ";
                    Cflag = false;
                }
                cout << Taken_citys[i][j]<<" ";
            }
            cout << endl<<endl;
            Cflag = true;
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
        cout <<endl<<endl<<"             The City in War is "<< city<<endl;
        cout << "--------------------------------------------------";
    }
    void Win(int &number){
        system("cls");
        cout << "\tTHE WAR ENDS!!!WINNER IS PLAYER"<<number + 1<<endl;
        cout <<"<THANK YOU FOR PAYING>";

    }
    void Round_ends(int &number){
        system("cls");
        cout <<"THIS WAR END HERE!! Player" << number<< " Is winner of this battle!!"<<endl;
        getch();

    }
};
class Yellow_card{
public:
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
class Purple_card{
public:
    ///getter
    string GetnamePurple(){
        return nameP;
    }
    ///methods
    void SetPurple_card(int &i,int Shuffle){
        srand(time(0));
        vector <string> Cards = {"matarsak","shah_dokht","tabl_zan","matarsak","matarsak","bahar","zemestan","matarsak","tabl_zan","matarsak","matarsak","shah_dokht","tabl_zan","bahar",
        "matarsak","matarsak","matarsak","shah_dokht","matarsak","tabl_zan","bahar","zemestan","matarsak","matarsak","tabl_zan","matarsak","tabl_zan","zemestan","matarsak","matarsak"
        ,"matarsak"};
        Shuffle_Cards(Cards,Shuffle);
        nameP = Cards[i];
    }
    void Shuffle_Cards(vector <string> &Cards,int &Shuffle){
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
class Citys{
public:
    ///method
    bool Check_Takken_citys(vector <vector<string>> &city,string &War_city){
        for(int i = 0 ; i < city.size() ;i++){
            for(int j = 0; j < city[0].size() ;j++){
                if(city[i][j] == War_city){
                    return true;
                }
            }
        }
    return false;
    }
    void Wrong_city(){
        cout << "The city that you choose Has been taken Before!!"<<endl<<"PLEASE ENTER A NAME OF (EMPTY) CITY :("<<endl;
    }
    bool SetMapcitys(vector<string> &city){
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
        for(int i = 0; i< city.size();i++){
            auto name = Mapcitys.find(city[i]);
            if(name != Mapcitys.end()){
                for(vector<string>::const_iterator Neighbor = name->second.begin(); Neighbor != name->second.end();Neighbor++){
                    for(int k = 0 ; k < city.size();k++){
                        if(*Neighbor == city[k]){
                            Adjacent++;
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
protected:
    unordered_map<string, vector<string>> Mapcitys;
};

class Peace_sign{
public:
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
        cout << "Please Enter the city you want to no one Attack to it: "<< endl;
        string temp;
        cin >> temp;
        Setpeace(temp);
    }
private:
    string Peace;
};

int main(){
    Menu user;
    bool flag = user.Action();
    if(!flag){
        user.End();
        return 0;
    }
    int Most_powerful = 0;
    int First_Attacker = 1;
    int Shuffle = rand() % 5 + 1;
    string Biggest_card = "0";
    Game play;
    Citys C;
    user.Enter_players();
    play.SetUsers_player();
    int tempP = play.GetPlayer();
    vector <ID> Player_ID(tempP);
    vector <vector<string>> Taken_citys;
    Taken_citys.resize(tempP,vector<string>(5));
    for(int i = 0; i < tempP; i++){
        Player_ID[i].Defind_players();
    }
    Sort_Array(Player_ID);
    string City_in_War;//name of the city which is in war
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
    bool end_of_game = false;// for adjacent
    bool bahar_season = false;
    bool zemestan_season = false;
    int Pass_members =0;
    Print_Map game_map;

    while(!end_of_game){
        vector <Player> Pplay(tempP);
        for(int i = 0; i < tempP; i++){
            Player b;
            Pplay.push_back(b);
        }
        for(int i = 0;i < tempP ;i++){///setting cards in random way
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
        for(int i = 0 ;i < tempP;i++){
            Pplay[i].Print(tempP,i,Player_ID[i]);
        }
        int Players_index = First_Attacker;/// the first_attacker is index of first person who start the game so to continue in order we set Players_index and use++ in"for"
        user.Start_War(First_Attacker);
        Pplay[First_Attacker - 1].SetWar_sing();
        City_in_War = Pplay[First_Attacker - 1].GetWar();

        while(C.Check_Takken_citys(Taken_citys,City_in_War)){//to check that player can remember at least a name of a EMPTY city |:
            C.Wrong_city();
            Pplay[First_Attacker - 1].SetWar_sing();
            City_in_War = Pplay[First_Attacker - 1].GetWar();
        }
        game_map.Map(tempP,City_in_War,Pplay,Taken_citys);// the player who has the war_sign will start the war
        Pplay[First_Attacker - 1].Print_Saturation(Player_ID[First_Attacker - 1]);
        Pplay[First_Attacker - 1].Check_Playing_card();
        if(Pplay[First_Attacker - 1].GetPass() == true && Pplay[First_Attacker - 1].GetPass_counted() == false){
                Pplay[First_Attacker - 1].SetPass_counted(true);
                Pass_members++;
        }
        while(!winner){
            for(Players_index ; Players_index < tempP; Players_index++){
                game_map.Map(tempP,City_in_War,Pplay,Taken_citys);
                Pplay[Players_index].Print_Saturation(Player_ID[Players_index]);
                Pplay[Players_index].Check_Playing_card();
                if(Pplay[Players_index].GetPass() == true && Pplay[Players_index].GetPass_counted() == false){
                    Pplay[Players_index].SetPass_counted(true);
                    Pass_members++;
                }
                if(Pplay[Players_index].Getbahar() != false && Pplay[Players_index].Getzemestan() != false){//to check every sing time that who has been played bahar or zamestan
                    if(Pplay[Players_index].Getbahar()){
                        bahar_season = true;
                        zemestan_season = false;
                    }
                    else{
                        bahar_season = false;
                        zemestan_season = true;
                    }
                }
            }
            Players_index = 0;//to restart
            if(Pass_members >= tempP){//to end the round on fight in a city
                Pass_members= 0;
                winner = true;
                break;
            }
        }//winner while
        bool temp_Flag = true;
        for(int i =0; i< tempP ;i++){
            if(bahar_season == false && zemestan_season == false){
                break;
            }
            else{
                if(bahar_season){
                    if(temp_Flag){
                        for(int i =0; i< tempP ;i++){
                            Pplay[i].SetBiggest_Card(Biggest_card);
                        }
                    }
                    temp_Flag = false;
                    Pplay[i].Calculate_Yellow_cards();
                    Pplay[i].Calculate_Purple_cards();
                    Pplay[i].Setbahar(Biggest_card);
                }
                if(zemestan_season){
                    Pplay[i].Calculate_Yellow_cards();
                    Pplay[i].Setzemestan();
                    Pplay[i].Calculate_Purple_cards();

                }
            }
        }
        system("cls");
        for(int i =0 ; i< tempP ; i++){
            if(Pplay[i].GetPower() > Most_powerful){
                Most_powerful = Pplay[i].GetPower();
                First_Attacker = i + 1;
                Pplay[i].SetWinner(true);
            }
        }
        if(Pplay[First_Attacker - 1].GetWinner()){
            game_map.Round_ends(First_Attacker);
            Player_ID[First_Attacker - 1].SetNon_Neighbor_city();
            Taken_citys[First_Attacker - 1].push_back(City_in_War);
        }
        for(int k = 0; k < tempP;k++){
            if(Player_ID[k].GetNon_Neighbor_city() >= 3){
                if(C.SetMapcitys(Taken_citys[k])){//end of game by adjacent
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
        bahar_season = false;
        zemestan_season = false;
        Biggest_card = "0";

    }//end_of_game while


return 0;
}
