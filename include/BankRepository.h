#ifndef BANK_REPOSITORY_H
#define BANK_REPOSITORY_H

#include <string>
#include <vector>
#include "Customer.h"
#include "BankAccount.h"
#include "Transaction.h"
#include "DBClient.h"

using namespace std;

class BankRepository {
private:
    vector<Customer> customers;
    vector<BankAccount> accounts;
    vector<Transaction> transactions;
    DBClient dbClient;

    bool userLoggedIn;
    string loggedInRole;     // "customer", "admin", or ""
    string currentAccount;   // account number if customer logged in

    int nextTransactionId;

public:
    BankRepository();

    // Mandatory Operation 1: Create Account
    bool addAccount(string accNo, string cId, string cName, string phone, string email, string pin, string accType, double initialBalance);

    // Mandatory Operation 2: Display All Accounts
    void displayAllAccounts() const;

    // Mandatory Operation 3: Search Customer by Account Number
    int searchAccount(string accountNumber) const;

    // Mandatory Operation 4: Deposit Money
    bool depositMoney(string accountNumber, double amount);

    // Mandatory Operation 5: Withdraw Money (with sufficient balance check)
    bool withdrawMoney(string accountNumber, double amount);

    // Mandatory Operation 6: Display Account Balance
    void showBalance(string accountNumber) const;

    // Mandatory Operation 7: Find Customer with Highest Balance
    void showHighestBalance() const;

    // Mandatory Operation 8: Sort Customers by Balance (Descending)
    void sortAccountsByBalance();

    // Additional Features
    bool transferMoney(string fromAcc, string toAcc, double amount);
    void showTransactionHistory(string accountNumber) const;
    bool customerLogin(string accountNumber, string pin);
    bool adminLogin(string username, string password);
    void logout();

    // State getters
    bool isLoggedIn() const;
    string getLoggedInRole() const;
    string getCurrentAccount() const;
    DBClient& getDBClient();

    // Helpers
    bool accountExists(string accountNumber) const;
    static string hashPIN(string pin);
    void seedSampleData();
};

#endif
