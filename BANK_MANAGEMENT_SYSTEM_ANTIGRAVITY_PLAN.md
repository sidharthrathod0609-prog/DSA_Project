# Bank Management System — Antigravity Build Specification

## 0. IMPORTANT: READ THIS FILE FIRST

This file is the complete build specification for a **beginner-friendly C++ DSA Mini Project — Bank Management System using MongoDB**.

The project must be built in a **console-first** manner. Do NOT over-engineer it.

The primary grading focus is:
- C++ backend
- DSA concepts covered in Modules I–X
- Functions and modularity
- Searching and sorting
- STL usage
- MongoDB database integration
- Input validation and edge cases
- Clear console menu and operations
- Ability to explain the code during demonstration

A GUI is optional and must NOT be the first priority.

## 1. NON-NEGOTIABLE CODING RULES

### 1.1 C++ starting lines

Every `.cpp` source file that contains executable C++ code should begin with:

```cpp
#include<bits/stdc++.h>
using namespace std;
```

MongoDB headers may be added immediately after these lines.

### 1.2 Coding level

Write code like a **first-year beginner C++ learner**.

Prefer:
- `if / else`
- `switch`
- `for`
- `while`
- simple functions
- `struct` or simple classes
- `string`
- 1D arrays where useful
- `vector`
- `sort`
- linear searching
- simple exception handling

Avoid unless absolutely necessary:
- advanced templates
- smart-pointer-heavy designs
- complicated inheritance
- polymorphism
- metaprogramming
- multithreading
- async programming
- complex design patterns
- unnecessary third-party libraries
- complicated GUI frameworks during MVP
- over-abstraction

The final source code must be easy for a first-year student to read and explain line by line.

### 1.3 Do not overbuild

Do NOT invent extra banking features such as:
- loans
- credit cards
- investment accounts
- ATM simulation
- interest calculation
- payment gateway
- OTP service
- biometric authentication
- microservices
- cloud deployment
- unnecessary dashboards

Only build what is listed in this specification plus small improvements needed for correctness and security.

---

# 2. ORIGINAL ASSIGNMENT REQUIREMENTS TO SATISFY

## 2.1 Common project requirements

The assignment requires:
- Develop the project using C++
- Create a menu-driven application with clearly defined operations
- Use functions to divide the program into logical operations
- Use structures wherever multiple attributes belong to one entity
- Use at least one STL container wherever appropriate
- Implement searching and sorting where relevant
- Validate user input and handle invalid operations carefully
- Do not place complete program logic inside one `main()` function
- Keep code readable, properly indented and meaningfully commented
- Explain the DSA concepts used during demonstration

## 2.2 Backend and database requirements

The primary focus is the C++ backend.

The project must connect the C++ backend to MongoDB.

Data must be stored in and retrieved from the database; do not rely only on temporary in-memory data.

Implement relevant database operations such as:
- adding records
- displaying records
- searching records
- updating records
- deleting records where applicable

Handle database errors and invalid inputs.

The final demonstration must show that the backend can successfully store and retrieve data.

## 2.3 Group 1 — Bank Management System requirements

Build a menu-driven C++ application to manage bank customers and their accounts.

Mandatory features:
1. Add a new customer/account
2. Display all customers
3. Search customer by account number
4. Deposit money
5. Withdraw money with sufficient-balance validation
6. Display account balance
7. Find the customer with the highest balance
8. Sort customers by balance

Expected DSA concepts:
- Structures
- Arrays / STL containers
- Strings
- Searching
- Sorting

Implementation expectations:
- Use separate functions for major operations
- Handle empty records
- Handle invalid account IDs/numbers
- Handle duplicate entries
- Handle unavailable resources/database errors
- Handle invalid user input
- Explain why each selected data structure is used

Suggested menu:
1. Add / Create record
2. Display records
3. Search
4. Update / Process
5. Delete / Cancel where applicable
6. Sort / Report where applicable
7. Exit

Demonstration:
- Explain the problem
- Show major features
- Demonstrate at least two edge cases
- Explain data structures and algorithms

---

# 3. C++ MODULE ALIGNMENT

The project should visibly use concepts from the supplied 10 modules.

## Module I — Introduction to C++ Programming

Use:
- variables
- constants
- data types
- input/output
- operators
- type conversion where useful

Examples:
```cpp
int choice;
string name;
double balance;
cout << "Enter balance: ";
cin >> balance;
```

## Module II — Control Statements

Use:
- decision-making
- loops
- functions

Examples:
- `if`
- `if / else`
- `switch`
- `for`
- `while`

The main menu should use a `while` loop and `switch`.

## Module III — Arrays — 1D

Use arrays only where genuinely useful.

Possible use:
- storing a small fixed list for simple validation or menu text

Do NOT force arrays into the main database logic if `vector` is more appropriate.

## Module IV — Arrays — 2D

A 2D array is NOT required by the bank problem.

Do not force an artificial 2D-array feature into the application.

It is better to explain during viva:
"2D arrays were studied in Module IV, but this problem is naturally represented by records rather than a matrix, so we did not use a 2D array unnecessarily."

## Module V — String Arrays / Strings

Use `string` for:
- customer name
- phone number
- email
- account number
- customer ID
- transaction type
- date/time strings where applicable

