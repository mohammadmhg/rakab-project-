#include <string>
#ifndef WAR_SIGN_H
#define WAR_SIGN_H
using namespace std;

class War_sign{
public:
    ///constructor
    War_sign();
    War_sign(string);
    ///setter
    void set_war_sign(string);
    ///getter
    string get_war_sign();
    ///method
    void define_war_sing();
private:
    string War;
};



#endif
