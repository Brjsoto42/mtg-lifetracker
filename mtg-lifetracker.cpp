// This program is made to track the life totals of up to 4 players in a game of Magic: The Gathering. 
// It allows users to enter player names, add or subtract life from players, and exit the program when finished.

#include <iostream>
using namespace std;

int main() {
    int choice = 0;

    do {
        cout << "\n=== Main Menu ===\n";
        cout << "1. Enter Player Names\n";
        cout << "2. Add Life to a player\n";
        cout << "3. Subtract Life from a player\n";
        cout << "4. Add Commander Damage\n";
        cout << "5. Reset Player Life Totals\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // You can handle choices here
        switch (choice) {
            case 1:
                cout << "Enter Player Names selected.\n";
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
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;}