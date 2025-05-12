#include <iostream>
#include "includes/game.h"
#include "includes/consts.h"
using namespace std;


int main() {

    cout << "CHECK: " << CELL_WIDTH << endl;

    Game game;
    game.render();
    
    return 0;
}