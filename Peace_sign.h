#include <string>
#ifndef PEACE_SIGN_H
#define PEACE_SIGN_H
using namespace std;

class Peace_Sign{
public:
    ///constructor
    Peace_Sign();
    Peace_Sign(string);
    ///setter
    void set_peace_sign(string);
    ///getter
    string get_peace_sign() const;
    ///method
    void define_peace_sign(int);
private:
    string peace;
};

#endif
