#include <iostream>
#include "Board.h"
#include <vector>
#include <fstream>
//#include "Tile.h"
using namespace std;

class GreenTiles
{
    private:
        Board board;
    public:
        GreenTiles()
        {
            board = Board();
        }
        void displayGreenTiles()
        {
            for (int i = 0; i < 52; i++) {
                if (board.getPlayerPosition(0) == i || board.getPlayerPosition(1) == i) {
                    if (board.getPlayerPosition(0) == i) {
                        cout << "Player 1 is on tile " << i << endl;
                    }
                    if (board.getPlayerPosition(1) == i) {
                        cout << "Player 2 is on tile " << i << endl;
                    }
                }
            }
        }
        void updateBoardAfterMove(int player_index)
        {
            board.movePlayer(player_index);
        }
        void randomEvents(fstream &file)
        {
            vector<string> events;

            file.open("random_events.txt");
            if(file.fail())
            {
                cout << "oopsie" << endl;
                return;
            }
            string line;
            while (getline(file, line))
            {
                events.push_back(line);
            }

            //int num 
        }
};
