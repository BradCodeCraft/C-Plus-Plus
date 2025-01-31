#include "../include/account.h"
#include <cctype>
#include <iostream>
#include <string>

// --- General Constructor
Account::Account(std::string inputLoginUsername,
                 std::string inputLoginPassphrase, std::string inputAccountName,
                 std::string inputAccountType) {
  this->AccountDetails["loginUsername"] = inputLoginUsername;
  this->AccountDetails["loginPassphrase"] = inputLoginPassphrase;
  this->AccountDetails["accountName"] = inputAccountName;
  this->AccountDetails["accountType"] = inputAccountType;
};

// --- Login Constructor
Account::Account(
    std::string inputLoginUsername, std::string inputLoginPassphrase,
    std::map<std::string, std::map<std::string, std::string>> accounts) {
  bool validAccount = Account::validateLoggingInAccount(
      inputLoginUsername, inputLoginPassphrase, accounts);

  if (validAccount) {
    std::cout << "Account Validated" << std::endl;

    this->AccountDetails["loginUsername"] =
        accounts[inputLoginUsername]["loginUsername"];
    this->AccountDetails["loginPassphrase"] =
        accounts[inputLoginUsername]["loginPassphrase"];
    this->AccountDetails["accountName"] =
        accounts[inputLoginUsername]["accountName"];
    this->AccountDetails["accountType"] =
        accounts[inputLoginUsername]["accountType"];

    system("clear");
  } else {
    std::cout << "Account Invalid! Please Contact IT Support!" << std::endl;

    return;
  }
}

// --- Login Method
bool Account::validateLoggingInAccount(
    std::string inputLoginUsername, std::string inputLoginPassphrase,
    std::map<std::string, std::map<std::string, std::string>> inputAccounts) {
  if (inputAccounts[inputLoginUsername].size() == 0) {
    std::cout << "Account Not Found! Please Go Back and Register!!"
              << std::endl;

    return false;
  } else {
    int attempt = 3;
    bool validPassphrase;

    if (inputAccounts[inputLoginUsername]["loginPassphrase"] !=
        inputLoginPassphrase) {
      validPassphrase = false;

      while (!validPassphrase && attempt > 0) {
        std::cout << "Invalid Passphrase! Please Try Again: ";
        std::cin >> inputLoginPassphrase;

        validPassphrase =
            inputAccounts[inputLoginUsername]["loginPassphrase"] ==
            inputLoginPassphrase;

        if (validPassphrase) {
          return true;
        }

        attempt--;
      }

      std::cout
          << "You have run out of attempts! Please try again at a later point!"
          << std::endl;
      return false;
    } else {
      return true;
    }
  }
}

// -- Register Constructor
Account::Account(
    std::string inputLoginUsername, std::string inputLoginPassphrase,
    std::string inputAccountName, std::string inputAccountType,
    std::map<std::string, std::map<std::string, std::string>> &inputAccounts) {
  validateAccountPassword(inputLoginPassphrase);
};

// -- Register Method
bool Account::validateRegisteringAccount(
    std::string inputLoginUsername, std::string inputLoginPassphrase,
    std::string inputAccountName,
    std::map<std::string, std::map<std::string, std::string>> inputAccounts) {
  if (inputAccounts[inputLoginUsername].size() != 0) {
    std::cout << "Can't create account! Error Code 400" << std::endl;

    return false;
  } else {
    bool validPassphrase = validateAccountPassword(inputLoginPassphrase);

    while (!validPassphrase) {
      std::cout << "Invalid Passphrase! Try a different passphrase: ";
      std::cin >> inputLoginPassphrase;

      validPassphrase = validateAccountPassword(inputLoginPassphrase);
    }

    return validPassphrase;
  }
}

// -- Getters
std::map<std::string, std::string> Account::getAccountDetails() {
  return this->AccountDetails;
}

bool Account::validateAccountPassword(std::string inputLoginPassphrase) {
  int minLength = 6;
  int maxLength = 13;
  bool hasLower = false;
  bool hasUpper = false;
  bool hasDigit = false;
  bool hasSpecial = false;

  if (inputLoginPassphrase.length() < minLength ||
      inputLoginPassphrase.length() > maxLength) {
    return false;
  }

  for (char letter : inputLoginPassphrase) {
    if (std::islower(letter)) {
      hasLower = true;
    } else if (std::isupper(letter)) {
      hasUpper = true;
    } else if (std::isdigit(letter)) {
      hasDigit = true;
    } else if (std::ispunct(letter)) {
      hasSpecial = true;
    }
  }

  return hasLower && hasUpper && hasDigit && hasSpecial;
}

void Account::setAccountName(std::string inputNewAccountName) {
  this->AccountDetails["accountName"] = inputNewAccountName;
}

void Account::setLoginPassphrase(std::string inputNewLoginPassphrase) {
  this->AccountDetails["loginPassphrase"] = inputNewLoginPassphrase;
}
