#include <iostream>
using namespace std;

/*Player Class: Tracks players attributes, including Experience, Accuracy, Efficiency, 
Insight, and Discover Points. Includes methods for adjusting these attributes based on 
events. */

class Player {
    private:
        int experience_points;
        int accuracy_points;
        int efficiency_points;
        int insight_points;
        int discover_points;

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

        // Methods to get current stats
        int getExperiencePoints();
        int getAccuracyPoints();
        int getEfficiencyPoints();
        int getInsightPoints();
        int getDiscoverPoints();
};

Player::Player(){
           experience_points = 0;
            accuracy_points = 0;
            efficiency_points = 0;
            insight_points = 0;
            discover_points = 0;
        }

// Methods to add points
        void Player::addExperiencePoints(int points) {
            experience_points += points;
        }
        void Player::addAccuracyPoints(int points) {
            accuracy_points += points;
        }
        void Player::addEfficiencyPoints(int points) {
            efficiency_points += points;
        }
        void Player::addInsightPoints(int points) {
            insight_points += points;
        }
        void Player::addDiscoverPoints(int points) {
            discover_points += points;
        }
// Methods to get current stats
        int Player::getExperiencePoints(){
            return experience_points;
        }           
        int Player::getAccuracyPoints() {
            return accuracy_points;
        }
        int Player::getEfficiencyPoints() {
            return efficiency_points;
        }
        int Player::getInsightPoints() {
            return insight_points;
        }
        int Player::getDiscoverPoints() {
            return discover_points;
        }
        
// TO DO: Integrate Player class into the main game loop to update stats based on tile events