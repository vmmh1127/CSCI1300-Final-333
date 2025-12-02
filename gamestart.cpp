#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Board.h"
using namespace std;

int main() {
    Board d;
    d.displayBoard();
    //gameBoard.movePlayer(0); // Move player 1
    //gameBoard.displayBoard();
    //gameBoard.movePlayer(1); // Move player 2
    //gameBoard.displayBoard();

    cout << "Welcome to, 'CAN YOU BECOME THE LEAD GENOMICIST?'" << endl;
    cout << "Let's see if YOU have the WITS to become the Lead Genomicist of the World :)"<<endl;

//========================== PLAYER SETUP ====================================================
    
    string name1; string name2;
   
    cout << "Player 1, enter your name: "; cin>>name1;
    cout<< "Great "<<name1<<"! You are our first scientist \n";
    
//========================== CHOOSE CHARACTER FOR PLAYER 1 ===================================

    ifstream list_scientists;
    list_scientists.open("characters.txt");
    
    if(list_scientists.fail()){
        cout<<"Game failed, we are terribly sorry! (I'm bad at file streams ~ Game Developer)";
    }

    vector <string> character_names;
    string lines_character;
    int i_names;

    while(getline(list_scientists, lines_character)){
        stringstream ss(lines_character);
        string only_name;
        if (ss>>only_name){
            character_names.push_back(only_name);
        }
    }

    for ( i_names= 0; i_names<character_names.size(); i_names++){
        cout<<character_names[i_names]<<endl;
    }

    string selected_scientist;
    cin.ignore();
    cout<<"Wonderful! Now select a scientist from the list above: ";
    cout<<"(You can also see the respective attributes, CHOOSE WISELY!\n)"; cin>>selected_scientist;

//========================== CHOOSE CHARACTER FOR PLAYER 2 ===================================
    
    string selected_scientist2;
    cout << "Player 2, enter your name: "; cin>>name2;
    cout<< "Great "<<name2<<"! You are our first scientist \n";
    cout<<"Just like "<<name1<<", "<<name2<<", chose a character!"; cin>>selected_scientist2;
    //display list again but, remove the character name selected
    //we can copy vector for player 1 but, remove the character selected
    //or just .erase selected_scientist and display vector again 
//if line != selected_scientist > print 
//copy, paste into new vector > erase 
//give number instead

//store in new vector? 

    if(character_names(i_names)==selected_scientist){
      character_names.erase(character_names());
      
    }

    for ( i_names= 0; character_names.size(); i_names++){
        cout<<character_names[i_names]<<endl;
    }
    
//========================== CHOOSE PATH TYPE ================================================
    
    //WILL HAVE TO BE REPEATED FOR BOTH PLAYERS. 
    //CAN BOTH CHOSE ANY? OR ONLY 1 SPECIFIC TYPE FOR EACH PLAYER?

    cout<<"Before we start you can choose between two paths: \n";
    cout<<"'THE TRAINED' path means you receive some training (at a cost!) with a handy-dandy ADVISOR \nor jump directly into the game with 'THE JUMPER' path"<<endl;
    
    int path_select;
    
    cout<<"Enter 1 for 'THE TRAINED' or 2 for 'THE JUMPER' \n"; cin>>path_select;

    //edge case: 
    if (path_select != 1 && path_select !=2){
        cout<<"Enter 1 for 'THE TRAINED' or 2 for 'THE JUMPER' \n"; cin>>path_select;
    }

   /* if (path_select == 1)
    {
        path_select = 
    } 
    */

    //then display_board will modify according to the response. 
    //Do we need to create 3 instances of the board then? 
    //one where both are trained, both jumper, one trained and one jumper?
    //ASSUMING THAT PLAYER 1 IS TRAINED AND PLAYER 2 IS JUMPER
    //copied from displayBoard.cpp
    Board gameBoard;            
    gameBoard.displayBoard();
    gameBoard.movePlayer(0); // Move player 1
    gameBoard.displayBoard();
    gameBoard.movePlayer(1); // Move player 2
    gameBoard.displayBoard();

    return 0;
}