#include <iostream>
#include <vector> 
#include <fstream>     
using namespace std;

//our DNA sequencing feauture will consist of two strands

//this function will also influence the players'stats


//we can generate random sequences which players will have to analyze
//we can have two lenghts of strands: short(6 base pairs) and long(10 base pairs)

//DUE TO REMOVING MAIN FUNCTION> CONVERTED GENERATION OF DNA INTO A FUNC, ASK FOR TWO DNA LENGTHS
// Generate a random DNA strand of length 10

void generate_two_strands(int dna_strand_length_long, int dna_strand_length_short){
 
    int longstrand_length;
    vector<char> dna_longstrand;

    for(int i = 0; i < longstrand_length; i++){
        int random_longSequence = rand() % 4; // Random number between 0 and 3
        switch(random_longSequence){
            //we are adding elements to the vector dna_longstrand, randomly
            case 0:
                dna_longstrand.push_back('A'); // Adenine
                break;
            case 1:
                dna_longstrand.push_back('T'); // Thymine
                break;
            case 2:
                dna_longstrand.push_back('C'); // Cytosine
                break;
            case 3:
                dna_longstrand.push_back('G'); // Guanine
                break;
        }
    }

    // Display the generated DNA strand
    cout<<"Generated DNA Strand: ";
    for (int i = 0; i < dna_longstrand.size(); i++) {
    cout<< dna_longstrand[i];
    }
    cout << endl;

    //===========================now we do the same but with length 6==========================
    int shortstrand_length;
    vector<char> dna_shortstrand;

    for(int i = 0; i < shortstrand_length; i++){
        int random_shortSequence = rand() % 4; // Random number between 0 and 3
        switch(random_shortSequence){
            case 0:
                dna_shortstrand.push_back('A'); // Adenine
                break;
            case 1:
                dna_shortstrand.push_back('T'); // Thymine
                break;
            case 2:
                dna_shortstrand.push_back('C'); // Cytosine
                break;
            case 3:
                dna_shortstrand.push_back('G'); // Guanine
                break;
        }
    }

    //Display the generated DNA strand
    cout<<"Generated DNA Strand: ";
    for (int i = 0; i < dna_shortstrand.size(); i++) {
    cout<<dna_shortstrand[i];
    }
    cout << endl;    
}

//TO DO: IT IS NOT RANDOM EVERY TIME WE RUN IT. FIGURE OUT WHY LATER !!!!!!!!!!!!!!!
//TO DO 2: WE GENERATE THE STRANDS 4 TIMES FOR EACH PLAYER, TO ANALYSE FOR THE DIFFERENT TASKS
//Writing code to generate four random strands for each player and store them in a 2D vector
//vector<vector<vector<char>>> player_strands(2, vector<vector<char>>(4));  


//now add functions for analyzing the strands 
//we can have 4 different analysis tasks corresponding to 4 colored tiles
//TO DO 3: How to make the functions impact the player's Traits? 
//TO DO 4: if user provides input to all functions, do we need to generate random dna strands?


//===========================BLUE function=======================================================
//BLUE - similarity score = total matches/total positions > compare same length strands
//we have to check which indexes match in both vectors and store that number in a variable total matches 
double strandSimilarity(string strand1, string strand2){
    
    if(strand1.length() != strand2.length()){
        cout << "Strands are not of equal length. Move on" << endl;
        return 0.0;
    }

    int total_matches = 0;
    if (strand1.length() == strand2.length()){
       
        for (int i = 0; i < strand1.length(); i++){
            if (strand1[i] == strand2[i]){
                total_matches++;
    
            }
        }
        
    }
    int similarity_score = total_matches/strand1.length();
    return similarity_score;
}

//===========================PINK function=======================================================
//Pink - similarity but unequal length =  > have to find out how to overlap > compare different length strands
//return = If the parameters are valid, return an int representing the starting index of the substring in the input strand where the best alignment with target strand occurs 
int bestStrandMatch(string input_strand, string target_strand)
//the strand with length 6 is target_strand 
//target_strand has to be optimally aligned with input_strand to get the maximum matches
//the strand with length 10 is input_strand
{
    int max_matches = 0;
    int best_start_index = -1;

    //code to align the strands to get maximum matches
    for (int i = 0; i <= input_strand.length() - target_strand.length(); i++) {
        int current_matches = 0;
        for (int j = 0; j < target_strand.length(); j++) {
            if (input_strand[i + j] == target_strand[j]) {
                current_matches++;
            }
        }
        if (current_matches > max_matches) {
            max_matches = current_matches;
            best_start_index = i;
        }
    }
    return best_start_index;
}

//===========================RED function=======================================================
//Red - mutation - to identify mutations between two strands
//input strand - length 10
//target strand - length 6
//identify substitution, insertion (extra), deletion

