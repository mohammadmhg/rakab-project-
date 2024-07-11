#include <iostream>
#include <string>
#include "War_sign.h"

using namespace std;

    War_Sign::War_Sign()
    {
        war = "none";
    }
    War_Sign::War_Sign(string data): war(data){}
    ///setter
    void War_Sign::set_war_sign(string city)
    {
        this->war = city;
    }
    ///getter
    string War_Sign::get_war_sign() const
    {
        return war;
    }
        ///method
    void War_Sign::define_war_sign(int player)
    {

        cout <<"Player " << player+1<< " has the war_sign . Enter an empty city to start attack :"<<endl;
        string temp_sign;
        cin>> temp_sign;
        while (temp_sign!="BELLA"&&temp_sign!="CALINE"&&temp_sign!="ENNA"&&temp_sign!="ATELA"&&temp_sign!="PLADACI"&&temp_sign!="BORGE"&&temp_sign!="DIMASE"&&temp_sign!="MORINA"&&
        temp_sign!="OLIVADI"&&temp_sign!="ROLLO"&&temp_sign!="TALMONE"&&temp_sign!="ARMENTO"&&temp_sign!="LIA"&&temp_sign!="ELINIA")
        {
            cout <<"WRONG NAME!!"<<endl;
            cin>>temp_sign;
        }
        War_Sign::set_war_sign(temp_sign);
    }
