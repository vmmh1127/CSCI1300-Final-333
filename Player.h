#include <iostream>
#pragma once
using namespace std;
//Partner Name: Vidita Mulik
/*Player Class: Tracks players attributes, including Experience, Accuracy, Efficiency, 
Insight, and Discover Points. Includes methods for adjusting these attributes based on 
events. */

class Player {
    private:
        string characterName;
        string playerName;
        int experience_points;
        int accuracy_points;
        int efficiency_points;
        int insight_points;
        int discover_points;
        int pathChoice;

    public:
        // Constructor to initialize player stats
        Player();
        Player(string pn){
            playerName = pn;
        }

        //TO DO: constructor or function for player to choose character
        //cout to choose 
        //display the characters and attributes 
        //cout to choose for player 1
         

        // Methods to add points
        void addExperiencePoints(int points);
        void addAccuracyPoints(int points);
        void addEfficiencyPoints(int points);
        void addInsightPoints(int points);
        void addDiscoverPoints(int points);
        
        void setCharacterName(string n)
        {
            characterName = n;
        }
        int setExperience(int exp)
        {
            experience_points = exp;
            return experience_points;
        }
        int setAccuracy(int acc) 
        {
            accuracy_points = acc;
            return accuracy_points;
        }
        int setEfficiency(int eff) 
        {
            efficiency_points = eff;
            return efficiency_points;
        }
        int setInsight(int ins) 
        {
            insight_points = ins;
            return insight_points;
        }
        int setDiscoverPoints(int disc) 
        {
            discover_points = disc;
            return discover_points;
        }
        int setPathChoice(int choice)
        {
            pathChoice = choice;
            return pathChoice;
        }
        string setPlayerName(string n) 
        {
            playerName = n;
            return playerName;
        }

        // Methods to get current stats
        int getExperiencePoints();
        int getAccuracyPoints();
        int getEfficiencyPoints();
        int getInsightPoints();
        int getDiscoverPoints();
        string getCharacterName();
        int getPathChoice();
        string getPlayerName();
};

