#include <iostream>
#include <vector> 
#include <fstream>     
using namespace std;
#include "Player.h"

//our DNA sequencing feauture will consist of two strands

//this function will also influence the players'stats


//we can generate random sequences which players will have to analyze
//we can have two lenghts of strands: short(6 base pairs) and long(10 base pairs)

//DUE TO REMOVING MAIN FUNCTION> CONVERTED GENERATION OF DNA INTO A FUNC, ASK FOR TWO DNA LENGTHS
// Generate a random DNA strand of length 10
class DNA
{
    private:
    int l;
    vector<string> riddle;
    vector<string> ans;
    Player playerAdd;

    public:
    void generate_two_strands(int l, int s)
    {
    
        vector<char> dna_longstrand;

        for(int i = 0; i < l; i++){
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
        vector<char> dna_shortstrand;

        for(int i = 0; i < s; i++){
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


    //===========================BLUE function=======================================================

    //BLUE - similarity score = total matches/total positions > compare same length strands
    //we have to check which indexes match in both vectors and store that number in a variable total matches 
    void strandSimilarity(string strand1, string strand2){
        
        if(strand1.length() != strand2.length()){
            cout << "Strands are not of equal length. Move on" << endl;
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
        if (similarity_score >= 0.8)
        {            
            playerAdd.addDiscoverPoints(500);
            cout << "High Similarity! Score: " << similarity_score << endl;
            cout << "You have earned 500 discover points." << endl;
        }
        
        else if (similarity_score >= 0.5){
            playerAdd.addDiscoverPoints(200);
            cout << "Moderate Similarity! Score: " << similarity_score << endl;
            cout << "You have earned 200 discover points." << endl;
        }
        else {
            playerAdd.addDiscoverPoints(100);
            cout << "Low Similarity! Score: " << similarity_score << endl;
            cout << "You have earned 100 discover points." << endl;
        }
    }

    //===========================PINK function=======================================================
    //Pink - similarity but unequal length =  > have to find out how to overlap > compare different length strands
    //return = If the parameters are valid, return an int representing the starting index of the substring in the input strand where the best alignment with target strand occurs 
    int bestStrandMatch(string input_strand, string target_strand)
    //short strannd is target strand, long strand is input strand
    {
        int max_matches = 0;
        int best_start_index = -1;
        int current_matches = 0;

        //code to align the strands to get maximum matches
        for (int i = 0; i <= input_strand.length() - target_strand.length(); i++) {
            
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
        
        cout<<"For these dna strands, the best alignment starts at index: " << best_start_index << endl;
        cout<<"This will help you with identifying mutations!" << endl; 
        playerAdd.addExperiencePoints(100);
        cout << "You have earned 100 experience points." << endl;
        return 0;
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
    void identifyMutations(string input_strand, string target_strand)
    {
        //need to call pink function code here to align strands first
        //we need to call bestStrandMatch function here to get best_start_index
        int smatch = bestStrandMatch(input_strand, target_strand);

        if (smatch == -1)
        {
            cout << "No alignment possible." << endl;
        }
        //target strand is aligned optimally with input_strand starting at best_start_index
        int i = smatch; // Index for target_strand
        int j = 0; // Index for input_strand

        while (i < smatch + target_strand.length() && j < input_strand.length())
        {
            if (input_strand[j] == target_strand[i - smatch])
            {
                // No mutation
                i++;
                j++;
            }
            else 
            {
                // Check for substitution
                cout << "Substitution at position " << j << ": " << input_strand[j] << " -> " << target_strand[i - smatch] << endl;
                i++;
                j++;
            }
        }
        // Check for any remaining insertions in input_strand
        while (j < input_strand.length())
        {
            cout << "Insertion at position " << j << ": " << input_strand[j] << endl;
            j++;
        }
        // Check for any remaining deletions in target_strand
        while (i < smatch + target_strand.length())
        {
            cout << "Deletion at position " << i - smatch<< ": " << target_strand[i - smatch] << endl;
            i++;
        }

        playerAdd.addEfficiencyPoints(300);
        cout << "You have earned 300 experience points for identifying these mutations!" << endl;
        char response;
        cout << "Surprise question - Would you like to 'mutate' your score? (y/n)" << endl;
        cin >> response;
        if (response == 'y')
        {
            playerAdd.addExperiencePoints(1000);
            cout <<" Wow buddy, you got 1000 discover points!" << endl;
        }
        if (response == 'n')
        {
            cout << "No worries, keep going!" << endl;
        }
    }

    //===========================BROWN function=======================================================
    //Brown - replace every 'T' with 'U' (thymine, uracil) 
    //this converst DNA strand to RNA strand
    string transcribeToRNA(string dna_strand)
    {
        //playerAdd = p;
        string rna_strand = dna_strand; // Start with a copy of the DNA strand
        for (int i = 0; i < rna_strand.length(); i++)
        {
            if (rna_strand[i] == 'T')
            {
                rna_strand[i] = 'U'; // Replace Thymine with Uracil
            }
        }
        playerAdd.addExperiencePoints(200);
        cout << "You have earned 200 discover points for transcribing DNA to RNA!" << endl;
        cout << "Transcribed RNA Strand: " << rna_strand << endl;
        return rna_strand;
    }

    //============================Purple function=======================================================
    //as the player lands on purple tile, they encounter a riddle related to programming.
     void setRandomRiddles(string filename)
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

                string r, a;

                getline(ss, r, '|');
                riddle.push_back(r);

                getline(ss, a);
                ans.push_back(a);

                i++;
            }
        }
    void presentRiddleToPlayer()
    {
        //when player lands on purple tile, this function is called
        cout << "You have landed on a Purple Tile! Solve the following riddle to earn 500 insight points." << endl;
        
        //the question is before the delimiter and the answer is after it
        int num = riddle.size();
        int randomIndex = rand() % num;

        //string riddle;
        //getline(riddle_file, riddle, '|');
        string rid = riddle[randomIndex];

        //string answer;

        cout << "Riddle: " << riddle[randomIndex] << endl;

        string player_answer;
        cout << "Your Answer: ";
        cin>> player_answer;
            
        getline(cin, player_answer); // To capture the full line including spaces
        if (ans[randomIndex]==player_answer)
        {
            cout << "Correct! You have earned 500 experience points." << endl;
            //update player's insight points here
            //players[player_index].addInsightPoints(500); // Assuming a method to add points
        } else 
        {
            cout << "Incorrect. The correct answer was: " << ans[randomIndex] << endl;
        }

    }
};