## Module VI — Structures

Use structures/classes to represent entities.

Minimum examples:
- `BankAccount`
- `Customer`
- `Transaction`

Keep these simple.

## Module VII — Data Structures Performance Analysis

Explain:
- linear search = O(n)
- highest balance scan = O(n)
- STL sorting = O(n log n) average/typical complexity for standard sort
- MongoDB indexed lookup can be faster than scanning every record when an appropriate index exists

Explain time and space complexity in the documentation and viva.

## Module VIII — Stacks

NOT mandatory for the basic bank requirements.

Optional future enhancement:
- recent action history in a stack

Do not force stack usage into the MVP.

## Module IX — Queues

NOT mandatory for the basic bank requirements.

Optional future enhancement:
- customer service waiting queue

Do not force queue usage into the MVP.

## Module X — STL Fundamentals & Containers

Use STL properly.

Minimum:
```cpp
vector<BankAccount>
```

Use:
- `vector`
- `sort`

Optional:
- `map` only if it genuinely simplifies a small problem

Do not use complex STL unnecessarily.

---

# 4. PROJECT GOAL

Build:

## "Bank Management System using C++ and MongoDB"

The console application should provide:

```text
================================================
             WELCOME TO OUR BANK
================================================

1. Create New Account
2. Display All Accounts
3. Search Customer
4. Deposit Money
5. Withdraw Money
6. Check Balance
7. Highest Balance
8. Sort Accounts
9. Transfer Money
10. Transaction History
11. Customer Login
12. Admin Login
13. Logout
0. Exit

Enter your choice:
```

The first working MVP may contain only the first 8 mandatory operations.

Then add:
- transaction history
- transfer
- customer/admin login
- logout

---

# 5. CONSOLE-FIRST APPROACH

## Required first phase

Build and test a fully working console application.

Do NOT start with a GUI.

The expected architecture is:

```text
User
  |
  v
C++ Console Menu
  |
  v
C++ Functions
  |
  v
MongoDB C++ Driver
  |
  v
MongoDB
```

Later, an optional GUI may call the same backend functions or backend service layer.

The GUI must not replace the required C++ backend.

---

# 6. CONNECTION BETWEEN C++ AND MONGODB

This is the critical integration.

C++ does not directly communicate with MongoDB by itself.

Use the official MongoDB C++ Driver as the bridge:

```text
C++ Application
      |
      v
MongoDB C++ Driver
      |
      v
MongoDB Server
```

The connection needs:
- a MongoDB deployment
- a MongoDB connection URI
- `mongocxx::instance`
- `mongocxx::client`

For a local MongoDB deployment, the default development URI is:

```text
mongodb://localhost:27017
```

For MongoDB Atlas, use the Atlas connection string.

IMPORTANT:
- Never commit a password-containing Atlas URI to Git.
- Never hard-code a real database password into source code.
- Keep the real URI in a local environment/configuration value.
- Provide a safe placeholder in documentation.

Recommended environment/config values:

```text
MONGODB_URI=mongodb://localhost:27017
MONGODB_DATABASE=bankdb
```

For Atlas, the user will replace `MONGODB_URI` with the real Atlas URI.

The application should preferably support this simple fallback logic:

```cpp
const char* uriFromEnv = getenv("MONGODB_URI");

string mongoURI;

if(uriFromEnv != nullptr)
{
    mongoURI = uriFromEnv;
}
else
{
    mongoURI = "mongodb://localhost:27017";
}
```

This keeps local setup simple while allowing Atlas later.

---

# 7. DATABASE NAME AND COLLECTIONS

Database:

```text
bankdb
```

Collections:

```text
customers
accounts
transactions
admins
sessions
```

Do not create unnecessary collections.

---

# 8. DATA MODEL

## 8.1 Customer

Purpose:
Store customer identity/contact/login details.

Example:

```json
{
  "customer_id": "C1001",
  "name": "Rahul Kumar",
  "phone": "9876543210",
  "email": "rahul@gmail.com",
  "pin_hash": "..."
}
```

Required fields:
- customer_id
- name
- phone
- email
- pin_hash

## 8.2 Account

Purpose:
Store account-specific information.

Example:

```json
{
  "account_number": "100001",
  "customer_id": "C1001",
  "account_type": "Savings",
  "balance": 15000.0,
  "status": "Active"
}
```

Required fields:
- account_number
- customer_id
- account_type
- balance
- status

## 8.3 Transaction

Purpose:
Store all money operations.

Example:

```json
{
  "transaction_id": "T10001",
  "account_number": "100001",
  "type": "Deposit",
  "amount": 5000.0,
  "to_account": "",
  "date": "2026-10-03"
}
```

For transfer:

```json
{
  "transaction_id": "T10002",
  "account_number": "100001",
  "type": "Transfer",
  "amount": 2000.0,
  "to_account": "100002",
  "date": "2026-10-03"
}
```

## 8.4 Admin

Example:

```json
{
  "admin_id": "A001",
  "username": "admin",
  "password_hash": "..."
}
```

## 8.5 Session

Example:

```json
{
  "session_id": "S1001",
  "customer_id": "C1001",
  "login_time": "2026-10-03 14:30",
  "active": true
}
```

