#include <string>
#ifndef WAR_SIGN_H
#define WAR_SIGN_H
using namespace std;

class War_Sign{
public:
    ///constructor
    War_Sign();
    War_Sign(string);
    ///setter
    void set_war_sign(string);
    ///getter
    string get_war_sign() const;
    ///method
    void define_war_sign(int);
private:
    string war;
};



#endif
