#include <iostream>
#include "Board.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
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
        void setRandomEvents(string filename)
        {
            ifstream file(filename);
            //file.open("random_events.txt");
            string line;
            int i = 0;

            if(file.fail())
            {
                cout << "oopsie" << endl;
                return;
            }
            while (getline(file, line))
            {
                stringstream ss;
                string pathTypeStr, pointsStr;

                getline(ss, greenTileDescriptions[i], '|');

                getline(ss, pathTypeStr, '|');
                pathType.push_back(stoi(pathTypeStr));

                getline(ss, pointsStr, '|');
                points.push_back(stoi(pointsStr));

                //events.push_back(line);

                i++;
            }
        }
        void triggerRandomEvent(int player_index)
        {
            int num = events.size();
            int randomIndex = rand() % num;
            cout << "Random Event: " << greenTileDescriptions[randomIndex] << "," << pathType[randomIndex] << "," << points[randomIndex] << endl;
        }
};