A beginner MVP may initially keep session state in C++ and add the `sessions` collection afterward.

---

# 9. RELATIONSHIP / ER-LIKE VIEW

Use this simple relationship:

```text
CUSTOMER
   |
   | 1
   |
   | has
   |
   | many
   v
ACCOUNT
   |
   | has
   |
   | many
   v
TRANSACTION
```

Admin is separate:

```text
ADMIN
  |
  v
Bank Management Operations
```

A customer has a `customer_id`.

An account stores `customer_id` to link the account to the customer.

Transactions store account references.

---

# 10. DATABASE INDEXES

Create useful indexes after basic CRUD works.

Recommended:

```javascript
db.accounts.createIndex(
  { account_number: 1 },
  { unique: true }
)

db.customers.createIndex(
  { customer_id: 1 },
  { unique: true }
)

db.transactions.createIndex(
  { account_number: 1 }
)
```

Optional:
```javascript
db.customers.createIndex(
  { phone: 1 }
)
```

Explain in viva:
- unique account index prevents duplicate account numbers
- customer ID uniqueness prevents duplicate customer IDs
- transaction account index helps transaction-history searches

Do not create indexes for every field.

---

# 11. C++ DATA STRUCTURES

Minimum simple classes:

```cpp
class BankAccount
{
public:
    string accountNumber;
    string customerId;
    string customerName;
    double balance;

    BankAccount()
    {
        balance = 0;
    }
};
```

```cpp
class Customer
{
public:
    string customerId;
    string name;
    string phone;
    string email;
    string pinHash;
};
```

```cpp
class Transaction
{
public:
    string transactionId;
    string accountNumber;
    string type;
    double amount;
    string toAccount;
};
```

If `struct` is easier for the student to explain, using:

```cpp
struct BankAccount
{
    string accountNumber;
    string customerId;
    string customerName;
    double balance;
};
```

is acceptable.

Prefer whichever is simpler.

---

# 12. RECOMMENDED STL CONTAINER

Use:

```cpp
vector<BankAccount> accounts;
```

Why:
- dynamic size
- easy indexing
- simple iteration
- easy STL sorting
- beginner-friendly

Use vector for in-memory display/sorting/testing.

MongoDB remains the persistent storage.

---

# 13. REQUIRED FUNCTIONS

Create separate functions for major operations.

Suggested functions:

```cpp
void addAccount();
void displayAccounts();
int searchAccount(string accountNumber);
void depositMoney();
void withdrawMoney();
void showBalance();
void highestBalance();
void sortAccounts();
void transferMoney();
void showTransactions();
void customerLogin();
void adminLogin();
void logout();
```

If a helper function is needed:

```cpp
bool accountExists(string accountNumber);
bool validAmount(double amount);
string hashPIN(string pin);
```

Do not put everything inside `main()`.

---

# 14. MENU LOGIC

Use beginner-level `while` + `switch`.

Basic pattern:

```cpp
int choice;

while(true)
{
    cout << "\n1. Add Account";
    cout << "\n2. Display Accounts";
    cout << "\n3. Search Account";
    cout << "\n4. Deposit";
    cout << "\n5. Withdraw";
    cout << "\n6. Check Balance";
    cout << "\n7. Highest Balance";
    cout << "\n8. Sort Accounts";
    cout << "\n9. Transfer";
    cout << "\n10. Transactions";
    cout << "\n11. Customer Login";
    cout << "\n12. Admin Login";
    cout << "\n13. Logout";
    cout << "\n0. Exit";

    cout << "\nEnter choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            addAccount();
            break;

        case 2:
            displayAccounts();
            break;

        case 3:
            // search
            break;

        case 4:
            depositMoney();
            break;

        case 5:
            withdrawMoney();
            break;

        case 6:
            showBalance();
            break;

        case 7:
            highestBalance();
            break;

        case 8:
            sortAccounts();
            break;

        case 9:
            transferMoney();
            break;

        case 10:
            showTransactions();
            break;

        case 11:
            customerLogin();
            break;

        case 12:
            adminLogin();
            break;

        case 13:
            logout();
            break;

        case 0:
            return;

        default:
            cout << "Invalid choice\n";
    }
}
```

---

# 15. PHASE-BY-PHASE BUILD PROCESS

## PHASE 0 — Decide the environment

Target:
- console application
- C++17
- MongoDB
- official MongoDB C++ Driver
- Windows and/or Linux

Do not require a GUI for MVP.

Decide whether MongoDB will be:
- local MongoDB
- MongoDB Atlas

Default local assumption:
```text
mongodb://localhost:27017
```

If the user supplies another URI, use it through configuration/environment instead of hard-coding it.

---

# 16. PHASE 1 — Create project

Create:

```text
BankManagementSystem/
│
├── CMakeLists.txt
├── README.md
├── .gitignore
│
├── include/
│
├── src/
│   └── main.cpp
│
├── tests/
│
└── data/
```

Do not create too many files at the beginning.

Start with:
```text
src/main.cpp
```

Then split into modules after the first working version.

---

# 17. PHASE 2 — Create basic C++ console program

First build:
- welcome message
- menu
- input
- switch
- exit

At this stage NO MongoDB code is required.

