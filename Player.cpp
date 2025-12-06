#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(){
            experience_points = 0;
            accuracy_points = 0;
            efficiency_points = 0;
            insight_points = 0;
            discover_points = 0;
        }

// Setters (Updates points) =======================================
        void Player::addExperiencePoints(int points)
        {
            experience_points += points;
        }
        void Player::addAccuracyPoints(int points)
        {
            accuracy_points += points;
        }
        void Player::addEfficiencyPoints(int points)
        {
            efficiency_points += points;
        }
        void Player::addInsightPoints(int points)
        {
            insight_points += points;
        }
        void Player::addDiscoverPoints(int points)
        {
            discover_points += points;
        }
// Getters =======================================
        int Player::getExperiencePoints()
        {
            return experience_points;
        }           
        int Player::getAccuracyPoints()
        {
            return accuracy_points;
        }
        int Player::getEfficiencyPoints()
        {
            return efficiency_points;
        }
        int Player::getInsightPoints()
        {
            return insight_points;
        }
        int Player::getDiscoverPoints()
        {
            return discover_points;
        }
        string Player::getCharacterName()
        {
            return characterName;
        }
        int Player::getPathChoice()
        {
            return pathChoice;
        }
        string Player::getPlayerName()
        {
            return playerName;
        }
        
        
// TO DO: Integrate Player class into the main game loop to update stats based on tile events