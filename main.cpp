#include <ctime>
#include "Game.h"

using namespace std;

int main()
{
    srand(time(0));
    Game game_start;
    if( game_start.get_exit_game() )
    {
        return 0;
    }
    return 0;
}
