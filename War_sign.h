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
    void SetWar(string);
    ///getter
    string GetWar();
    ///method
    void SetWar_sing();
private:
    string War;
};



#endif
