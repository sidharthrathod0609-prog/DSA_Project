#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;

// Structure to store transaction log details
class Transaction {
public:
    string transactionId;
    string accountNumber;
    string type;          // Deposit, Withdraw, Transfer
    double amount;
    string toAccount;     // Target account for transfer, empty otherwise
    string date;

    Transaction() {
        transactionId = "";
        accountNumber = "";
        type = "";
        amount = 0.0;
        toAccount = "";
        date = "";
    }

    Transaction(string txId, string accNo, string t, double amt, string toAcc, string d) {
        transactionId = txId;
        accountNumber = accNo;
        type = t;
        amount = amt;
        toAccount = toAcc;
        date = d;
    }
};

#endif
