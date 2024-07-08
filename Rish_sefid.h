#include <string>
#include <vector>
#ifndef RISH_SEFID_H
#define RISH_SEFID_H

using namespace std;

class Rish_Sefid{
public:

    ///constructor
    Rish_Sefid();

    ///setter
    void set_biggest_card_value(int);
    void set_number_of_players(int);


    ///getter
    int get_last_played_card_index();

    bool get_rish_sefid_card();

    ///method
    void setting_rish_sefid(int,vector <string>&);


private:
    static int last_played_card_index;
    static bool rish_sefid_card;
    static int number_of_players;
    static int biggest_card_value;

};

#endif