Output should resemble:

```text
========================================
        WELCOME TO OUR BANK
========================================

1. Create New Account
2. Display All Accounts
3. Search Customer
4. Deposit Money
5. Withdraw Money
6. Check Balance
7. Highest Balance
8. Sort Accounts
0. Exit

Enter your choice:
```

Acceptance condition:
- program compiles
- menu repeats
- invalid choices are handled
- exit works

---

# 18. PHASE 3 — Add structures/classes

Create simple entities:
- Customer
- BankAccount
- Transaction

Then create:

```cpp
vector<BankAccount> accounts;
```

Add account records in memory first.

Acceptance condition:
- account can be created
- record is stored in vector
- display function prints it

---

# 19. PHASE 4 — Implement all 8 mandatory DSA operations IN MEMORY FIRST

Do not connect MongoDB yet.

## 19.1 Create account

Input:
- account number
- customer ID
- customer name
- account type
- opening balance

Validate:
- account number not empty
- duplicate account number not allowed
- opening balance >= 0

## 19.2 Display accounts

Loop through vector.

Handle:
```text
No accounts found.
```

## 19.3 Search account

Search by account number.

Beginner approach:
```cpp
for(int i = 0; i < accounts.size(); i++)
```

Return index or display directly.

## 19.4 Deposit

Rules:
- amount > 0
- account must exist
- increase balance

## 19.5 Withdraw

Rules:
- amount > 0
- account must exist
- amount <= balance

If amount > balance:
```text
Insufficient balance.
```

## 19.6 Show balance

Search account and print balance.

## 19.7 Highest balance

Scan vector and keep index of highest balance.

If no records:
```text
No accounts found.
```

## 19.8 Sort by balance

Use STL `sort()`.

Requirement:
- highest balance first

---

# 20. PHASE 5 — MongoDB connection TEST ONLY

Before integrating the full bank application, create a tiny connection test.

Required structure:

```cpp
#include<bits/stdc++.h>
using namespace std;

#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/uri.hpp>

int main()
{
    mongocxx::instance instance;

    mongocxx::client client(
        mongocxx::uri{"mongodb://localhost:27017"}
    );

    cout << "Connected to MongoDB!" << endl;

    return 0;
}
```

Then improve it with a MongoDB ping command.

DO NOT continue to the rest of the database integration until the connection test works.

Acceptance:
```text
Connected to MongoDB successfully!
```

If connection fails:
- print readable error
- do not crash
- check MongoDB server
- check URI
- check C++ driver installation

---

# 21. PHASE 6 — Database client class

After the simple connection test works, create:

```text
DBClient
```

Purpose:
- create MongoDB driver instance
- create MongoDB client
- select `bankdb`

Simple idea:

```cpp
class DBClient
{
public:
    mongocxx::instance instance;
    mongocxx::client client;
    mongocxx::database db;

    DBClient()
        : instance{},
          client(mongocxx::uri{"mongodb://localhost:27017"}),
          db(client["bankdb"])
    {
    }
};
```

Later make URI configurable through environment/config.

Do not create a complex dependency injection system.

---

# 22. PHASE 7 — Create MongoDB collections

Collections may be created automatically when data is first inserted, but document the intended collections:

```text
customers
accounts
transactions
admins
sessions
```

Verify using `mongosh`.

Example:

```javascript
use bankdb
show collections
```

---

# 23. PHASE 8 — Implement CREATE ACCOUNT in MongoDB

Flow:

```text
User input
   ↓
Validate
   ↓
Check duplicate account
   ↓
Create BSON document
   ↓
insert_one()
   ↓
Success message
```

Suggested document fields:

```text
account_number
customer_id
account_type
balance
status
```

If customer and account are separate entities:
1. insert customer
2. insert account with customer_id

Keep the first implementation simple.

---

# 24. PHASE 9 — DISPLAY ACCOUNTS from MongoDB

Use:
```cpp
find()
```

Read every account and print:

```text
Account Number
Customer ID
Customer Name
Balance
Status
```

If no records:
```text
No accounts found.
```

This proves the data is not only stored in a C++ vector.

---

# 25. PHASE 10 — SEARCH from MongoDB

Search by:
```text
account_number
```

Use:
```cpp
find_one()
```

Flow:

```text
input account number
      ↓
MongoDB query
      ↓
record found?
  /           \
yes            no
 |              |
display       message
```

Create a unique index on account number.

---

# 26. PHASE 11 — DEPOSIT

Use MongoDB update operation.

Conceptually:
```text
new balance = old balance + amount
```

MongoDB update can use `$inc`.

Validation:
- account exists
- amount > 0

After successful balance update:
- insert a deposit transaction record

Result:
```text
Deposit successful!
```

---

# 27. PHASE 12 — WITHDRAW

Rules:
- amount > 0
- account exists
- sufficient balance

Use a conditional update so the database only decreases the balance when the balance is sufficient.

Concept:
```text
balance >= amount
```

Then:
```text
balance = balance - amount
```

After successful update:
- insert withdrawal transaction

If failed:
```text
Insufficient balance or account not found.
```

---

# 28. PHASE 13 — HIGHEST BALANCE

Two reasonable approaches:

### Simple student approach

