#include <iostream>
using namespace std;

class StartPage
{
    private:

    int choice;

    public:
    StartPage()
    {
        choice = 0;
    }
    void displayMenu()
    {
        cout << "~Journey Through the Geneome~" << endl;
        cout << "Choose your adventure!" << endl;
        cout << "1) Start the study" << endl;
        cout << "2) Go through training" << endl;
        cin >> choice;

        switch (choice) {
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
    }
    }
 

};