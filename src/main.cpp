#include<bits/stdc++.h>
using namespace std;

#include "../include/BankRepository.h"

// Helper function to safely read integer choice from console
int readChoice() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1; // Indicates invalid input
    }
    return choice;
}

// Helper function to safely read double amount
double readAmount(string prompt) {
    double amt;
    while (true) {
        cout << prompt;
        cin >> amt;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[Error] Invalid numeric input. Please enter a valid number.\n";
        } else {
            return amt;
        }
    }
}

// Helper function to read string line
string readString(string prompt) {
    cout << prompt;
    string val;
    cin >> ws;
    getline(cin, val);
    return val;
}

int main() {
    BankRepository bank;

    cout << "\n================================================\n";
    cout << "             WELCOME TO OUR BANK                \n";
    cout << "================================================\n";
    bank.getDBClient().printConnectionInfo();

    while (true) {
        cout << "\n================================================\n";
        cout << "                  MAIN MENU                     \n";
        cout << "================================================\n";
        if (bank.isLoggedIn()) {
            cout << " [Active Session: " << bank.getLoggedInRole();
            if (bank.getLoggedInRole() == "customer") {
                cout << " | Acc: " << bank.getCurrentAccount();
            }
            cout << "]\n";
        }
        cout << "1. Create New Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Search Customer\n";
        cout << "4. Deposit Money\n";
        cout << "5. Withdraw Money\n";
        cout << "6. Check Balance\n";
        cout << "7. Highest Balance\n";
        cout << "8. Sort Accounts\n";
        cout << "9. Transfer Money\n";
        cout << "10. Transaction History\n";
        cout << "11. Customer Login\n";
        cout << "12. Admin Login\n";
        cout << "13. Logout\n";
        cout << "0. Exit\n";
        cout << "------------------------------------------------\n";

        int choice = readChoice();

        switch (choice) {
            case 1: {
                cout << "\n--- CREATE NEW ACCOUNT ---\n";
                string accNo = readString("Enter Account Number: ");
                string cId   = readString("Enter Customer ID: ");
                string name  = readString("Enter Customer Name: ");
                string phone = readString("Enter Phone Number: ");
                string email = readString("Enter Email: ");
                string pin   = readString("Set 4-digit PIN: ");
                string type  = readString("Enter Account Type (Savings/Current): ");
                double balance = readAmount("Enter Opening Balance (Rs.): ");

                bank.addAccount(accNo, cId, name, phone, email, pin, type, balance);
                break;
            }

            case 2: {
                cout << "\n--- ALL BANK ACCOUNTS ---\n";
                bank.displayAllAccounts();
                break;
            }

            case 3: {
                cout << "\n--- SEARCH ACCOUNT ---\n";
                string accNo = readString("Enter Account Number to search: ");
                int idx = bank.searchAccount(accNo);
                if (idx != -1) {
                    cout << "[Found] Account exists in system (Record Index: " << idx << ")\n";
                    bank.showBalance(accNo);
                } else {
                    cout << "[Error] Account not found.\n";
                }
                break;
            }

            case 4: {
                cout << "\n--- DEPOSIT MONEY ---\n";
                string accNo;
                if (bank.isLoggedIn() && bank.getLoggedInRole() == "customer") {
                    accNo = bank.getCurrentAccount();
                    cout << "Using active logged-in account: " << accNo << "\n";
                } else {
                    accNo = readString("Enter Account Number: ");
                }
                double amt = readAmount("Enter Deposit Amount (Rs.): ");
                bank.depositMoney(accNo, amt);
                break;
            }

            case 5: {
                cout << "\n--- WITHDRAW MONEY ---\n";
                string accNo;
                if (bank.isLoggedIn() && bank.getLoggedInRole() == "customer") {
                    accNo = bank.getCurrentAccount();
                    cout << "Using active logged-in account: " << accNo << "\n";
                } else {
                    accNo = readString("Enter Account Number: ");
                }
                double amt = readAmount("Enter Withdrawal Amount (Rs.): ");
                bank.withdrawMoney(accNo, amt);
                break;
            }

            case 6: {
                cout << "\n--- CHECK BALANCE ---\n";
                string accNo;
                if (bank.isLoggedIn() && bank.getLoggedInRole() == "customer") {
                    accNo = bank.getCurrentAccount();
                } else {
                    accNo = readString("Enter Account Number: ");
                }
                bank.showBalance(accNo);
                break;
            }

            case 7: {
                bank.showHighestBalance();
                break;
            }

            case 8: {
                bank.sortAccountsByBalance();
                break;
            }

            case 9: {
                cout << "\n--- TRANSFER MONEY ---\n";
                string fromAcc;
                if (bank.isLoggedIn() && bank.getLoggedInRole() == "customer") {
                    fromAcc = bank.getCurrentAccount();
                    cout << "Sender Account: " << fromAcc << "\n";
                } else {
                    fromAcc = readString("Enter Sender Account Number: ");
                }
                string toAcc = readString("Enter Receiver Account Number: ");
                double amt = readAmount("Enter Transfer Amount (Rs.): ");
                bank.transferMoney(fromAcc, toAcc, amt);
                break;
            }

            case 10: {
                cout << "\n--- TRANSACTION HISTORY ---\n";
                string accNo;
                if (bank.isLoggedIn() && bank.getLoggedInRole() == "customer") {
                    accNo = bank.getCurrentAccount();
                } else {
                    accNo = readString("Enter Account Number: ");
                }
                bank.showTransactionHistory(accNo);
                break;
            }

            case 11: {
                cout << "\n--- CUSTOMER LOGIN ---\n";
                string accNo = readString("Enter Account Number: ");
                string pin   = readString("Enter 4-digit PIN: ");
                bank.customerLogin(accNo, pin);
                break;
            }

            case 12: {
                cout << "\n--- ADMIN LOGIN ---\n";
                string user = readString("Enter Admin Username: ");
                string pass = readString("Enter Admin Password: ");
                bank.adminLogin(user, pass);
                break;
            }

            case 13: {
                bank.logout();
                break;
            }

            case 0: {
                cout << "\nThank you for using our Bank Management System. Goodbye!\n\n";
                return 0;
            }

            default: {
                cout << "\n[Error] Invalid choice! Please select an option between 0 and 13.\n";
                break;
            }
        }
    }

    return 0;
}
