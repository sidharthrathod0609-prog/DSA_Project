#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>

using namespace std;

// Structure to store bank account details
class BankAccount {
public:
    string accountNumber;
    string customerId;
    string customerName;
    string accountType;
    double balance;
    string status;

    BankAccount() {
        accountNumber = "";
        customerId = "";
        customerName = "";
        accountType = "Savings";
        balance = 0.0;
        status = "Active";
    }

    BankAccount(string accNo, string cId, string cName, string accType, double bal, string stat = "Active") {
        accountNumber = accNo;
        customerId = cId;
        customerName = cName;
        accountType = accType;
        balance = bal;
        status = stat;
    }
};

#endif
