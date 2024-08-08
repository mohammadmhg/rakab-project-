#include <iostream>
#include <ctime>
#include <conio.h>
#include "Gameplay.h"
using namespace std;
int Gameplay::empty_hand_players = 0;
int Gameplay::passed_players = 0;
int Gameplay::players_turn = 0;

    ///constructor
    Gameplay::Gameplay(){}
    Gameplay::Gameplay(string card,string played_card)
    {
        Gameplay::set_cards(card);
        Gameplay::set_played_card(played_card);
    }
    ///setter
    void Gameplay::set_players_turn(int number)
    {
        players_turn = number;
    }

    void Gameplay::re_set_empty_hand_players()
    {
        empty_hand_players = 0;
    }

    void Gameplay::set_empty_hand_players(int empty_hand)
    {
        empty_hand_players = empty_hand;
    }

    void Gameplay::set_help(bool help)
    {
        this->getting_help = help;
    }

    void Gameplay::set_cards(string card)
    {
        cards.push_back(card);
    }

    void Gameplay::set_played_card(string card)
    {//setting the paled card and check the season
        play_cards.push_back(card);
        if(card == "bahar"){
            card_data.set_bahar(true);
            card_data.set_zemestan(false);
        }
        if(card == "zemestan"){
            card_data.set_bahar(false);
            card_data.set_zemestan(true);
        }
        if(card == "matarsak"){
            card_data.set_used_matarsak(true);
            Gameplay::matarsak();
        }
    }

    void Gameplay::set_pass(bool passed)
    {
        pass = passed;
    }

    void Gameplay::set_pass_counted(bool pass)
    {
        this->pass_counted = pass;
    }

    void Gameplay::re_set_data()
    {
        passed_players = 0;
    }

    void Gameplay::set_passed_players()
    {
        this->passed_players = passed_players + 1;
    }

    void Gameplay::add_passed_players_number(int number)
    {
        passed_players = number;
    }

    void Gameplay::re_set_pass()
    {
        pass = false;
        pass_counted = false;
        play_cards.clear();
    }

    void Gameplay::add_play_cards(string card)
    {
        play_cards.push_back(card);
    }
    ///getter

    int Gameplay::get_players_turn() const
    {
        return players_turn;
    }

    int Gameplay::get_passed_players() const
    {
        return passed_players;
    }

    bool Gameplay::get_red_card_herkol()const
    {
        return red_card_handel.get_used_herkol();
    }

    bool Gameplay::get_red_card_kooh_shekan()const
    {
        return red_card_handel.get_used_kooh_shekan();
    }

    bool Gameplay::get_red_card_rooh_jangal()const
    {
        return red_card_handel.get_used_rooh_jangal();
    }

    bool Gameplay::get_help() const
    {
        return getting_help;
    }

    int Gameplay::get_empty_hand_players() const
    {
        return empty_hand_players;
    }

    bool Gameplay::get_pass_counted() const
    {
        return pass_counted;
    }

    int Gameplay::get_play_cards() const
    {
        return play_cards.size();
    }

    string Gameplay::get_play_cards_data(int &i) const
    {
        return play_cards[i];
    }

    int Gameplay::get_cards_size() const
    {
        return cards.size();
    }

    string Gameplay::get_cards_data(int & index) const
    {
        return cards[index];
    }

    bool Gameplay::get_pass() const
    {
        return pass;
    }

    void Gameplay::show_cards_array() const
    {
        for(int i = 0 ; i < cards.size(); i++)
        {
            cout << cards[i] << '\t';
        }
    }
    ///method
    void Gameplay::setting_card(const Card card_setter,const int conquer_cities_number)
    {
        srand(time(0));
        if(card_data.get_index_purple_card() > 51)
        {
            card_data.set_index_purple_card(0);
        }
        if(card_data.get_index_yellow_card() > 56)
        {
            card_data.set_index_yellow_card(0);
        }

        for(int i = 0 ; i < 10 + conquer_cities_number ;i++)
        {
            int Random = rand() % 8 + 1;
            if(Random % 2 == 0)
            {
                cards.push_back( card_setter.get_purple_card(card_data.get_index_purple_card() ) );
                card_data.set_index_purple_card(card_data.get_index_purple_card() + 1);
            }
            else if(Random == 7)
            {
                cards.push_back( card_setter.get_red_card( red_card_handel.get_index_red_card()) );
                red_card_handel.set_index_red_card();
            }
            else
            {
                cards.push_back( card_setter.get_yellow_card(card_data.get_index_yellow_card() ) );
                card_data.set_index_yellow_card(card_data.get_index_yellow_card() + 1);
            }
        }
    }

    void Gameplay::print_cards(const int index,const Players play)
    {//print the cards for each player
        system("cls");
        cout <<"We want to show the Player"<<index+1<<" Card(press any key): "<<endl;
        getch();
        cout << "Name: " << play.get_name(index) << "\tage: " << play.get_age(index) <<"\tColor : " << play.get_color(index) <<"\tCards: " <<endl;
        Gameplay::show_cards_array();
        getch();
        cout << endl<<endl;

    }

    void Gameplay::show_saturation(int number,int number_of_players,int biggest_played_card)
    {//print the available cards for player and taking his input
        cout <<endl<< "Player Turn Player: " << number +1 <<endl;
        define_players_turn(number,number_of_players);
        if(pass){
            cout << "\t Player has Passed the round!!"<<endl;
            getch();
            return;
        }
        cout << "The player available Cards are : " << endl<<endl;
        Gameplay::show_cards_array();
        cout << endl<<endl<<"Please Enter the value of The Card That you want to play(Enter 0 or say pass if You want to Pass): " <<endl;
        string input;
        getline(cin,input);
        while(input!="help"&&input!="pass"&&input!="help bahar"&&input!="help matarsak"&&input!="help shir_dokht"&&input!="help zemestan"&&input!="help tabl_zan"&&input!="0"
              &&input!="help shir_zan"&&input!="help rish_sefid"&&input!="help parcham_dar")
        {
            if( Gameplay::check_exist_card(input) )
            {
                break;
            }
            else
            {
                cout << "Enter Value Please:"<<endl;
                getline(cin,input);
            }
        }
        if(input == "pass"|| input == "0")
        {
            pass = true;
            return;
        }
        if(input == "help")
        {
            set_help(true);
            menu.menu_of_opsions();
            return;
        }
        if(input=="help bahar"||input=="help matarsak"||input=="help shir_dokht"||input=="help zemestan"||input=="help tabl_zan"||input=="help parcham_dar"||
           input=="help shir_zan"||input=="help rish_sefid")
        {
            set_help(true);
            cards_helping_menus(input);
            return;
        }
        control_received_card(input,number,biggest_played_card);
        Gameplay::input_chosen_card(input);
        Gameplay::setting_the_input_card();
    }

    void Gameplay::control_received_card(string input,int number,int biggest_played_card)
    {
        if(input == "rakhsh_sefid")
        {
            card_data.set_used_rakhsh_sefid(true);
            players_turn = number;
        }
        if(input == "parcham_dar")
        {
            card_data.set_parcham_dar(true);
        }
        if(input == "rish_sefid")
        {
            rish_sefid_handel.set_used_rish_sefid_card(true);
            rish_sefid_handel.set_biggest_card_value(biggest_played_card);
            rish_sefid_handel.set_rish_sefid_card(true);
            rish_sefid_handel.set_last_played_card_index(number);
        }
        if(input == "herkol")
        {
            red_card_handel.set_used_herkol(true);
        }
        if(input == "kooh_shekan")
        {
            red_card_handel.set_used_kooh_shekan(true);
        }
        if(input == "rooh_jangal")
        {
            red_card_handel.set_used_rooh_jangal(true);
        }
    }

    void Gameplay::setting_the_input_card()
    {
        cout << "The Played Card is : " << cards[chosen_card - 1]<<endl;
        getch();
        set_played_card(cards[chosen_card - 1]);
        cards[chosen_card - 1] = "Empty";
    }

    void Gameplay::matarsak()
    {//handle the matarsak card(matarsak card only impact during the game and after the round ends is useless so we handle it here)
        cout << "You select matarsak! Your Played cards are: "<<endl;
        for(int i =0 ;i < play_cards.size() ; i++)
        {
            cout << play_cards[i] << '\t';
        }
        cout<<endl << "Please Enter the Value of The soldier Card you Want to Put Back:(only inter Value of card if there is no soldier card Enter 0)"<<endl;
        string input;
        cin>> input;
        if(input == "0")
        {
            return;
        }
        while( check_exist_played_card(input)== false )
        {
            cout << "There is no Card with this Value!!"<<endl;
            cin>> input;
            if(input == "0")
            {
                return;
            }
        }
        for(int i =0 ;i < play_cards.size() ; i++)
        {
            if(play_cards[i] == input)
            {
                play_cards[i] = "Empty";
                Gameplay::set_cards(input);
                break;
            }
        }
    }

    bool Gameplay::check_exist_played_card(string input)const
    {//validation of matarsak
        if(input != "0"&&input != "1"&&input !="2"&&input != "3"&&input != "4"&&input != "5"&&input != "6"&&input != "10")
        {
            return false;
        }

        for(int i = 0 ; i < play_cards.size() ; i++)
        {
            if(input == play_cards[i] && input != "Empty")
            {
                return true;
            }
        }
        return false;
    }

    void Gameplay::define_players_turn(int number,int number_of_players)
    {//setting the plater turn in match
        players_turn = number + 1;
        if(players_turn == number_of_players)
        {
            players_turn = 0;
        }
    }

    void Gameplay::cards_helping_menus(string &temp)
    {//check the input to show help menu
        if(temp == "help bahar"){
            menu.bahar_help();
            return;
        }
        if(temp=="help matarsak"){
            menu.matarsak_help();
            return;
        }
        if(temp == "help zemestan"){
            menu.zemestan_help();
            return;
        }
        if(temp == "help tabl_zan"){
            menu.tabl_zan_help();
            return;
        }
        if(temp == "help shir_dokht"){
            menu.shir_dokht_help();
            return;
        }
        if(temp == "help rish_sefid"){
            menu.rish_sefid_help();
            return;
        }
        if(temp == "help shir_zan"){
            menu.shir_zan_help();
            return;
        }
        if(temp == "help parcham_dar"){
            menu.parcham_dar_help();
            return;
        }
    }

    void Gameplay::input_chosen_card(string temp)
    {//setting the index of chosen card by player
        for(int i =0 ; i < cards.size();i++)
        {
            if(cards[i] == temp){
                chosen_card = i+1;
                break;
            }
        }
    }

    void Gameplay::re_set_red_cards()
    {
        red_card_handel.set_used_herkol(false);
        red_card_handel.set_used_kooh_shekan(false);
        red_card_handel.set_used_rooh_jangal(false);
    }

    bool Gameplay::check_exist_card(string chosen)
    {//check that input from player is correct
        for(int i = 0 ; i < cards.size() ; i++)
        {
            if(chosen == cards[i] && chosen != "Empty")
            {
                return true;
            }
        }
        return false;
    }
    void Gameplay::check_empty_cards(int number_of_players,vector <Gameplay> game_gameplay)
    {//checking that is need to set cards againg or not

        empty_hand_players = 0;
        for(int i = 0 ; i < number_of_players ; i++)
        {
            int empty_cards_number = 0;
            for(int j = 0; j < game_gameplay[i].cards.size() ;j++)
            {
                if (game_gameplay[i].cards[j] == "Empty")
                {
                    empty_cards_number++;
                }
                if(empty_cards_number == game_gameplay[i].cards.size() )
                {
                    empty_hand_players++;
                    empty_cards_number = 0;
                }
            }
        }
    }

    void Gameplay::handel_rish_sefid(int number_of_players,vector <Gameplay> &game_gameplay)
    {
        for(int j = 0; j < number_of_players ; j++)
        {
            for (int i = 0; i < game_gameplay[j].play_cards.size() ;i++)
            {
                if(game_gameplay[j].play_cards[i] == "1"||game_gameplay[j].play_cards[i] == "2"||game_gameplay[j].play_cards[i] == "3"||game_gameplay[j].play_cards[i] == "4"||
                   game_gameplay[j].play_cards[i] == "5"||game_gameplay[j].play_cards[i] == "6"||game_gameplay[j].play_cards[i] == "10" )
                {
                    if( stoi(game_gameplay[j].play_cards[i]) == rish_sefid_handel.get_biggest_card_value() )
                    {
                        game_gameplay[j].play_cards[i] = "Empty";
                    }
                }
            }
        }
    }