Load account records into:
```cpp
vector<BankAccount>
```

Then scan:

```cpp
int highest = 0;

for(int i = 1; i < accounts.size(); i++)
{
    if(accounts[i].balance > accounts[highest].balance)
    {
        highest = i;
    }
}
```

Complexity:
```text
O(n)
```

### Optional later approach

Use a MongoDB sort query.

But for DSA demonstration, the vector + scan approach is easier to explain.

---

# 29. PHASE 14 — SORT ACCOUNTS

Load records into vector.

Use STL:

```cpp
sort(accounts.begin(), accounts.end(),
    [](BankAccount a, BankAccount b)
    {
        return a.balance > b.balance;
    });
```

Display sorted results.

Explain:
- vector = STL dynamic container
- sort = standard algorithm
- descending balance order

---

# 30. PHASE 15 — TRANSACTION HISTORY

Every financial operation should create a transaction document.

Types:
- Deposit
- Withdrawal
- Transfer

Fields:
```text
transaction_id
account_number
type
amount
to_account
date
```

When the user selects transaction history:
- ask account number
- query transactions collection
- display matching records

Index:
```javascript
db.transactions.createIndex(
  { account_number: 1 }
)
```

---

# 31. PHASE 16 — MONEY TRANSFER

Transfer logic:

```text
Sender
   |
   | - amount
   v
Receiver
   |
   | + amount
```

Requirements:
- sender exists
- receiver exists
- sender != receiver
- amount > 0
- sender has sufficient balance

The two balance changes and the transfer transaction should be handled as one database transaction.

Important MongoDB constraint:
- multi-document transactions require a replica set or sharded deployment
- standalone MongoDB deployment is not sufficient for this transaction feature

For simple local development:
- use a MongoDB replica set configuration
OR
- use MongoDB Atlas

Do not fake atomic transfer behavior by updating one account and then blindly updating the other.

---

# 32. PHASE 17 — LOGIN SYSTEM

## Customer login

Inputs:
- account number
- PIN

Process:
```text
account number
     ↓
find customer/account
     ↓
verify PIN hash
     ↓
login success
```

## Admin login

Inputs:
- username
- password

Keep admin credentials simple for the academic demo, but do not store plaintext passwords in the database.

---

# 33. PHASE 18 — PASSWORD/PIN HASHING

For a classroom demonstration, the code can include a simple helper such as:

```cpp
string hashPIN(string pin)
{
    return to_string(hash<string>{}(pin));
}
```

However:

IMPORTANT:
`std::hash` is NOT a secure password hashing system for a real banking application.

For this academic project it may be used only to demonstrate the concept of not storing plaintext PINs.

Production enhancement:
- Argon2
- bcrypt
- another dedicated password hashing algorithm

Never claim the simple `std::hash` solution is production-grade security.

---

# 34. PHASE 19 — SESSION MANAGEMENT

Beginner MVP:

```cpp
bool loggedIn = false;
string loggedInAccount = "";
```

Login:
```cpp
loggedIn = true;
loggedInAccount = accountNumber;
```

Logout:
```cpp
loggedIn = false;
loggedInAccount = "";
```

Then optionally save session records in MongoDB.

Never store plaintext authentication secrets in session documents.

---

# 35. PHASE 20 — ROLE-BASED MENU

## Customer menu

```text
1. Check Balance
2. Deposit
3. Withdraw
4. Transfer
5. Transaction History
6. Logout
```

## Admin menu

```text
1. Create Account
2. Display All Accounts
3. Search Customer
4. Highest Balance
5. Sort Accounts
6. Display Transactions
7. Logout
```

Keep the role system simple.

Do not build a large authorization framework.

---

# 36. INPUT VALIDATION REQUIREMENTS

Validate all important user input.

## Menu
Accept only valid menu numbers.

## Amount
```text
amount > 0
```

Reject:
- zero
- negative
- non-numeric input

## Account number
Reject:
- empty input
- duplicate account number
- unknown account when operation requires existing account

## Withdrawal
Reject:
- amount greater than balance

## Transfer
Reject:
- same sender and receiver
- nonexistent sender
- nonexistent receiver
- insufficient balance
- non-positive amount

## Login
Reject:
- wrong credentials
- empty username/account number

---

# 37. INPUT FAILURE HANDLING

The application must not get stuck when a user enters text where an integer is expected.

A simple approach:

```cpp
if(cin.fail())
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input. Try again.\n";
}
```

Keep this helper simple.

---

# 38. DUPLICATE ACCOUNT HANDLING

Before creating an account:
1. search MongoDB for the account number
2. if found, reject it
3. otherwise insert it

Database-level protection:
```text
unique index on account_number
```

This gives both:
- application validation
- database validation

---

# 39. ERROR HANDLING

Use simple `try/catch`.

Pattern:

```cpp
try
{
    // MongoDB operation
}
catch(const exception &e)
{
    cout << "Database error: "
         << e.what()
         << endl;
}
```

Do not expose credentials in error messages.

---

# 40. CONCURRENCY AND DATA CONSISTENCY

The project should demonstrate awareness of multiple users/operations.

For basic deposit/withdraw:
- use atomic-style MongoDB update operations where possible
- avoid reading a balance and later overwriting it unnecessarily

