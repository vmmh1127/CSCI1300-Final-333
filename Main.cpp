#include <iostream>
#include <ctime>
#include "Board.h"
#include "StartPage.h"
#include "GreenTiles.h"
#include "DNA.h"


using namespace std;

int randRoll() {
    return rand() % 6 + 1; // Simulates a dice roll (1-6)
}

int main() {
    
    srand(time(0)); // Seed for random number generation

    Player player1 = Player();
    Player player2 = Player();

    StartPage start;
    start.setUpCharacters("characters.txt");
    start.namesStartPage(player1.getPlayerName(), player2.getPlayerName());
    start.displayMenu();
    start.path_type();

    GreenTiles green;
    //green.nameGreenTiles(player1.getName());
    green.displayGreenTiles();

    cout<< "\n" << endl;

    Board board = Board();
    //board.displayBoard();

    int turn = 0;

    cout<< "\n" << endl;

    while(board.getPlayerPosition(0) < 51 && board.getPlayerPosition(1) < 51){

        int current = turn % 2;
        board.movePlayer(current);
        board.displayBoard();

        if (board.getTileColor(current) == 'G')
        {
            green.triggerRandomEvent();
        }

        turn++;
    }
    cout << "\n" << "=====================================================================================" << "\n" << endl;
   //board.movePlayer(0);
    //board.displayBoard(); 

    /*green.updateBoardAfterMove(0);
    green.displayGreenTiles();*/
    green.setRandomEvents("random_events.txt");

    green.triggerRandomEvent();
    green.triggerRandomEvent();

    cout << "\n" << "=====================================================================================" << "\n" << endl;

    DNA dna;
    dna.generate_two_strands(10, 6);
    dna.strandSimilarity("ATCGTACGTA", "ATCGTTCG");
    //dna.bestStrandMatch("ATCGTACGTA", "CGTACG");
    //dna.identifyMutations("ATCGTACGTA", "CGTACG");
    //string rna_strand = dna.transcribeToRNA("ATCGTACGTA");
    return 0;
}