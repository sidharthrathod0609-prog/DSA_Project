# Bank Management System (C++ & MongoDB DSA Project)

A beginner-friendly, console-driven **Bank Management System** developed in C++ following Data Structures and Algorithms (DSA) principles, backed by MongoDB for persistent record keeping and featuring an in-memory STL fallback mode.

---

## 1. Problem Statement
Traditional banking systems require secure, reliable, and efficient management of customer accounts, financial transactions (deposits, withdrawals, transfers), balance inquiries, and auditing. This project implements a core banking engine in C++ demonstrating fundamental data structures (classes, arrays, STL vectors), search algorithms, sorting algorithms, and database integration with MongoDB.

---

## 2. Core Features

### Mandatory Operations (Assignment Specification)
1. **Create Account**: Add a new customer account with customer details, account type, and opening balance (duplicate account number validation enforced).
2. **Display All Accounts**: Formatted tabular view of all registered accounts.
3. **Search Customer**: Search account by account number using linear search ($O(n)$).
4. **Deposit Money**: Credit funds to an account with positive amount validation ($O(1)$ lookup + update).
5. **Withdraw Money**: Debit funds from an account with sufficient balance check.
6. **Check Balance**: Display current account balance and status.
7. **Customer with Highest Balance**: Scans all accounts to find the maximum balance ($O(n)$).
8. **Sort Accounts**: Sort accounts in descending order of balance using STL `sort()` ($O(n \log n)$).

### Additional Features
9. **Transfer Money**: Safely transfer funds between two distinct accounts with balance verification and atomic state updates.
10. **Transaction History**: Audit log of all deposits, withdrawals, and transfers with transaction IDs and dates.
11. **Customer Login**: Secure PIN-based login for customers with hashed PIN verification.
12. **Admin Login**: Privileged administrative access (`admin` / `admin123`).
13. **Logout & Session State**: Active session management.

---

## 3. Technology Stack
- **Language**: C++ (C++14 / C++17)
- **Compiler**: MinGW GCC 6.3.0+ / MSVC / Clang
- **Build System**: CMake / Windows Batch scripts
- **Database**: MongoDB (Local or MongoDB Atlas)
- **Shell / Tools**: `mongosh` 2.11+, PowerShell, Windows CMD

---

## 4. C++ Module Mapping (Syllabus Alignment)

| Module | Concept | Where Used in Project |
|---|---|---|
| **Module I** | Intro & Data Types | Variables, constants, double for balances, string for IDs |
| **Module II** | Control Statements | `while` loops, `switch` case menus, `if/else` validations |
| **Module III** | 1D Arrays | Input buffers, formatting tables, fixed lists |
| **Module IV** | 2D Arrays | Studied in syllabus; naturally omitted here since banking entities are record-based, not matrix-based |
| **Module V** | Strings | `string` for account numbers, names, emails, phones, PIN hashes |
| **Module VI** | Structures & Classes | `Customer`, `BankAccount`, `Transaction`, `DBClient`, `BankRepository` |
| **Module VII** | Complexity Analysis | Linear Search $O(n)$, Max scan $O(n)$, STL sort $O(n \log n)$ |
| **Module VIII** | Stacks | Conceptual action history (future undo mechanism) |
| **Module IX** | Queues | Customer service queue (future extension) |
| **Module X** | STL Containers | `std::vector`, `std::sort`, lambda comparators |

---

## 5. MongoDB Architecture & Collections

### Database Name: `bankdb`

```
  +------------------+         1 : N         +-------------------+
  |    customers     | -------------------> |     accounts      |
  +------------------+                      +-------------------+
  | customer_id (PK) |                      | account_number(PK)|
  | name             |                      | customer_id (FK)  |
  | phone            |                      | account_type      |
  | email            |                      | balance           |
  | pin_hash         |                      | status            |
  +------------------+                      +-------------------+
                                                      |
                                                      | 1 : N
                                                      v
                                            +-------------------+
                                            |   transactions    |
                                            +-------------------+
                                            | transaction_id(PK)|
                                            | account_number(FK)|
                                            | type              |
                                            | amount            |
                                            | to_account        |
                                            | date              |
                                            +-------------------+
```