For transfer:
- use a MongoDB transaction

Concept:

```text
START TRANSACTION
    ↓
Debit sender
    ↓
Credit receiver
    ↓
Insert transaction record
    ↓
COMMIT
```

If any operation fails:

```text
ABORT
```

No partial transfer should remain.

Do not implement multithreading just to demonstrate concurrency.

---

# 41. LOGGING

Keep logging simple.

Recommended:
- successful account creation
- deposit
- withdrawal
- transfer
- failed login
- database errors

Use transaction history as the main audit trail.

Optional file log:
```text
logs/bank.log
```

But file logging is optional. Do not overcomplicate the first version.

---

# 42. BACKUP AND RECOVERY

Document MongoDB backup commands such as:
```text
mongodump
mongorestore
```

For transaction recovery:
- rely on MongoDB transaction atomicity for multi-step transfer
- catch exceptions
- report failures clearly

During demo, explain:
"If the transfer transaction fails before commit, MongoDB does not leave the transfer half-completed."

---

# 43. MONEY HANDLING

For beginner implementation:
```cpp
double balance;
```

This keeps the code easy to understand.

For production-grade financial systems:
- use integer minor currency units (paise) or decimal-safe monetary representation

Do not claim `double` is production financial accounting precision.

For this academic project, INR is the displayed currency.

Example:
```text
Rs. 5000.00
```

---

# 44. REPOSITORY / DATA ACCESS LAYER

After the first version works, separate database operations from menu code.

Create:

```cpp
class BankRepository
{
public:
    void addAccount();
    void displayAccounts();
    void searchAccount();
    void depositMoney();
    void withdrawMoney();
    void showBalance();
    void transferMoney();
    void showTransactions();
};
```

The UI/menu calls repository operations.

Keep repository logic simple.

Do not build a complex enterprise architecture.

---

# 45. RECOMMENDED FINAL PROJECT STRUCTURE

After the initial single-file implementation is working:

```text
BankManagementSystem/
│
├── CMakeLists.txt
├── README.md
├── .gitignore
│
├── include/
│   ├── BankAccount.h
│   ├── Customer.h
│   ├── Transaction.h
│   ├── DBClient.h
│   └── BankRepository.h
│
├── src/
│   ├── main.cpp
│   ├── DBClient.cpp
│   ├── BankRepository.cpp
│   ├── BankAccount.cpp
│   ├── Customer.cpp
│   └── Transaction.cpp
│
├── tests/
│
└── data/
```

However, if splitting files makes the beginner code harder to understand, keep an intentionally simpler structure:

```text
BankManagementSystem/
├── CMakeLists.txt
├── src/
│   └── main.cpp
├── tests/
└── README.md
```

The final decision should favor readability.

---

# 46. CMAKE REQUIREMENTS

Target:
```text
C++17
```

Example starting CMake:

```cmake
cmake_minimum_required(VERSION 3.15)

project(BankManagementSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(bsoncxx 4.0 REQUIRED)
find_package(mongocxx 4.0 REQUIRED)

add_executable(BankManagementSystem
    src/main.cpp
)

target_link_libraries(BankManagementSystem
    PRIVATE
    mongo::mongocxx_shared
    mongo::bsoncxx_shared
)
```

IMPORTANT:
The exact imported target names can depend on how the MongoDB C++ Driver was installed. If the installation exposes different target names, use the targets supplied by that installation instead of inventing new ones.

---

# 47. BUILD STEPS

After dependencies are installed:

```bash
cmake -B build
cmake --build build
```

Run the generated program.

On Linux:
```bash
./build/BankManagementSystem
```

On Windows, use the corresponding generated executable/configuration.

---

# 48. LOCAL DEVELOPMENT CONFIGURATION

Recommended:

```text
MONGODB_URI=mongodb://localhost:27017
MONGODB_DATABASE=bankdb
```

If using Atlas:

```text
MONGODB_URI=mongodb+srv://<username>:<password>@<cluster>/<database>?...
MONGODB_DATABASE=bankdb
```

DO NOT put real credentials in:
- README
- source code
- Git history
- screenshots
- public repository

Create `.gitignore` entries for local secret files.

Possible:
```text
.env
.env.*
```

If Antigravity needs the real connection string, it should instruct the user to add it locally rather than embedding it into generated source.

---

# 49. SAMPLE MONGODB DATA

Use these test records.

Customer:

```json
{
  "customer_id": "C1001",
  "name": "Rahul Kumar",
  "phone": "9876543210",
  "email": "rahul@gmail.com",
  "pin_hash": "demo_hash"
}
```

Account 1:

```json
{
  "account_number": "100001",
  "customer_id": "C1001",
  "account_type": "Savings",
  "balance": 10000,
  "status": "Active"
}
```

Account 2:

```json
{
  "account_number": "100002",
  "customer_id": "C1002",
  "account_type": "Savings",
  "balance": 5000,
  "status": "Active"
}
```

These values are demonstration data only.

---

# 50. DEMO TEST SCENARIO

Perform this exact sequence during development:

## Test 1
Create:
```text
100001 Rahul 10000
```

## Test 2
Create:
```text
100002 Arjun 5000
```

## Test 3
Display all.

