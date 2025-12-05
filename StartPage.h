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
    Player player2;
    vector<string> name;
    vector<int> experience;
    vector<int> accuracy;
    vector<int> efficiency;
    vector<int> insight;
    vector<int> discoveryPoints;
    int pathChoice0;
    int pathChoice1;

    public:
    StartPage()
    {
        choice = 0;
    }
    void namesStartPage(string p1Name, string p2Name)
    {
        player.setPlayerName(p1Name);
        player2.setPlayerName(p2Name);
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
        string playerName1;
        string playerName2;
        cout << "Welcome to, 'JOURNEY OF THE GENOMICIST'" << endl;
        cout << "Let's see if YOU have the WITS to become the Lead Genomicist of the World :)"<<endl;
        cout <<"PLayer 1, enter the phrase by thy which you art called by the mortals:"<<endl; 
        cin>>playerName1;
        player.setPlayerName(playerName1);

        cin.clear();

        cout << "PLayer 2 gimmie ur name: " << endl;
        cin>>playerName2;
        player2.setPlayerName(playerName2);
        cin.clear();

        cout << player.getPlayerName() << ", Choose your character:" << endl;
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

        cout << "You have chosen: " << player.getName() << endl;

        //erase chosen character from vectors to prevent player 2 from choosing same character
        name.erase(name.begin() + (choice - 1));
        experience.erase(experience.begin() + (choice - 1));
        accuracy.erase(accuracy.begin() + (choice - 1));
        efficiency.erase(efficiency.begin() + (choice - 1));
        insight.erase(insight.begin() + (choice - 1));
        discoveryPoints.erase(discoveryPoints.begin() + (choice - 1));

        cin.clear();

        cout << player2.getPlayerName() << ", Choose your character:" << endl;
        for (int i = 0; i < name.size(); i++)
        {
            cout << i + 1 << ") " << name[i] << " | Experience: " << experience[i] << " | Accuracy: " << accuracy[i] << " | Efficiency: " << efficiency[i] << " | Insight: " << insight[i] << " | Discovery Points: " << discoveryPoints[i] << endl;
        }
        cin >> choice;
        player2.setName(name[choice - 1]);
        player2.setExperience(experience[choice - 1]);
        player2.setAccuracy(accuracy[choice - 1]);
        player2.setEfficiency(efficiency[choice - 1]);
        player2.setInsight(insight[choice - 1]);
        player2.setDiscoverPoints(discoveryPoints[choice - 1]);

        cout << "You have chosen: " << player2.getName() << endl;

    }
    //========================== CHOOSE PATH TYPE ================================================
    void path_type(){
        int path_choice;
        cout<<"Player 1, Choose your path type: (Enter 0 or 1)\n";
        cout<<"'THE TRAINED' or jump directly into the game with 'THE JUMPER' path"<<endl;
        cout<<"0) THE TRAINED - path means you receive some training (at a cost!) with a handy-dandy ADVISOR \n";
        cout<<"1) THE JUMPER - jump directly onto your journey (P.S. it will be harder for you \n HEHEHEHEHHE) "<<endl;
        cin>>path_choice;
        player.setPathChoice(path_choice);

        switch (path_choice)
        {
        case 0:
            cout<<"You have chosen THE TRAINED path! An advisor will be with you throughout your journey. \n";
            break;
        case 1:
            cout<<"You have chosen THE JUMPER path! Good luck out there! \n";
            break;
        default:
            cout<<"Invalid choice. Please enter 0 or 1. \n";
            cin>>path_choice;
            break;
        }

        cin.clear();

        cout<<"Player 2, Choose your path type: (Enter 0 or 1)\n";
        cout<<"'THE TRAINED' or jump directly into the game with 'THE JUMPER' path"<<endl;
        cout<<"0) THE TRAINED - path means you receive some training (at a cost!) with a handy-dandy ADVISOR \n";
        cout<<"1) THE JUMPER - jump directly onto your journey (P.S. it will be harder for you \n HEHEHEHEHHE) "<<endl;
        cin>>path_choice;
        player2.setPathChoice(path_choice);

        switch (path_choice)
        {
        case 0:
            cout<<"You have chosen THE TRAINED path! An advisor will be with you throughout your journey. \n";
            break;
        case 1:
            cout<<"You have chosen THE JUMPER path! Good luck out there! \n";
            break;
        default:
            cout<<"Invalid choice. Please enter 0 or 1. \n";
            cin>>path_choice;
            break;
        }
    }
};