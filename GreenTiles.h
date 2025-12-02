#include <iostream>
#include "Board.h"
#include <vector>
#include <fstream>
#include <string>
//#include "Tile.h"
using namespace std;

class GreenTiles
{
    private:
        Board board;
        vector<string> events;
        vector<string> greenTileDescriptions;
        vector<int> pathType;
        vector<int> points;
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
        void setRandomEvents(fstream &file)
        {
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
        }
        void triggerRandomEvent(int player_index)
        {
            int num = events.size();
            int randomIndex = rand() % num;
            cout << "Random Event: " << events[randomIndex] << endl;
        }
};