Expected:
```text
100001 Rahul 10000
100002 Arjun 5000
```

## Test 4
Search:
```text
100001
```

Expected:
```text
Rahul
10000
```

## Test 5
Deposit:
```text
100001
1000
```

Expected:
```text
11000
```

## Test 6
Withdraw:
```text
100001
2000
```

Expected:
```text
9000
```

## Test 7
Withdraw:
```text
100001
20000
```

Expected:
```text
Insufficient balance
```

## Test 8
Transfer:
```text
100001 -> 100002
1000
```

Expected:
```text
100001 = 8000
100002 = 6000
```

## Test 9
Highest balance

Expected:
```text
Account 100001 / 100002
```

based on current test values.

## Test 10
Sort descending by balance.

---

# 51. EDGE CASES TO DEMONSTRATE

At least two are required.

Recommended four:

### Edge case 1
Withdraw more than available balance.

Expected:
```text
Insufficient balance
```

### Edge case 2
Create duplicate account number.

Expected:
```text
Account already exists
```

### Edge case 3
Transfer to same account.

Expected:
```text
Cannot transfer to the same account
```

### Edge case 4
Search nonexistent account.

Expected:
```text
Account not found
```

---

# 52. UNIT TEST OUTLINE

Tests should cover helper functions and business rules.

Examples:

```text
testAccountCreation()
testDuplicateAccount()
testSearchAccount()
testDeposit()
testNegativeDeposit()
testWithdraw()
testInsufficientBalance()
testHighestBalance()
testSortByBalance()
testTransfer()
testSameAccountTransfer()
```

Tests can be basic and beginner-readable.

Do not introduce a large testing framework unless needed.

---

# 53. DATABASE TESTS

Also test:
- insert account
- find account
- update balance
- transaction insert
- transaction query
- duplicate account protection
- failed transfer rollback

Verify in `mongosh` where useful.

---

# 54. SECURITY REQUIREMENTS

This is an academic project, not a real banking platform.

Still implement basic good practices:
- do not store plaintext PIN/password
- do not commit database credentials
- validate all user input
- use role checks
- use unique account IDs
- use atomic database updates
- use MongoDB transactions for transfer
- never print sensitive credentials
- do not put secrets in source comments or README

Do not claim the project is secure enough for real banking use.

---

# 55. OPTIONAL GUI — ONLY AFTER CONSOLE MVP

Do not start GUI development until all backend tests pass.

Possible later GUI options:
- Qt
- another lightweight cross-platform UI layer

The GUI should display:

```text
WELCOME TO OUR BANK
```

and only the operations already supported by the backend.

Do not redesign the entire project around a GUI.

The console application is the primary assessed implementation.

---

# 56. ANTIGRAVITY DEVELOPMENT ORDER

Antigravity must build the project in this order.

## Step 1
Read this file completely.

## Step 2
Create the project folders and CMake file.

## Step 3
Create a minimal C++ console menu.

## Step 4
Verify C++ compiler/build works.

## Step 5
Add `BankAccount`, `Customer`, and `Transaction`.

## Step 6
Implement all 8 mandatory operations using vector/in-memory data.

## Step 7
Test the DSA implementation.

## Step 8
Install/configure MongoDB C++ Driver if needed.

## Step 9
Build and run a MongoDB connection test.

## Step 10
Create `bankdb`.

## Step 11
Implement MongoDB account creation.

## Step 12
Implement MongoDB display/query.

## Step 13
Implement MongoDB search.

## Step 14
Implement deposit.

## Step 15
Implement withdrawal.

## Step 16
Implement transaction history.

## Step 17
Implement transfer using a MongoDB transaction.

## Step 18
Implement customer login.

## Step 19
Implement admin login.

## Step 20
Implement logout/session state.

## Step 21
Add validation and exception handling throughout.

## Step 22
Add indexes.

## Step 23
Add tests.

## Step 24
Create README and demo instructions.

## Step 25
Only then consider optional GUI.

DO NOT skip ahead if an earlier phase does not compile/work.

---

# 57. ANTIGRAVITY MUST USE BUILD CHECKPOINTS

After every major phase:

1. Build project
2. Run project
3. Test feature
4. Fix errors
5. Only then move forward

Checkpoint examples:

```text
Checkpoint A
Console menu works

Checkpoint B
In-memory DSA operations work

Checkpoint C
MongoDB connection works

Checkpoint D
Create/read/search work with MongoDB

Checkpoint E
Deposit/withdraw work

Checkpoint F
Transactions work

Checkpoint G
Transfer transaction works

Checkpoint H
Authentication works

Checkpoint I
Full project demo works
```

Do not make many unrelated changes at once.

---

# 58. ANTIGRAVITY ERROR-HANDLING BEHAVIOR

When an error occurs:
- identify the exact compile/runtime/database error
- make the smallest necessary correction
- rebuild
- retest
- do not rewrite the entire project
- do not replace simple working code with complicated architecture

If MongoDB is unavailable, show a clear error message.

Do not silently pretend that database operations succeeded.

---

# 59. WHAT THE FINAL APPLICATION MUST NOT DO

