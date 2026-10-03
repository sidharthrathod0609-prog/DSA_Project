#include<bits/stdc++.h>
using namespace std;

#include "../include/DBClient.h"

DBClient::DBClient() {
    connected = false;
    mongoURI = "mongodb://localhost:27017";
    databaseName = "bankdb";
    loadConfig();
}

void DBClient::loadConfig() {
    // 1. Try reading from environment variable
    const char* envUri = getenv("MONGODB_URI");
    if (envUri != nullptr && string(envUri).length() > 0) {
        mongoURI = envUri;
    }

    const char* envDb = getenv("MONGODB_DATABASE");
    if (envDb != nullptr && string(envDb).length() > 0) {
        databaseName = envDb;
    }

    // 2. Fallback to .env file if available
    ifstream envFile(".env");
    if (envFile.is_open()) {
        string line;
        while (getline(envFile, line)) {
            // Trim leading spaces
            size_t first = line.find_first_not_of(" \t\r\n");
            if (first == string::npos || line[first] == '#') continue;

            size_t eqPos = line.find('=');
            if (eqPos != string::npos) {
                string key = line.substr(0, eqPos);
                string val = line.substr(eqPos + 1);

                // Trim key and value
                key.erase(0, key.find_first_not_of(" \t\r\n"));
                key.erase(key.find_last_not_of(" \t\r\n") + 1);
                val.erase(0, val.find_first_not_of(" \t\r\n"));
                val.erase(val.find_last_not_of(" \t\r\n") + 1);

                if (key == "MONGODB_URI" && (envUri == nullptr || string(envUri).empty())) {
                    mongoURI = val;
                }
                if (key == "MONGODB_DATABASE" && (envDb == nullptr || string(envDb).empty())) {
                    databaseName = val;
                }
            }
        }
        envFile.close();
    }
}

bool DBClient::connect() {
    cout << "\n[MongoDB Bridge] Initializing database client..." << endl;
    cout << "[MongoDB Bridge] Target Database: " << databaseName << endl;
    
    // Mask sensitive URI credentials if present for safe display
    string maskedURI = mongoURI;
    size_t atPos = maskedURI.find('@');
    size_t colonSlash = maskedURI.find("://");
    if (atPos != string::npos && colonSlash != string::npos && atPos > colonSlash) {
        maskedURI = maskedURI.substr(0, colonSlash + 3) + "***:***" + maskedURI.substr(atPos);
    }
    cout << "[MongoDB Bridge] Connection Target: " << maskedURI << endl;

    // Check connection via ping command using mongosh or native driver
    string testCmd = "mongosh \"" + mongoURI + "\" --quiet --eval \"db.runCommand({ ping: 1 })\" > nul 2>&1";
    int res = system(testCmd.c_str());
    if (res == 0) {
        connected = true;
        cout << "[MongoDB Bridge] SUCCESS: Connected to MongoDB successfully!" << endl;
    } else {
        connected = false;
        cout << "[MongoDB Bridge] NOTICE: MongoDB server is not reachable at " << maskedURI << endl;
        cout << "[MongoDB Bridge] In-Memory DSA Mode is ACTIVE. Data is stored in memory structures." << endl;
    }
    return connected;
}

bool DBClient::isConnected() const {
    return connected;
}

string DBClient::getURI() const {
    return mongoURI;
}

string DBClient::getDatabaseName() const {
    return databaseName;
}

void DBClient::printConnectionInfo() const {
    cout << "\n---------------- Database Status ----------------\n";
    cout << "Database Name : " << databaseName << "\n";
    string maskedURI = mongoURI;
    size_t atPos = maskedURI.find('@');
    size_t colonSlash = maskedURI.find("://");
    if (atPos != string::npos && colonSlash != string::npos && atPos > colonSlash) {
        maskedURI = maskedURI.substr(0, colonSlash + 3) + "***:***" + maskedURI.substr(atPos);
    }
    cout << "MongoDB URI   : " << maskedURI << "\n";
    cout << "Status        : " << (connected ? "CONNECTED (MongoDB Active)" : "DISCONNECTED (In-Memory DSA Mode Active)") << "\n";
    cout << "------------------------------------------------\n";
}
