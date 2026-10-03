#include<bits/stdc++.h>
using namespace std;

#include "../include/BankRepository.h"

// Constructor
BankRepository::BankRepository() {
    userLoggedIn = false;
    loggedInRole = "";
    currentAccount = "";
    nextTransactionId = 10001;

    // Connect to database if available
    dbClient.connect();

    // Load initial sample demonstration data
    seedSampleData();
}

// Simple PIN hashing helper for academic demonstration
string BankRepository::hashPIN(string pin) {
    unsigned long hash = 5381;
    for (char c : pin) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return to_string(hash);
}

// Check if an account number already exists
bool BankRepository::accountExists(string accountNumber) const {
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return true;
        }
    }
    return false;
}

// Helper: Get current date as string
static string getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buf[32];
    sprintf(buf, "%04d-%02d-%02d", 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
    return string(buf);
}

// Seed sample data as per specification Section 49
void BankRepository::seedSampleData() {
    // Sample Customer 1
    Customer c1("C1001", "Rahul Kumar", "9876543210", "rahul@gmail.com", hashPIN("1234"));
    customers.push_back(c1);
    BankAccount a1("100001", "C1001", "Rahul Kumar", "Savings", 10000.0, "Active");
    accounts.push_back(a1);

    // Sample Customer 2
    Customer c2("C1002", "Arjun Sharma", "9876543211", "arjun@gmail.com", hashPIN("4321"));
    customers.push_back(c2);
    BankAccount a2("100002", "C1002", "Arjun Sharma", "Savings", 5000.0, "Active");
    accounts.push_back(a2);

    // Initial seed transaction
    transactions.push_back(Transaction("T10001", "100001", "Deposit", 10000.0, "", getCurrentDate()));
    transactions.push_back(Transaction("T10002", "100002", "Deposit", 5000.0, "", getCurrentDate()));
    nextTransactionId = 10003;
}

// =========================================================
// MANDATORY DSA OPERATION 1: Create Account
// =========================================================
bool BankRepository::addAccount(string accNo, string cId, string cName, string phone, string email, string pin, string accType, double initialBalance) {
    // 1. Validation
    if (accNo.empty()) {
        cout << "[Error] Account number cannot be empty!\n";
        return false;
    }
    if (accountExists(accNo)) {
        cout << "[Error] Account already exists! Duplicate account number rejected.\n";
        return false;
    }
    if (initialBalance < 0) {
        cout << "[Error] Opening balance cannot be negative!\n";
        return false;
    }
    if (cName.empty()) {
        cout << "[Error] Customer name cannot be empty!\n";
        return false;
    }

    // 2. Create customer and account objects
    Customer newCust(cId, cName, phone, email, hashPIN(pin));
    BankAccount newAcc(accNo, cId, cName, accType, initialBalance, "Active");

    customers.push_back(newCust);
    accounts.push_back(newAcc);

    // 3. Log initial opening deposit if > 0
    if (initialBalance > 0) {
        string txId = "T" + to_string(nextTransactionId++);
        transactions.push_back(Transaction(txId, accNo, "Deposit", initialBalance, "", getCurrentDate()));
    }

    // 4. Persistence in MongoDB if connected
    if (dbClient.isConnected()) {
        string script = "mongosh \"" + dbClient.getURI() + "/" + dbClient.getDatabaseName() + "\" --quiet --eval " +
            "\"db.accounts.insertOne({account_number:'" + accNo + "', customer_id:'" + cId + "', customer_name:'" + cName + "', balance:" + to_string(initialBalance) + ", status:'Active'});\" > nul 2>&1";
        system(script.c_str());
    }

    cout << "\n[Success] Account created successfully for " << cName << " with Account No: " << accNo << "!\n";
    return true;
}

