// This program is made to track the life totals of up to 4 players in a game of Magic: The Gathering. 
// It allows users to enter player names, add or subtract life from players, and exit the program when finished.

#include <iostream>
#include <string>
using namespace std;

int main() {
    int choice = 0;
    int life1 = 40, life2 = 40, life3 = 40, life4 = 40;
    string player1, player2, player3, player4;

    do {
        cout << "\n" << player1 <<": " << life1 << " life\n";
        cout << "\n" << player2 <<": " << life2 << " life\n";
        cout << "\n" << player3 <<": " << life3 << " life\n";
        cout << "\n" << player4 <<": " << life4 << " life\n";
        cout << "\n=== Main Menu ===\n";
        cout << "1. Enter Player Names\n";
        cout << "2. Add Life to a player\n";
        cout << "3. Subtract Life from a player\n";
        cout << "4. Add Commander Damage\n";
        cout << "5. Reset Player Life Totals\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Menu options for the user to select from, with a switch statement to handle the user's choice.
        switch (choice) {
            case 1:
                cout << "Enter Player Names selected.\n";
                cout << "Enter Player 1 Name: \n";
                cin >> player1;
                cout << "Enter Player 2 Name: \n";
                cin >> player2;
                cout << "Enter Player 3 Name: \n";
                cin >> player3;
                cout << "Enter Player 4 Name: \n";
                cin >> player4;
                break;
            case 2:
                cout << "Add Life to:\n";
                break;
            case 3:
                cout << "Subtract Life from:\n";
                break;
            case 4:
                cout << "Add Commander Damage to:\n";
                break;
            case 5:
                cout << "Reseting Player Life Totals.\n";
                life1 = 40;
                life2 = 40;
                life3 = 40;
                life4 = 40;
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;}