#include <string>
#include "City.h"
#ifndef RISH_SEFID_H
#define RISH_SEFID_H

using namespace std;

class Rish_Sefid{
public:

    ///constructor
    Rish_Sefid();

    ///getter
    int get_last_played_card_index();

    bool get_rish_sefid_card();

    ///method
    void setting_rish_sefid(int);

    void setting_peace_sign(vector <City>);




private:
    static int last_played_card_index;
    static bool rish_sefid_card;

};

#endif
