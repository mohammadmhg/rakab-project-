#include <iostream>
using namespace std;
class Menu{///for setting the menu of game
public:
    void Start_menu(){
            system("cls");
            cout << " Welcome to rakab Game!!"<<endl << endl<< "\t ***************" << endl<<endl;
            cout << "\t 1-Start the game" << endl << "\t 2-Menu of opsions" << endl << "\t 3-Exit" << endl<<endl;
            cout << "\t ***************"<<endl;
    }
    void Start_War(){
        cout << "The Player1 have The War_sign!"<< endl;
        cout << "Please Enter the name of an empty city you want to Attack: "<< endl;
    }
private:
};