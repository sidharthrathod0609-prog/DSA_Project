#include<bits/stdc++.h>
using namespace std;

#include "../include/BankRepository.h"

// Simple testing assertions
int totalTests = 0;
int passedTests = 0;

void assertTest(string testName, bool condition) {
    totalTests++;
    if (condition) {
        passedTests++;
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    cout << "\n===================================================\n";
    cout << "     RUNNING BANK SYSTEM DSA UNIT & EDGE TESTS      \n";
    cout << "===================================================\n";

    BankRepository repo;

    // Test 1: Account creation
    bool created = repo.addAccount("100003", "C1003", "Priya Verma", "9876543212", "priya@gmail.com", "9999", "Savings", 15000.0);
    assertTest("Test 1: Create valid new account", created == true);

    // Test 2: Edge Case - Duplicate account number
    bool duplicate = repo.addAccount("100003", "C1004", "Duplicate User", "9876543213", "dup@gmail.com", "0000", "Savings", 1000.0);
    assertTest("Test 2: Prevent duplicate account creation", duplicate == false);

    // Test 3: Search account (Linear Search)
    int idx = repo.searchAccount("100003");
    assertTest("Test 3: Search existing account", idx != -1);

    int notFoundIdx = repo.searchAccount("999999");
    assertTest("Test 4: Search non-existent account returns -1", notFoundIdx == -1);

    // Test 5: Deposit
    bool depositOk = repo.depositMoney("100003", 2500.0);
    assertTest("Test 5: Deposit valid amount", depositOk == true);

    // Test 6: Edge Case - Negative/Zero Deposit
    bool negDeposit = repo.depositMoney("100003", -500.0);
    assertTest("Test 6: Reject negative deposit", negDeposit == false);

    // Test 7: Withdraw
    bool withdrawOk = repo.withdrawMoney("100003", 5000.0);
    assertTest("Test 7: Withdraw with sufficient balance", withdrawOk == true);

    // Test 8: Edge Case - Insufficient Balance
    bool overdraw = repo.withdrawMoney("100003", 999999.0);
    assertTest("Test 8: Reject withdrawal exceeding balance", overdraw == false);

    // Test 9: Transfer
    bool transferOk = repo.transferMoney("100001", "100002", 1000.0);
    assertTest("Test 9: Transfer money between different accounts", transferOk == true);

    // Test 10: Edge Case - Transfer to same account
    bool sameTransfer = repo.transferMoney("100001", "100001", 500.0);
    assertTest("Test 10: Reject transfer to same account", sameTransfer == false);

    // Test 11: Customer Login
    bool custLogin = repo.customerLogin("100001", "1234");
    assertTest("Test 11: Valid customer PIN login", custLogin == true);

    bool badPin = repo.customerLogin("100001", "0000");
    assertTest("Test 12: Invalid PIN rejected", badPin == false);

    // Test 12: Admin Login
    bool adminOk = repo.adminLogin("admin", "admin123");
    assertTest("Test 13: Admin login credentials", adminOk == true);

    // Summary
    cout << "===================================================\n";
    cout << "Tests Passed: " << passedTests << " / " << totalTests << endl;
    if (passedTests == totalTests) {
        cout << "[ALL UNIT TESTS PASSED SUCCESSFULLY]\n";
    }
    cout << "===================================================\n\n";

    return (passedTests == totalTests) ? 0 : 1;
}
