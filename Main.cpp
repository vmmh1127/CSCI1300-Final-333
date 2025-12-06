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
    //string name1;
    //string name2;

    StartPage start;
    start.setUpCharacters("characters.txt");

    player1 = start.setUpPlayerStats1(player1);
    player2 = start.setUpPlayerStats2(player2);

    //start.namesStartPage(player1.getPlayerName(), player2.getPlayerName());
    start.gameStart(player1, player2);
    start.path_type(player1, player2);

    //name1 = start.namesStartPage();

    cout << player1.getPlayerName() << endl;
    cout << player2.getPlayerName() << endl;
    cout << "\n" << endl;

    GreenTiles green;
    green.setRandomEvents("random_events.txt");
    //green.nameGreenTiles(player1.getName());

    Board board = Board();

    DNA dna;

    int turn = 0;
    string strand1;
    string strand2;

    cout << "\n" << endl;

    while(board.getPlayerPosition(0) < 51 && board.getPlayerPosition(1) < 51){

        int current = turn % 2;
        board.movePlayer(current);
        board.displayBoard();

        if (board.getTileColor(current) == 'G')
        {
            if(current == 0) { player1 = green.triggerRandomEvent(player1);}
            else { player2 = green.triggerRandomEvent(player2); }
        }

        if(board.getTileColor(current) == 'B'){
            cout << "Blue Tile! DNA Challenge Initiated!" << endl;
            cout << "Enter two DNA strands to compare similarity: " << endl;
            cin >> strand1 >> strand2;
            dna.strandSimilarity(strand1, strand2);
            cin.clear();
            strand1 = "";
            strand2 = "";
        }

        if(board.getTileColor(current) == 'R'){
            cout << "Red Tile! DNA Mutation Challenge Initiated!" << endl;
            cout << "Enter original DNA strand and mutated DNA strand: " << endl;
            cin >> strand1 >> strand2;
            dna.identifyMutations("ATCGTACGTA", "CGTACG");
            cin.clear();
            strand1 = "";
            strand2 = "";
        }
        if(board.getTileColor(current) == 'P'){
            cout << "Pink Tile! DNA Alignment Challenge Initiated!" << endl;
            cout << "Enter two DNA strands to find best alignment: " << endl;
            cin >> strand1 >> strand2;
            dna.bestStrandMatch(strand1, strand2);
            cin.clear();
            strand1 = "";
            strand2 = "";
        }
        if(board.getTileColor(current) == 'T'){
            cout << "Brown Tile! Transcription Challenge Initiated!" << endl;
            cout << "Enter a DNA strand to transcribe to RNA: " << endl;
            cin >> strand1;
            string rna_strand = dna.transcribeToRNA(strand1);
            cout << "Transcribed RNA Strand: " << rna_strand << endl;
            cin.clear();
            strand1 = "";
        }
        if(board.getTileColor(current) == 'U')
        {
            cout << "Purple Tile! Riddle Time :3333" << endl;
            dna.presentRiddleToPlayer();
        }
        cout << "\n" << player1.getPlayerName() << "'s Experience Points: " << player1.getExperiencePoints() << endl;
        cout << player2.getPlayerName() << "'s Experience Points: " << player2.getExperiencePoints() << endl;
        turn++;
        cout << "\n" << "===============================================================" << "\n" << endl;
    }

    return 0;
}