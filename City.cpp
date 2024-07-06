
#include "City.h"

using namespace std;

    City::City()
    {
        taken_city.resize(5);
    }

    void City::set_city(string city)
    {
        taken_city.push_back(city);
    }

    ///getter

    string City::get_city(int index) const
    {
        return taken_city[index];
    }

    ///method

    void City::show_taken_cities() const
    {
        for (int i = 0; i < taken_city.size() ; i++)
        {
            cout << taken_city[i] << '\t';
        }
    }

    bool City::check_taken_cities(string war_city)
    {//check that player do not enter a name of a taken city

        for(int i = 0 ; i < taken_city.size() ;i++)
        {
            if(taken_city[i] == war_city)
            {
                return true;
            }
        }

        return false;

    }


