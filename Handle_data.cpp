#include "Handle_data.h"
using namespace std;

bool Handle_Data::is_bahar = false;
bool Handle_Data::is_zemestan = false;
bool Handle_Data::used_parcham_dar = false;
bool Handle_Data::used_matarsak = false;
bool Handle_Data::used_rakhsh_sefid = false;
int Handle_Data::index_yellow_card = 0;
int Handle_Data::index_purple_card = 0;

    Handle_Data::Handle_Data(){}
    ///setter

    void Handle_Data::set_used_matarsak(bool used)
    {
        used_matarsak = used;
    }

    void Handle_Data::set_parcham_dar(bool card)
    {
        used_parcham_dar = card;
    }

    void Handle_Data::re_set_data()
    {//re_setting the bahar and zemestan
        is_bahar = false;
        is_zemestan = false;
        used_parcham_dar = false;
    }

    void Handle_Data::set_bahar(bool season)
    {
        is_bahar = season;
    }

    void Handle_Data::set_zemestan(bool season)
    {
        is_zemestan = season;
    }

    void Handle_Data::set_index_yellow_card(int index)
    {
        index_yellow_card = index;
    }

    void Handle_Data::set_index_purple_card(int index)
    {
        index_purple_card = index;
    }

    void Handle_Data::set_used_rakhsh_sefid(bool rakhsh)
    {
        used_rakhsh_sefid = rakhsh;
    }

    ///getter

    bool Handle_Data::get_used_matarsak()const
    {
        return used_matarsak;
    }

    bool Handle_Data::get_parcham_dar()const
    {
        return used_parcham_dar;
    }

    bool Handle_Data::get_zemestan() const
    {
        return is_zemestan;
    }

    bool Handle_Data::get_bahar() const
    {
        return is_bahar;
    }

    int Handle_Data::get_index_yellow_card() const
    {
        return index_yellow_card;
    }

    int Handle_Data::get_index_purple_card() const
    {
        return index_purple_card;
    }

    bool Handle_Data::get_used_rakhsh_sefid()const
    {
        return used_rakhsh_sefid;
    }