// =========================================================
// MANDATORY DSA OPERATION 2: Display All Accounts
// =========================================================
void BankRepository::displayAllAccounts() const {
    if (accounts.empty()) {
        cout << "\nNo accounts found.\n";
        return;
    }

    cout << "\n========================================================================================\n";
    cout << setw(15) << left << "Account No"
         << setw(15) << left << "Customer ID"
         << setw(22) << left << "Customer Name"
         << setw(14) << left << "Type"
         << setw(16) << left << "Balance (Rs.)"
         << setw(10) << left << "Status" << "\n";
    cout << "----------------------------------------------------------------------------------------\n";

    for (size_t i = 0; i < accounts.size(); i++) {
        cout << setw(15) << left << accounts[i].accountNumber
             << setw(15) << left << accounts[i].customerId
             << setw(22) << left << accounts[i].customerName
             << setw(14) << left << accounts[i].accountType
             << setw(16) << left << fixed << setprecision(2) << accounts[i].balance
             << setw(10) << left << accounts[i].status << "\n";
    }
    cout << "========================================================================================\n";
    cout << "Total accounts: " << accounts.size() << "\n";
}

// =========================================================
// MANDATORY DSA OPERATION 3: Search Account (Linear Search)
// Time Complexity: O(n)
// =========================================================
int BankRepository::searchAccount(string accountNumber) const {
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return (int)i; // Found at index i
        }
    }
    return -1; // Not found
}

// =========================================================
// MANDATORY DSA OPERATION 4: Deposit Money
// =========================================================
bool BankRepository::depositMoney(string accountNumber, double amount) {
    if (amount <= 0) {
        cout << "[Error] Deposit amount must be greater than zero!\n";
        return false;
    }

    int idx = searchAccount(accountNumber);
    if (idx == -1) {
        cout << "[Error] Account not found!\n";
        return false;
    }

    // Update balance
    accounts[idx].balance += amount;

    // Record transaction
    string txId = "T" + to_string(nextTransactionId++);
    transactions.push_back(Transaction(txId, accountNumber, "Deposit", amount, "", getCurrentDate()));

    // MongoDB update if connected
    if (dbClient.isConnected()) {
        string script = "mongosh \"" + dbClient.getURI() + "/" + dbClient.getDatabaseName() + "\" --quiet --eval " +
            "\"db.accounts.updateOne({account_number:'" + accountNumber + "'}, {$inc: {balance: " + to_string(amount) + "}});\" > nul 2>&1";
        system(script.c_str());
    }

    cout << "\n[Success] Deposit of Rs. " << fixed << setprecision(2) << amount << " successful!\n";
    cout << "New Balance: Rs. " << fixed << setprecision(2) << accounts[idx].balance << "\n";
    return true;
}

// =========================================================
// MANDATORY DSA OPERATION 5: Withdraw Money
// Sufficient Balance Validation
// =========================================================
bool BankRepository::withdrawMoney(string accountNumber, double amount) {
    if (amount <= 0) {
        cout << "[Error] Withdrawal amount must be greater than zero!\n";
        return false;
    }

    int idx = searchAccount(accountNumber);
    if (idx == -1) {
        cout << "[Error] Account not found!\n";
        return false;
    }

    // Edge case check: Insufficient balance
    if (accounts[idx].balance < amount) {
        cout << "[Error] Insufficient balance!\n";
        cout << "Available Balance: Rs. " << fixed << setprecision(2) << accounts[idx].balance << "\n";
        cout << "Attempted Withdrawal: Rs. " << fixed << setprecision(2) << amount << "\n";
        return false;
    }

    // Deduct balance
    accounts[idx].balance -= amount;

    // Record transaction
    string txId = "T" + to_string(nextTransactionId++);
    transactions.push_back(Transaction(txId, accountNumber, "Withdraw", amount, "", getCurrentDate()));

    // MongoDB update if connected
    if (dbClient.isConnected()) {
        string script = "mongosh \"" + dbClient.getURI() + "/" + dbClient.getDatabaseName() + "\" --quiet --eval " +
            "\"db.accounts.updateOne({account_number:'" + accountNumber + "'}, {$inc: {balance: " + to_string(-amount) + "}});\" > nul 2>&1";
        system(script.c_str());
    }

    cout << "\n[Success] Withdrawal of Rs. " << fixed << setprecision(2) << amount << " successful!\n";
    cout << "Remaining Balance: Rs. " << fixed << setprecision(2) << accounts[idx].balance << "\n";
    return true;
}