/*the function compares two DNA sequences to identify all types of mutations between them. 
It aligns the sequences based on the best possible match and processes them character by 
character, printing out any mutations as they are detected. */

//have code that algins the strands first to get maximum matches like in pink function
void identifyMutations(string input_strand, string target_strand) {
    int best_start_index = bestStrandMatch(input_strand, target_strand);
    if (best_start_index == -1) {
        cout << "No alignment possible." << endl;
        return;
    }
    //target strand is aligned optimally with input_strand starting at best_start_index
    int i = best_start_index; // Index for target_strand
    int j = 0; // Index for input_strand

    while (i < best_start_index + target_strand.length() && j < input_strand.length()) {
        if (input_strand[j] == target_strand[i - best_start_index]) {
            // No mutation
            i++;
            j++;
        } else {
            // Check for substitution
            cout << "Substitution at position " << j << ": " << input_strand[j] << " -> " << target_strand[i - best_start_index] << endl;
            i++;
            j++;
        }
    }
    // Check for any remaining insertions in input_strand
    while (j < input_strand.length()) {
        cout << "Insertion at position " << j << ": " << input_strand[j] << endl;
        j++;
    }
    // Check for any remaining deletions in target_strand
    while (i < best_start_index + target_strand.length()) {
        cout << "Deletion at position " << i - best_start_index << ": " << target_strand[i - best_start_index] << endl;
        i++;
    }
}

//===========================BROWN function=======================================================
//Brown - replace every 'T' with 'U' (thymine, uracil) 
//this converst DNA strand to RNA strand
string transcribeToRNA(string dna_strand){
    string rna_strand = dna_strand; // Start with a copy of the DNA strand
    for (int i = 0; i < rna_strand.length(); i++){
        if (rna_strand[i] == 'T'){
            rna_strand[i] = 'U'; // Replace Thymine with Uracil
        }
    }
    return rna_strand;
}

//TO DO: TEST ALL THE FUNCTIONS INDIVIDUALLY TO SEE IF THEY WORK AS EXPECTED
//TO DO 2: INTEGRATE THESE FUNCTIONS INTO THE BOARD CLASS AND CALL THEM WHEN A PLAYER LANDS ON A TILE
//TO DO 3: UPDATE PLAYER STATS BASED ON THE OUTCOMES OF THESE ANALYSES



//============================Purple function=======================================================
//as the player lands on purple tile, they encounter a riddle related to programming.
//these riddles can be sourced from text file name riddles.txt.

//function to read riddles from a text file and present them to the player
//player should be able to input their answer and their insight points increase by 500 if correct.

void presentRiddleToPlayer(int player_index){
    //when player lands on purple tile, this function is called
    cout << "You have landed on a Purple Tile! Solve the following riddle to earn 500 insight points." << endl;
    ifstream riddle_file("riddles.txt");
    if (riddle_file.fail()){
        cout << "Oops, game failed (I am bad at file streams ~ game developer)" << endl;
        return;
    }
    
    //the question is before the delimiter and the answer is after it
    //we can use '|' as delimiter

    //store the question in the variable riddle, and the answer in the variable answer
    string riddle;
    getline(riddle_file, riddle, '|');

    string answer;
    getline(riddle_file, answer);

    cout << "Riddle: " << riddle << endl;

    string player_answer;
    cout << "Your Answer: "; cin>> player_answer;
        
    getline(cin, player_answer);
    if (player_answer == answer){
        cout << "Correct! You have earned 500 insight points." << endl;
        //update player's insight points here
        //players[player_index].addInsightPoints(500); // Assuming a method to add points
    } else {
        cout << "Incorrect. The correct answer was: " << answer << endl;
    }

}

//=====================================GREEN TILES===============================================

/*Regular tiles are default colored green. For each path, ensure there is a minimum of 20 
regular tiles on the board. When triggered, randomly select an event from the random.txt 
file’s event list the impacts the player’s journey. Implement a 50% chance for an event to 
be triggered when landing on these regular tiles. */

//read data from a text file named random.txt
//remove discovery points if player has no advisor
//Description will be printed 
//PathType (0 = Training Fellowship; 1 = Direct Lab Assignment) 
//Advisor (0 = none; 1 = Dr. Aliquot; 2 = Dr. Assembler; 3 = Dr. Pop-Gen; 4 = Dr. Bio-Script; 5 = Dr. Loci)
//DiscoveryPoints lost. 

//when player lands on green tile, there is a 50% chance an event is triggered
//if event is triggered, read from random.txt and display event description, this will be the sentence before the first delimiter

//50% chance function
bool eventTriggered() {
    return rand() % 2 == 0; // Returns true 50% of the time
}

//function to read and then print the description of a random event from file random_events.txt
void triggerRandomEvent() {
    ifstream event("random.txt");
    if (event.fail()) {
        cout << "Error opening file." << endl;
        return;
    }

    // Read all events into a vector
    vector<string> events;
}