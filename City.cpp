
#include "City.h"

using namespace std;

    City::City(){}


    void City::set_city(string city)
    {
        taken_city.push_back(city);
    }

    ///getter

    string City::get_city(int index) const
    {
        return taken_city[index];
    }

    int City::get_size_of_city()const
    {
        return taken_city.size();
    }

    ///method

    void City::show_taken_cities() const
    {
        for (int i = 0; i < taken_city.size() ; i++)
        {
            cout << taken_city[i] << '\t';
        }
    }

    bool City::check_taken_cities(string war_city,string peace_city)
    {//check that player do not enter a name of a taken city

        if( peace_city == war_city)
        {
                return true;
        }

        for(int i = 0 ; i < taken_city.size() ;i++)
        {
            if(taken_city[i] == war_city)
            {
                return true;
            }
        }

        return false;

    }

    bool City::set_adjacent_cities()
    {//check adjacent for the taken citys by a player
        unordered_map<string, vector<string>> map_citys;

        map_citys = {
        {"BELLA", {"CALINE","PLADACI","BORGE"}},
        {"CALINE", {"BELLA","PLADACI","BORGE","LIA","ATELA"}},
        {"LIA", {"CALINE","ATELA","BORGE","DIMASE"}},
        {"ATELA", {"CALINE","LIA","DIMASE","ATEN"}},
        {"PLADACI", {"BORGE","MORINA","ROLLO"}},
        {"BORGE", {"BELLA","CALINE","LIA","DIMASE","PLADACI","DIMASE","MORINA","OLIVADI"}},
        {"DIMASE", {"LIA","ATELA","BORGE","OLIVADI","ATEN"}},
        {"MORINA", {"PLADACI","BORGE","OLIVADI","ROLLO","TALMONE","ARMENTO"}},
        {"OLIVADI", {"BORGE","DIMASE","MORINA","ARMENTO","ENNA"}},
        {"ROLLO", {"PLADACI","MORINA","TALMONE","ELINIA"}},
        {"TALMONE", {"MORINA","ROLLO","ARMENTO","ELINIA"}},
        {"ARMENTO", {"MORINA","OLIVADI","ENNA","TALMONE"}},
        {"ENNA", {"OLIVADI","ARMENTO"}},
        {"ELINIA", {"ROLLO","TALMONE"}},
        {"ATEN", {"ATELA","DIMASE"}}
        };
        int adjacent = 0;
        for (int i = 0; i< taken_city.size();i++)
        {
            auto name = map_citys.find(taken_city[i]);
            adjacent = 0;
            if (name != map_citys.end())
            {
                for (vector<string>::const_iterator Neighbor = name->second.begin(); Neighbor != name->second.end();Neighbor++)
                {
                    for(int k = i + 1 ; k < taken_city.size();k++)
                    {
                        if(*Neighbor == taken_city[k])
                        {
                            string temp_city = taken_city[k];
                            check_second_adjacent(adjacent,k,map_citys,temp_city,i);

                            if(adjacent >= 2)
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }

        return false;
    }


    void City::check_second_adjacent(int &adjacent,int k,unordered_map<string, vector<string>> map_citys,string temp_city,int i)//check the triangular adjacency
    {
        for(int z = k + 1; z < taken_city.size() ;z++)
        {
            auto name = map_citys.find(taken_city[z]);
            if (name != map_citys.end())
            {
                for(vector<string>::const_iterator Neighbor2 = name->second.begin(); Neighbor2 != name->second.end();Neighbor2++)
                {
                    for (int x = 0 ; x < taken_city.size();x++)
                    {
                        if(taken_city[x] == *Neighbor2)
                        {
                            adjacent++;
                        }
                    }
                }
            }
        }
    }


