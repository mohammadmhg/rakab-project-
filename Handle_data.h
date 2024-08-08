#ifndef HANDLE_DATA_H
#define HANDLE_DATA_H

class Handle_Data{
public:
    Handle_Data();
    ///setter

    void set_bahar(bool);
    void set_zemestan(bool);
    void set_parcham_dar(bool);
    void set_used_matarsak(bool);
    void set_index_yellow_card(int);
    void set_index_purple_card(int);
    void re_set_data();
    void set_used_rakhsh_sefid(bool);

    ///getter

    bool get_bahar() const;
    bool get_zemestan() const;
    bool get_parcham_dar()const;
    bool get_used_matarsak()const;
    int get_index_yellow_card() const;
    int get_index_purple_card() const;
    bool get_used_rakhsh_sefid()const;

private:

    static bool is_bahar;
    static bool is_zemestan;
    static bool used_parcham_dar;
    static bool used_matarsak;
    static bool used_rakhsh_sefid;
    static int index_yellow_card;
    static int index_purple_card;

};

#endif // HANDLE_DATA_H_INCLUDED
