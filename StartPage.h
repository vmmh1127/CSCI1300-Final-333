#include <iostream>
#include <string>
#include "Player.h"
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class StartPage
{
    private:

    int choice;
    Player player;
    vector<string> name;
    vector<int> experience;
    vector<int> accuracy;
    vector<int> efficiency;
    vector<int> insight;
    vector<int> discoveryPoints;

    public:
    StartPage()
    {
        choice = 0;
    }
    void setUpCharacters(string filename)
    {
        ifstream file(filename);
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
            
            string temp_name, temp_experience, temp_accuracy, temp_efficiency, temp_insight, temp_discoveryPoints;

            getline(ss, temp_name, '|');
            name.push_back(temp_name);

            getline(ss, temp_experience, '|');
            experience.push_back(stoi(temp_experience));

            getline(ss, temp_accuracy, '|');
            accuracy.push_back(stoi(temp_accuracy));

            getline(ss, temp_efficiency, '|'); 
            efficiency.push_back(stoi(temp_efficiency));

            getline(ss, temp_insight, '|');
            insight.push_back(stoi(temp_insight));

            getline(ss, temp_discoveryPoints, '|');
            discoveryPoints.push_back(stoi(temp_discoveryPoints));

            i++;
        }
    }
    void displayMenu()
    {
        cout << "~Journey Through the Geneome~" << endl;

        cout << "Choose your character:" << endl;
        for (int i = 0; i < name.size(); i++)
        {
            cout << i + 1 << ") " << name[i] << " | Experience: " << experience[i] << " | Accuracy: " << accuracy[i] << " | Efficiency: " << efficiency[i] << " | Insight: " << insight[i] << " | Discovery Points: " << discoveryPoints[i] << endl;
        }
        cin >> choice;
        player.setName(name[choice - 1]);
        player.setExperience(experience[choice - 1]);
        player.setAccuracy(accuracy[choice - 1]);
        player.setEfficiency(efficiency[choice - 1]);
        player.setInsight(insight[choice - 1]);
        player.setDiscoverPoints(discoveryPoints[choice - 1]);

        /*cout << "Choose your adventure!" << endl;
        cout << "1) Start the study" << endl;
        cout << "2) Go through training" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            int character;
            cout << "Starting the study..." << endl;
            cout << "Pick your player: " << endl;
            cout << "1) DNA Double Helix" << endl;
            cout << "2) RNA Strand" << endl;
            cin >> character;
            break;
        case 2:
            cout << "Going through training..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }*/
    }
};