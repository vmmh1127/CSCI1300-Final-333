#include <iostream>
#include <ctime>
#include "Board.h"
#include "StartPage.h"
#include "GreenTiles.h"


using namespace std;

int randRoll() {
    return rand() % 6 + 1; // Simulates a dice roll (1-6)
}

int main() {
    
    srand(time(0)); // Seed for random number generation

    StartPage start;
    start.setUpCharacters("characters.txt");
    start.displayMenu();

    GreenTiles green;
    green.displayGreenTiles();

    cout<< "\n" << endl;

    Board board = Board();
    board.displayBoard();

    Player player1 = Player();
    Player player2 = Player();

    cout<< "\n" << endl;

    board.movePlayer(0);
    board.displayBoard(); 

    green.updateBoardAfterMove(0);
    green.displayGreenTiles();
    green.setRandomEvents("random_events.txt");

    cout << "Loaded events successfully" << endl;

    green.triggerRandomEvent(0, player1);
    green.triggerRandomEvent(0, player2);
    
    return 0;
}