Do not:
- fake MongoDB operations with local arrays only
- claim database storage while only using memory
- put all logic inside `main()`
- use hard-coded real passwords
- expose connection secrets
- use complex code beyond the modules without a reason
- add huge GUI features before backend is stable
- invent unrequested banking features
- remove required searching/sorting
- remove MongoDB integration
- make the user understand advanced C++ before running the app

---

# 60. FINAL ACCEPTANCE CHECKLIST

The project is considered complete only when all are true.

## C++
- [ ] Program starts with the required include style
- [ ] Code compiles
- [ ] Menu works
- [ ] Functions divide the logic
- [ ] Structures/classes represent entities
- [ ] vector/STL is used
- [ ] strings are used
- [ ] searching works
- [ ] sorting works
- [ ] highest balance works
- [ ] input validation works
- [ ] edge cases work

## MongoDB
- [ ] MongoDB connection works
- [ ] bankdb exists/works
- [ ] accounts collection works
- [ ] customers collection works
- [ ] transactions collection works
- [ ] records are actually persisted
- [ ] records can be retrieved
- [ ] balance updates are stored
- [ ] transaction history is stored
- [ ] duplicate account numbers are prevented
- [ ] indexes are created

## Banking operations
- [ ] create account
- [ ] display accounts
- [ ] search customer
- [ ] deposit
- [ ] withdrawal
- [ ] balance inquiry
- [ ] highest balance
- [ ] sorting
- [ ] transfer
- [ ] transaction history
- [ ] customer login
- [ ] admin login
- [ ] logout

## Safety
- [ ] no plaintext PIN/password storage
- [ ] no real MongoDB password in source
- [ ] invalid inputs handled
- [ ] database exceptions handled
- [ ] transfer uses transaction safety

## Demo
- [ ] at least two edge cases demonstrated
- [ ] DSA concepts explained
- [ ] complexity explained
- [ ] MongoDB connection explained
- [ ] CRUD operations demonstrated
- [ ] project can be built from README

---

# 61. VIVA EXPLANATION CHEAT SHEET

The student should be able to explain:

### Why C++?
Because the assignment requires a C++ backend and DSA implementation.

### Why MongoDB?
To permanently store customers, accounts and transactions.

### How does C++ connect to MongoDB?
Through the official MongoDB C++ Driver.

### What is the connection string?
It tells the C++ driver where the MongoDB deployment is located.

Local example:
```text
mongodb://localhost:27017
```

### Why vector?
It provides a simple dynamic STL container for account records and supports easy iteration/sorting.

### Why structure/class?
Because an account/customer has multiple related attributes.

### How do you search?
Linear search in the in-memory DSA demonstration; MongoDB query for persistent data.

### How do you sort?
STL `sort()`.

### Why functions?
To divide the application into logical operations.

### How do you prevent duplicate accounts?
Application-level search plus a unique MongoDB index.

### How do you prevent insufficient withdrawal?
Validate amount and require balance >= withdrawal amount.

### How do you make transfer safe?
Use a MongoDB transaction so debit, credit and transaction logging succeed together or are rolled back together.

### Why do you not use 2D arrays?
The problem is naturally record-based, not matrix-based.

### Why don't you force stack/queue?
They were studied in the syllabus, but they are not necessary for the mandatory banking requirements. They may be optional extensions.

---

# 62. README REQUIREMENTS

The final README should contain:
1. Project title
2. Problem statement
3. Features
4. Technologies
5. C++ module mapping
6. MongoDB architecture
7. Database collections
8. Installation
9. MongoDB setup
10. Driver setup
11. Configuration
12. Build commands
13. Run commands
14. Sample data
15. Testing
16. Edge cases
17. DSA concepts
18. Complexity
19. Known limitations
20. Future GUI enhancement

---

# 63. IMPLEMENTATION STYLE EXAMPLE

The source code style should look similar to this:

```cpp
#include<bits/stdc++.h>
using namespace std;

class BankAccount
{
public:
    string accountNumber;
    string customerName;
    double balance;

    BankAccount()
    {
        balance = 0;
    }
};

int searchAccount(vector<BankAccount> &accounts, string accountNumber)
{
    for(int i = 0; i < accounts.size(); i++)
    {
        if(accounts[i].accountNumber == accountNumber)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    vector<BankAccount> accounts;

    int choice;

    while(true)
    {
        cout << "\n1. Add Account";
        cout << "\n2. Search Account";
        cout << "\n0. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                // call addAccount()
                break;

            case 2:
                // call search function
                break;

            case 0:
                return 0;

            default:
                cout << "Invalid choice";
        }
    }
}
```

This is the desired level of complexity.

---

# 64. FINAL INSTRUCTION TO ANTIGRAVITY

Build this project as a **simple first-year C++ DSA banking application with MongoDB persistence**.

Do not over-engineer it.

Do not replace the beginner syntax with sophisticated architecture.

Prioritize:
1. correctness
2. simple C++ syntax
3. DSA requirements
4. MongoDB integration
5. input validation
6. database consistency
7. demonstration readiness

Build incrementally.

Every major phase must compile and run before starting the next phase.

The finished project must be easy for the student to:
- understand
- run
- modify
- explain in a viva
- demonstrate to the lecturer

The console application is the primary version.

GUI is optional and comes only after the complete backend/console MVP is stable.

