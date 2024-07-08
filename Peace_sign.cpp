#include <iostream>
#include <string>
#include "Peace_sign.h"

using namespace std;

    ///constructor
    Peace_Sign::Peace_Sign(){}
    Peace_Sign::Peace_Sign(string name): peace(name){}
    ///setter
    void Peace_Sign::set_peace_sign(string name)
    {
        this->peace = name;
    }
    ///getter
    string Peace_Sign::get_peace_sign()
    {
        return peace;
    }
    ///method
    void Peace_Sign::define_peace_sign(int player)
    {
        system("cls");
        cout << "Player" << player + 1<<" has played the rish_sefid card.Enter the name of an Empty city to put Sign on it:"<<endl;
        string temp_sign;
        cin>> temp_sign;
        while (temp_sign!="BELLA"&&temp_sign!="CALINE"&&temp_sign!="ENNA"&&temp_sign!="ATELA"&&temp_sign!="PLADACI"&&temp_sign!="BORGE"&&temp_sign!="DIMASE"&&temp_sign!="MORINA"&&
        temp_sign!="OLIVADI"&&temp_sign!="ROLLO"&&temp_sign!="TALMONE"&&temp_sign!="ARMENTO"&&temp_sign!="LIA"&&temp_sign!="ELINIA")
        {
            cout <<"WRONG NAME!!"<<endl;
            cin>>temp_sign;
        }
        Peace_Sign::set_peace_sign(temp_sign);
    }

