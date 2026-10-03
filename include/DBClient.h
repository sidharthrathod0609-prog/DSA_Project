#ifndef DB_CLIENT_H
#define DB_CLIENT_H

#include <string>

using namespace std;

class DBClient {
private:
    string mongoURI;
    string databaseName;
    bool connected;

public:
    DBClient();
    void loadConfig();
    bool connect();
    bool isConnected() const;
    string getURI() const;
    string getDatabaseName() const;
    void printConnectionInfo() const;
};

#endif