---

## 6. Project Directory Layout

```
DSA_Project/
├── CMakeLists.txt              # CMake build configuration
├── build.bat                   # 1-click build script (MinGW g++)
├── run.bat                     # Run main bank management application
├── run_tests.bat               # Run DSA unit & edge case tests
├── run_mongo_test.bat          # Run MongoDB connection test
├── .env.example                # Template configuration file
├── .env                        # Active environment configuration
├── .gitignore                  # Git ignore file
├── README.md                   # Complete documentation
│
├── include/
│   ├── Customer.h              # Customer model
│   ├── BankAccount.h           # BankAccount model
│   ├── Transaction.h           # Transaction model
│   ├── DBClient.h              # Database client & connection bridge
│   └── BankRepository.h        # DSA operations & repository logic
│
├── src/
│   ├── main.cpp                # Console menu and interactive loop
│   ├── DBClient.cpp            # Configuration parser & connection tester
│   └── BankRepository.cpp      # Implementation of all 8 DSA operations
│
└── tests/
    ├── test_dsa.cpp            # 13 automated unit & edge case tests
    └── test_mongo_connection.cpp# MongoDB connection & ping test
```

---

## 7. Configuration (.env)

Edit the `.env` file in the project root:

```env
MONGODB_URI=mongodb://localhost:27017
MONGODB_DATABASE=bankdb
```

> **For MongoDB Atlas**: Replace `MONGODB_URI` with your connection string:
> `MONGODB_URI=mongodb+srv://<username>:<password>@cluster0.xyz.mongodb.net/?retryWrites=true&w=majority`

---

## 8. Build & Run Instructions

### Option A: Using Batch Scripts (Recommended for Windows)

1. **Build all executables**:
   ```cmd
   build.bat
   ```
2. **Run the Bank Management System**:
   ```cmd
   run.bat
   ```
3. **Run DSA Unit Tests**:
   ```cmd
   run_tests.bat
   ```
4. **Test MongoDB Connection**:
   ```cmd
   run_mongo_test.bat
   ```

### Option B: Using CMake

```cmd
cmake -B build -G "MinGW Makefiles"
cmake --build build
.\build\BankManagementSystem.exe
```

---

## 9. Automated Test Suite Results

Run `run_tests.bat` to verify all 13 core DSA checks and edge cases:

- [x] **Test 1**: Create valid new account
- [x] **Test 2**: Prevent duplicate account creation (Edge Case 1)
- [x] **Test 3**: Search existing account via Linear Search
- [x] **Test 4**: Search non-existent account returns -1
- [x] **Test 5**: Deposit valid amount
- [x] **Test 6**: Reject negative/zero deposit (Edge Case 2)
- [x] **Test 7**: Withdraw with sufficient balance
- [x] **Test 8**: Reject withdrawal exceeding balance (Edge Case 3)
- [x] **Test 9**: Transfer money between different accounts
- [x] **Test 10**: Reject transfer to same account (Edge Case 4)
- [x] **Test 11**: Valid customer PIN login
- [x] **Test 12**: Invalid PIN rejected
- [x] **Test 13**: Admin login credentials verification

---

## 10. Viva & Interview Cheat Sheet

- **Why C++?** Required for backend performance, memory control, and standard DSA implementations.
- **Why vector over fixed array?** `std::vector` dynamically resizes at runtime, supports random access in $O(1)$, and works directly with STL algorithms like `std::sort`.
- **How is searching implemented?** Linear search iterating across the collection ($O(n)$ time complexity, $O(1)$ auxiliary space).
- **How is sorting implemented?** STL `std::sort()` which uses Introsort (QuickSort + HeapSort + InsertionSort) with an average and worst-case time complexity of $O(n \log n)$.
- **How is duplicate prevention handled?** An application-level lookup check is performed before insertion, mirrored by a unique index constraint on `account_number` in MongoDB.
- **How is transfer safety guaranteed?** Validations check sender balance, recipient existence, and self-transfer rejection before executing the atomic debit/credit operations.
