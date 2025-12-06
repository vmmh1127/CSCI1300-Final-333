#include <iostream>
#include <ctime>
#include "Board.h"
#include "StartPage.h"
#include "GreenTiles.h"
#include "DNA.h"

//Partner Name: Vidita Mulik


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
    dna.setRandomRiddles("riddles.txt");

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
            cout << "Enter original DNA strand and mutated DNA strand: (contains letters a,c,t,g only)" << endl;
            cin >> strand1 >> strand2;
            dna.identifyMutations("ATCGTACGTA", "CGTACG");
            cin.clear();
            strand1 = "";
            strand2 = "";
        }
        if(board.getTileColor(current) == 'P'){
            cout << "Pink Tile! DNA Alignment Challenge Initiated!" << endl;
            cout << "Enter two DNA strands to find best alignment: (contains letters a,c,t,g only)" << endl;
            cin >> strand1 >> strand2;
            dna.bestStrandMatch(strand1, strand2);
            cin.clear();
            strand1 = "";
            strand2 = "";
        }
        if(board.getTileColor(current) == 'T'){
            cout << "Brown Tile! Transcription Challenge Initiated!" << endl;
            cout << "Enter a DNA strand to transcribe to RNA: (contains letters a,c,t,g only)" << endl;
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
        cout << "\n" << "===========================================================================================================================" << "\n" << endl;
    }
    if (board.getPlayerPosition(0)==51){
        cout<< player1.getPlayerName() << "; thou hast reached the end of the DNA Journey first "<<endl;
    }
    else
    {
        cout<< player2.getPlayerName() << "; thou hast reached the end of the DNA Journey first "<<endl;
    }

    int finalPts1 = player1.getExperiencePoints()+ player1.getAccuracyPoints() + player1.getEfficiencyPoints() + player1.getInsightPoints() + player1.getDiscoverPoints();
    int finalPts2 = player2.getExperiencePoints()+ player2.getAccuracyPoints() + player2.getEfficiencyPoints() + player2.getInsightPoints() + player2.getDiscoverPoints();

    cout << player1.getPlayerName() << "'s Final Points: " << finalPts1 << endl;
    cout << player2.getPlayerName() << "'s Final Points: " << finalPts2 << endl;
    
    if (finalPts1 > finalPts2){
        cout << player1.getPlayerName() << " is the Ultimate DNA Master! Congratulations!" << endl;
    }
    else if (finalPts2 > finalPts1){
        cout << player2.getPlayerName() << " is the Ultimate DNA Master! Congratulations!" << endl;
    }
    else {
        cout << "It's a tie! Both you are Ultimate DNA Masters! Congratulations!" << endl;
    }
    
    return 0;
}