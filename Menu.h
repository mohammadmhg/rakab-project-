
#ifndef MENU_H
#define MENU_H


class Menus{
public:
    void set_loading_game(bool);
    bool get_loading_game()const;

    void start_menu();
    void start_war(int);
    void menu_of_opsions();
    void bahar_help();
    void zemestan_help();
    void tabl_zan_help();
    void shir_dokht_help();
    void matarsak_help();
    void rish_sefid_help();
    void parcham_dar_help();
    void shir_zan_help();
    void non_existed_card();
    bool action();
    void exit();
    void ending();
    void enter_players();
    void enter_details();
private:
    bool upload_game = false;
};

#endif
