// This program is made to track the life totals of up to 4 players in a game of Magic: The Gathering. 
// It allows users to enter player names, add or subtract life from players, and exit the program when finished.

#include <iostream>
#include <string>

using namespace std;

int main() {
    int choice = 0;
    int life1 = 40, life2 = 40, life3 = 40, life4 = 40; // Starting life totals for each player
    string player1, player2, player3, player4;  // Variables to store player names
    string cmdr1, cmdr2, cmdr3, cmdr4;  // Variables to store commander names for each player

    int cmdrDmg[4][4] = {0}; // Array to track commander damage for each player

    do {
        cout << "\n" << player1 <<": " << life1 << " life\n"; //Displays each player's name and current life total
        cout << "\n" << player2 <<": " << life2 << " life\n";
        cout << "\n" << player3 <<": " << life3 << " life\n";
        cout << "\n" << player4 <<": " << life4 << " life\n";
        
        cout << "\n=== Main Menu ===\n"; // Displays the main menu options for the user
        cout << "1. Enter Player Names\n";
        cout << "2. Enter Players Commander Names\n";
        cout << "3. Add Life to a player\n";
        cout << "4. Subtract Life from a player\n";
        cout << "5. Add Commander Damage\n";
        cout << "6. View Commander Damage\n";
        cout << "7. Reset Game\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            
            case 1: // Allows the user to enter the names of the players in the game
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
            
            case 2: // Allows the user to enter the commander names for each player in the game
                cout << "Enter Players Commander Names selected.\n";
                cout << "Enter " << player1 << "'s Commander Name: \n";
                cin >> cmdr1;
                cout << "Enter " << player2 << "'s Commander Name: \n";
                cin >> cmdr2;
                cout << "Enter " << player3 << "'s Commander Name: \n";
                cin >> cmdr3;
                cout << "Enter " << player4 << "'s Commander Name: \n";
                cin >> cmdr4;
                break;
            
            case 3: // Allows the user to add life to a player
                int addChoice, addAmount;
                cout << "Add Life to:\n";
                cout << "1. " << player1 << "\n";
                cout << "2. " << player2 << "\n";
                cout << "3. " << player3 << "\n";
                cout << "4. " << player4 << "\n";
                cin >> addChoice;
                cout << "Enter amount to add: ";
                cin >> addAmount;
                switch (addChoice) {
                    case 1:
                        life1 += addAmount;
                        break;
                    case 2:
                        life2 += addAmount;
                        break;
                    case 3:
                        life3 += addAmount;
                        break;
                    case 4:
                        life4 += addAmount;
                        break;
                    default:
                        cout << "Invalid player choice.\n";
                }
                break;

            case 4: // Allows the user to subtract life from a player
                int subChoice, subAmount;
                cout << "Subtract Life from:\n";
                cout << "1. " << player1 << "\n";
                cout << "2. " << player2 << "\n";
                cout << "3. " << player3 << "\n";
                cout << "4. " << player4 << "\n";
                cin >> subChoice;
                cout << "Enter amount to subtract: ";
                cin >> subAmount;
                switch (subChoice) {
                    case 1:
                        life1 -= subAmount;
                        break;
                    case 2:
                        life2 -= subAmount;
                        break;
                    case 3:
                        life3 -= subAmount;
                        break;
                    case 4:
                        life4 -= subAmount;
                        break;
                    default:
                        cout << "Invalid player choice.\n";
                }
                break;

            case 5: { // Allows the user to record commander damage
                int attacker, defender, cmdrDamage;

                cout << "Who is attacking?\n";
                cout << "1. " << player1 << " (" << cmdr1 << ")\n";
                cout << "2. " << player2 << " (" << cmdr2 << ")\n";
                cout << "3. " << player3 << " (" << cmdr3 << ")\n";
                cout << "4. " << player4 << " (" << cmdr4 << ")\n";
                cin >> attacker;

                cout << "Who is defending?\n";
                cout << "1. " << player1 << "\n";
                cout << "2. " << player2 << "\n";
                cout << "3. " << player3 << "\n";
                cout << "4. " << player4 << "\n";
                cin >> defender;

                cout << "Enter commander damage amount: ";
                cin >> cmdrDamage;

                attacker--; 
                defender--;

                if (attacker < 0 || attacker > 3 || defender < 0 || defender > 3 || attacker == defender) { // Validate input for attacker and defender
                    cout << "Invalid selection.\n";
                    break;
                }

                cmdrDmg[defender][attacker] += cmdrDamage;

                // Subtract life from defending player
                switch (defender) {
                    case 0:
                        life1 -= cmdrDamage;
                        break;
                    case 1:
                        life2 -= cmdrDamage;
                        break;
                    case 2:
                        life3 -= cmdrDamage;
                        break;
                    case 3:
                        life4 -= cmdrDamage;
                        break;
                }

                string players[4] = {player1, player2, player3, player4};

                cout << "Added " << cmdrDamage << " commander damage from "
                    << players[attacker]
                    << " to "
                    << players[defender]
                    << ".\n";

                if (cmdrDmg[defender][attacker] >= 21) {
                    cout << ">>> " << players[defender]
                        << " loses to commander damage from "
                        << players[attacker]
                        << "!\n";
                }

                break;
            }

            case 6: // Displays the commander damage each player has taken from each opponent
                cout << "\n=== Commander Damage ===\n";

                cout << player1 << " has taken:\n";
                cout << cmdrDmg[0][1] << " from " << player2 << " (" << cmdr2 << ")\n";
                cout << cmdrDmg[0][2] << " from " << player3 << " (" << cmdr3 << ")\n";
                cout << cmdrDmg[0][3] << " from " << player4 << " (" << cmdr4 << ")\n\n";

                cout << player2 << " has taken:\n";
                cout << cmdrDmg[1][0] << " from " << player1 << " (" << cmdr1 << ")\n";
                cout << cmdrDmg[1][2] << " from " << player3 << " (" << cmdr3 << ")\n";
                cout << cmdrDmg[1][3] << " from " << player4 << " (" << cmdr4 << ")\n\n";

                cout << player3 << " has taken:\n";
                cout << cmdrDmg[2][0] << " from " << player1 << " (" << cmdr1 << ")\n";
                cout << cmdrDmg[2][1] << " from " << player2 << " (" << cmdr2 << ")\n";
                cout << cmdrDmg[2][3] << " from " << player4 << " (" << cmdr4 << ")\n\n";

                cout << player4 << " has taken:\n";
                cout << cmdrDmg[3][0] << " from " << player1 << " (" << cmdr1 << ")\n";
                cout << cmdrDmg[3][1] << " from " << player2 << " (" << cmdr2 << ")\n";
                cout << cmdrDmg[3][2] << " from " << player3 << " (" << cmdr3 << ")\n\n";

                break;

            case 7: // Resets the game
                cout << "Resetting Game.\n";
                life1 = life2 = life3 = life4 = 40; // Reset life totals to 40

                for (int i = 0; i < 4; i++) {   // Reset commander damage array
                    for (int j = 0; j < 4; j++) {
                        cmdrDmg[i][j] = 0;
                    }
                }
                break;

            case 8: // Exits the program
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 8);

    return 0;}