#include <iostream>
#include "Board.h"
#include "StartPage.h"
#include "GreenTiles.h"


using namespace std;

int randRoll() {
    return rand() % 6 + 1; // Simulates a dice roll (1-6)
}

int main() {
    StartPage start;
    start.displayMenu();
    GreenTiles green;
    green.displayGreenTiles();

    cout<< "\n" << endl;
    Board board = Board();
    board.displayBoard();
    cout<< "\n" << endl;
    board.movePlayer(0);
    board.displayBoard(); 
    green.updateBoardAfterMove(0);
    green.displayGreenTiles();
    
    return 0;
}