#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

// Structure to store customer details
class Customer {
public:
    string customerId;
    string name;
    string phone;
    string email;
    string pinHash;

    Customer() {
        customerId = "";
        name = "";
        phone = "";
        email = "";
        pinHash = "";
    }

    Customer(string id, string n, string p, string e, string pin) {
        customerId = id;
        name = n;
        phone = p;
        email = e;
        pinHash = pin;
    }
};

#endif