// =========================================================
// MANDATORY DSA OPERATION 6: Display Balance
// =========================================================
void BankRepository::showBalance(string accountNumber) const {
    int idx = searchAccount(accountNumber);
    if (idx == -1) {
        cout << "[Error] Account not found!\n";
        return;
    }

    cout << "\n---------------- Account Details ----------------\n";
    cout << "Account Number: " << accounts[idx].accountNumber << "\n";
    cout << "Account Holder: " << accounts[idx].customerName << "\n";
    cout << "Account Type  : " << accounts[idx].accountType << "\n";
    cout << "Current Balance: Rs. " << fixed << setprecision(2) << accounts[idx].balance << "\n";
    cout << "Status        : " << accounts[idx].status << "\n";
    cout << "-------------------------------------------------\n";
}

// =========================================================
// MANDATORY DSA OPERATION 7: Customer with Highest Balance
// Time Complexity: O(n)
// =========================================================
void BankRepository::showHighestBalance() const {
    if (accounts.empty()) {
        cout << "\nNo accounts found.\n";
        return;
    }

    int highestIdx = 0;
    for (size_t i = 1; i < accounts.size(); i++) {
        if (accounts[i].balance > accounts[highestIdx].balance) {
            highestIdx = (int)i;
        }
    }

    cout << "\n=========== CUSTOMER WITH HIGHEST BALANCE ===========\n";
    cout << "Account Number: " << accounts[highestIdx].accountNumber << "\n";
    cout << "Customer Name : " << accounts[highestIdx].customerName << "\n";
    cout << "Customer ID   : " << accounts[highestIdx].customerId << "\n";
    cout << "Balance       : Rs. " << fixed << setprecision(2) << accounts[highestIdx].balance << "\n";
    cout << "Account Type  : " << accounts[highestIdx].accountType << "\n";
    cout << "=====================================================\n";
}

// =========================================================
// MANDATORY DSA OPERATION 8: Sort Accounts by Balance (Descending)
// Algorithm: STL sort() -> Introsort (QuickSort + HeapSort + InsertionSort)
// Time Complexity: O(n log n)
// =========================================================
void BankRepository::sortAccountsByBalance() {
    if (accounts.empty()) {
        cout << "\nNo accounts found.\n";
        return;
    }

    // Sort descending by balance using lambda
    sort(accounts.begin(), accounts.end(), [](const BankAccount& a, const BankAccount& b) {
        return a.balance > b.balance;
    });

    cout << "\n[Success] Accounts sorted in descending order of balance (Highest First):\n";
    displayAllAccounts();
}

// =========================================================
// ADDITIONAL FEATURE 9: Transfer Money
// Atomic Check: Sender debit + Receiver credit
// =========================================================
bool BankRepository::transferMoney(string fromAcc, string toAcc, double amount) {
    // Edge case 1: Same account transfer
    if (fromAcc == toAcc) {
        cout << "[Error] Cannot transfer to the same account!\n";
        return false;
    }

    // Amount check
    if (amount <= 0) {
        cout << "[Error] Transfer amount must be greater than zero!\n";
        return false;
    }

    int senderIdx = searchAccount(fromAcc);
    if (senderIdx == -1) {
        cout << "[Error] Sender account (" << fromAcc << ") not found!\n";
        return false;
    }

    int receiverIdx = searchAccount(toAcc);
    if (receiverIdx == -1) {
        cout << "[Error] Receiver account (" << toAcc << ") not found!\n";
        return false;
    }

    // Sufficient balance check
    if (accounts[senderIdx].balance < amount) {
        cout << "[Error] Insufficient balance for transfer!\n";
        cout << "Sender Balance: Rs. " << fixed << setprecision(2) << accounts[senderIdx].balance << "\n";
        cout << "Transfer Amount: Rs. " << fixed << setprecision(2) << amount << "\n";
        return false;
    }

    // Execute transfer
    accounts[senderIdx].balance -= amount;
    accounts[receiverIdx].balance += amount;

    // Log transaction
    string txId = "T" + to_string(nextTransactionId++);
    transactions.push_back(Transaction(txId, fromAcc, "Transfer", amount, toAcc, getCurrentDate()));

    // MongoDB transfer update if connected
    if (dbClient.isConnected()) {
        string script = "mongosh \"" + dbClient.getURI() + "/" + dbClient.getDatabaseName() + "\" --quiet --eval " +
            "\"db.accounts.updateOne({account_number:'" + fromAcc + "'}, {$inc:{balance: " + to_string(-amount) + "}});" +
            "db.accounts.updateOne({account_number:'" + toAcc + "'}, {$inc:{balance: " + to_string(amount) + "}});\" > nul 2>&1";
        system(script.c_str());
    }

    cout << "\n[Success] Transferred Rs. " << fixed << setprecision(2) << amount
         << " from Account " << fromAcc << " to Account " << toAcc << " successfully!\n";
    cout << "Sender New Balance  : Rs. " << fixed << setprecision(2) << accounts[senderIdx].balance << "\n";
    cout << "Receiver New Balance: Rs. " << fixed << setprecision(2) << accounts[receiverIdx].balance << "\n";
    return true;
}

