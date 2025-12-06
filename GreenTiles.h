#include <iostream>
//#include "Board.h"
#include "Player.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
//#include "Tile.h"
using namespace std;

class GreenTiles
{
    private:
        //Board board;
        //Player player;
        string p;
        vector<string> events;
        vector<string> greenTileDescriptions;
        vector<int> pathType;
        vector<int> advisor;
        vector<int> points;
    public:
        GreenTiles()
        {
            p = ":333333";
            //player = Player();
            //board = Board();
        }
        /*void nameGreenTiles(Player p)
        {
            player.setName(p.getName());
        }*/
        /*void displayGreenTiles()
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
        }*/
        /*void updateBoardAfterMove(int player_index)
        {
            board.movePlayer(player_index);
        }*/
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

                ss << line;

                string pathTypeStr, pointsStr, description, advisorStr;

                getline(ss, description, '|');
                greenTileDescriptions.push_back(description);

                getline(ss, pathTypeStr, '|');
                pathType.push_back(stoi(pathTypeStr));

                getline(ss, advisorStr, '|');
                advisor.push_back(stoi(advisorStr));

                getline(ss, pointsStr, '|');
                points.push_back(stoi(pointsStr));

                events.push_back(line);

                //cout << events.size() << " " << greenTileDescriptions.size() << " " << pathType.size() << " " << advisor.size() << " " << points.size() << endl;

                i++;
            }
        }
        Player triggerRandomEvent(Player pl)
        {
            int num = events.size();
            
            //cout << events.size() << " " << greenTileDescriptions.size() << " " << pathType.size() << " " << advisor.size() << " " << points.size() << endl;
            int randomIndex = rand() % num;
            //player.setPlayerName(p.getPlayerName());
            cout << "Random Event: " << greenTileDescriptions[randomIndex] << "," << advisor[randomIndex] << "," << pathType[randomIndex] << "," << points[randomIndex] << endl;
            if(points[randomIndex] < 0)
            {
                cout << pl.getPlayerName() << " lost " << -points[randomIndex] << " experience points!" << endl;
            }
            else
            {
                cout << pl.getPlayerName() << " gained " << points[randomIndex] << " experience points!" << endl;
            }
            pl.addExperiencePoints(points[randomIndex]);
            //player = p;
            return pl;
        }
};
