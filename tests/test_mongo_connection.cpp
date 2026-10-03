#include<bits/stdc++.h>
using namespace std;

#include "../include/DBClient.h"

int main() {
    cout << "\n=======================================================\n";
    cout << "          MONGODB DATABASE CONNECTION TEST             \n";
    cout << "=======================================================\n";

    DBClient client;
    client.printConnectionInfo();

    cout << "\nTesting connection to MongoDB server...\n";
    bool success = client.connect();

    if (success) {
        cout << "\n[PASS] Connected to MongoDB successfully!\n";
        cout << "Database: " << client.getDatabaseName() << " is reachable and ready.\n";
    } else {
        cout << "\n[INFO] Could not connect to MongoDB server.\n";
        cout << "Reason: Server is offline, or connection URI needs updating.\n";
        cout << "Note: You can update MONGODB_URI in the .env file once you have the connection string.\n";
    }
    cout << "=======================================================\n\n";

    return success ? 0 : 1;
}
