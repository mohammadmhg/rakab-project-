#include <string>
#include <vector>

#ifndef RED_CARD_H
#define RED_CARD_H
using namespace std;

class Red_Card{
public:
    ///constructor

    Red_Card();
    ///setter

    void set_index_red_card();
    void set_used_herkol(bool);
    void set_used_rooh_jangal(bool);
    void set_used_kooh_shekan(bool);




    ///getter

    int get_index_red_card() const;
    bool get_used_herkol() const;
    bool get_used_rooh_jangal() const;
    bool get_used_kooh_shekan() const;


private:

    static int index_red_card;
    bool used_herkol = false;
    bool used_rooh_jangal = false;
    bool used_kooh_shekan = false;

};


#endif