// =========================================================
// ADDITIONAL FEATURE 10: Show Transaction History
// =========================================================
void BankRepository::showTransactionHistory(string accountNumber) const {
    int idx = searchAccount(accountNumber);
    if (idx == -1) {
        cout << "[Error] Account not found!\n";
        return;
    }

    cout << "\n======================== TRANSACTION HISTORY FOR " << accountNumber << " ========================\n";
    cout << setw(12) << left << "Tx ID"
         << setw(16) << left << "Account"
         << setw(14) << left << "Type"
         << setw(16) << left << "Amount (Rs.)"
         << setw(16) << left << "To Account"
         << setw(14) << left << "Date" << "\n";
    cout << "------------------------------------------------------------------------------------\n";

    int count = 0;
    for (size_t i = 0; i < transactions.size(); i++) {
        if (transactions[i].accountNumber == accountNumber || transactions[i].toAccount == accountNumber) {
            cout << setw(12) << left << transactions[i].transactionId
                 << setw(16) << left << transactions[i].accountNumber
                 << setw(14) << left << transactions[i].type
                 << setw(16) << left << fixed << setprecision(2) << transactions[i].amount
                 << setw(16) << left << (transactions[i].toAccount.empty() ? "-" : transactions[i].toAccount)
                 << setw(14) << left << transactions[i].date << "\n";
            count++;
        }
    }

    if (count == 0) {
        cout << "No transactions found for this account.\n";
    }
    cout << "====================================================================================\n";
}

// =========================================================
// AUTHENTICATION: Customer Login
// =========================================================
bool BankRepository::customerLogin(string accountNumber, string pin) {
    int idx = searchAccount(accountNumber);
    if (idx == -1) {
        cout << "[Error] Account number not found!\n";
        return false;
    }

    string cId = accounts[idx].customerId;
    string hashed = hashPIN(pin);

    // Verify PIN with customer record
    for (size_t i = 0; i < customers.size(); i++) {
        if (customers[i].customerId == cId) {
            if (customers[i].pinHash == hashed) {
                userLoggedIn = true;
                loggedInRole = "customer";
                currentAccount = accountNumber;
                cout << "\n[Success] Welcome back, " << accounts[idx].customerName << "! Logged in as Customer.\n";
                return true;
            } else {
                cout << "[Error] Invalid PIN! Access denied.\n";
                return false;
            }
        }
    }

    cout << "[Error] Customer record mismatch!\n";
    return false;
}

// =========================================================
// AUTHENTICATION: Admin Login
// =========================================================
bool BankRepository::adminLogin(string username, string password) {
    if (username == "admin" && password == "admin123") {
        userLoggedIn = true;
        loggedInRole = "admin";
        currentAccount = "";
        cout << "\n[Success] Welcome, Administrator! Admin privileges granted.\n";
        return true;
    } else {
        cout << "[Error] Invalid admin username or password!\n";
        return false;
    }
}

// Logout
void BankRepository::logout() {
    if (!userLoggedIn) {
        cout << "\n[Info] No active session to logout.\n";
        return;
    }
    userLoggedIn = false;
    loggedInRole = "";
    currentAccount = "";
    cout << "\n[Success] Successfully logged out.\n";
}

bool BankRepository::isLoggedIn() const {
    return userLoggedIn;
}

string BankRepository::getLoggedInRole() const {
    return loggedInRole;
}

string BankRepository::getCurrentAccount() const {
    return currentAccount;
}

DBClient& BankRepository::getDBClient() {
    return dbClient;
}
