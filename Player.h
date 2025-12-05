#include <iostream>
#pragma once
using namespace std;

/*Player Class: Tracks players attributes, including Experience, Accuracy, Efficiency, 
Insight, and Discover Points. Includes methods for adjusting these attributes based on 
events. */

class Player {
    private:
        string name;
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
        void setName(string playerName) {
            name = playerName;
        }
        void setExperience(int exp) {
            experience_points = exp;
        }
        void setAccuracy(int acc) {
            accuracy_points = acc;
        }
        void setEfficiency(int eff) {
            efficiency_points = eff;
        }
        void setInsight(int ins) {
            insight_points = ins;
        }
        void setDiscoverPoints(int disc) {
            discover_points = disc;
        }
        void setPathChoice(int choice) {
            pathChoice = choice;
        }
        void setPlayerName(string pName) {
            playerName = pName;
        }

        // Methods to get current stats
        int getExperiencePoints();
        int getAccuracyPoints();
        int getEfficiencyPoints();
        int getInsightPoints();
        int getDiscoverPoints();
        string getName();
        int getPathChoice();
        string getPlayerName();
};

