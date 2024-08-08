#include <vector>
#include <string>
#ifndef CARD_H
#define CARD_H
using namespace std;

class Card{
public:
    Card();
    Card(string,string);
    ///setter

    void set_yellow_card();
    void set_purple_card();
    void set_red_card();
    ///getter

    string get_yellow_card(int) const;
    string get_purple_card(int) const;
    string get_red_card(int) const;
    ///method

    void shuffle_yellow_cards();
    void shuffle_purple_cards();
    void shuffle_red_cards();

private:

    vector <string> purple_cards;
    vector <string> yellow_cards;
    vector <string> red_cards;
    void define_purple_cards(int,string);
    void define_yellow_cards(int,string);
    void define_red_cards(int,string);

};


#endif // CARD_H
