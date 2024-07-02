#include <vector>
#ifndef CARD_H
#define CARD_H
using namespace std;

class Card{
public:
    Card();
    Card(string,int);
    ///setter

    void set_yellow_card();
    void set_purple_card();
    ///getter

    int get_yellow_card(int) const;
    string get_purple_card(int) const;
    ///method

    void shuffle_yellow_cards();
    void shuffle_purple_cards();

private:
    vector <string> purple_cards;
    vector <int> yellow_cards;
    void define_purple_cards(int,string);
    void define_yellow_cards(int,int);

};


#endif // CARD_H
