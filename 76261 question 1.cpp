#include <iostream>
using namespace std;

int main() {
    const int PIN = 1234;   // Correct PIN
    int enteredPIN;
    int attempts = 0;
    double balance = 1000.0; // Initial balance
    int choice;
    double amount;

    // PIN verification with 3 attempts
    while (attempts < 3) {
        cout << "Enter your PIN: ";
        cin >> enteredPIN;

        if (enteredPIN == PIN) {
            cout << "PIN accepted. Welcome!\n";

            // ATM Menu Loop
            do {
                cout << "\n===== ATM Menu =====\n";
                cout << "1. Check Balance\n";
                cout << "2. Deposit\n";
                cout << "3. Withdraw\n";
                cout << "4. Exit\n";
                cout << "Choose an option: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        cout << "Your current balance is: $" << balance << endl;
                        break;

                    case 2:
                        cout << "Enter amount to deposit: $";
                        cin >> amount;
                        if (amount > 0) {
                            balance += amount;
                            cout << "Deposit successful. New balance: $" << balance << endl;
                        } else {
                            cout << "Invalid deposit amount.\n";
                        }
                        break;

                    case 3:
                        cout << "Enter amount to withdraw: $";
                        cin >> amount;
                        if (amount > balance) {
                            cout << "Insufficient balance. Withdrawal denied.\n";
                        } else if (amount > 0) {
                            balance -= amount;
                            cout << "Withdrawal successful. New balance: $" << balance << endl;
                        } else {
                            cout << "Invalid withdrawal amount.\n";
                        }
                        break;

                    case 4:
                        cout << "Thank you for using the ATM. Goodbye!\n";
                        break;

                    default:
                        cout << "Invalid option. Please try again.\n";
                }
            } while (choice != 4);

            return 0; // Exit program after user chooses Exit
        } else {
            attempts++;
            cout << "Incorrect PIN. Attempts left: " << (3 - attempts) << endl;
        }
    }

    cout << "Too many incorrect attempts. Card blocked.\n";
    return 0;
}

