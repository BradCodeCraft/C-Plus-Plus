#include "account.cpp"
#include "nlohmann/json.hpp"
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>

std::map<std::string, std::map<std::string, std::string>> loadAccounts() {
  std::ifstream data("./src/accounts.json");
  nlohmann::json dataJson = nlohmann::json::parse(data);
  std::map<std::string, std::map<std::string, std::string>> resultMap;

  for (auto account : dataJson) {
    std::map<std::string, std::string> accountMap;

    std::string accountLoginUsername = account["loginUsername"];
    std::string accountLoginPassphrase = account["loginPassphrase"];
    std::string accountAccountName = account["accountName"];
    std::string accountAccountType = account["accountType"];

    accountMap["loginUsername"] = accountLoginUsername;
    accountMap["loginPassphrase"] = accountLoginPassphrase;
    accountMap["accountName"] = accountAccountName;
    accountMap["accountType"] = accountAccountType;

    resultMap[accountLoginUsername] = accountMap;
  }

  return resultMap;
};

void setAccounts(std::map<std::string, std::map<std::string, std::string>>
                     inputAccountsMap) {
  system("clear");

  nlohmann::json dataJson;

  for (auto account : inputAccountsMap) {
    nlohmann::json accountDetailsJson;

    accountDetailsJson["loginUsername"] = account.second["loginUsername"];
    accountDetailsJson["loginPassphrase"] = account.second["loginPassphrase"];
    accountDetailsJson["accountName"] = account.second["accountName"];
    accountDetailsJson["accountType"] = account.second["accountType"];

    dataJson[account.second["loginUsername"]] = accountDetailsJson;
  }

  std::ofstream data("./src/accounts.json");
  data << std::setw(2) << dataJson << std::endl;
  data.close();
}

bool validateAccountPassword(std::string inputLoginPassphrase) {
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

void loadChangeName(Account &inputUserAccount,
                    std::map<std::string, std::map<std::string, std::string>>
                        &inputAccountsMap) {
  system("clear");

  std::string userInputNewName;

  std::cout << std::endl
            << "=============== Welcome back to AuthGen, "
            << inputUserAccount.getAccountDetails()["accountName"]
            << " ===============" << std::endl
            << std::endl;

  std::cin.ignore();
  std::cout << "New Name: ";
  std::getline(std::cin, userInputNewName);
  inputUserAccount.setAccountName(userInputNewName);
  inputAccountsMap[inputUserAccount.getAccountDetails()["loginUsername"]] =
      inputUserAccount.getAccountDetails();

  setAccounts(inputAccountsMap);
}

void loadChangePassphrase(
    Account &inputUserAccount,
    std::map<std::string, std::map<std::string, std::string>>
        &inputAccountsMap) {
  system("clear");

  std::string userOldPassphrase;
  std::string userNewPassphrase;
  bool validPassphrase;

  std::cout << std::endl
            << "=============== Welcome back to AuthGen, "
            << inputUserAccount.getAccountDetails()["accountName"]
            << " ===============" << std::endl
            << std::endl;

  std::cout << "Old passphrase: ";
  std::cin >> userOldPassphrase;

  if (userOldPassphrase ==
      inputUserAccount.getAccountDetails()["loginPassphrase"]) {

    std::cout << "New passphrase: ";
    std::cin >> userNewPassphrase;

    validPassphrase = validateAccountPassword(userNewPassphrase);

    while (!validPassphrase) {
      std::cout << "Invalid Passphrase! Passphrase must be between 6 and 13 "
                   "characters, have at least one uppercase character, one "
                   "lowercase character, one digit, and one special character"
                << std::endl
                << "New passphrase: ";
      std::cin >> userNewPassphrase;

      validPassphrase = validateAccountPassword(userNewPassphrase);
    }

    inputUserAccount.setLoginPassphrase(userNewPassphrase);
    inputAccountsMap[inputUserAccount.getAccountDetails()["loginUsername"]] =
        inputUserAccount.getAccountDetails();

    setAccounts(inputAccountsMap);
  } else {
    std::cout << std::endl << "Invalid Passphrase!" << std::endl;

    return;
  }
}

void loadExit(bool &inputRunningStatus) {
  system("clear");

  inputRunningStatus = false;

  std::cout << std::endl
            << "=============== Exit from AuthGen ===============" << std::endl
            << std::endl;

  std::cout << "Goodbye, user! Hope you have a good day!" << std::endl;
};

void loadExit(Account inputAccount, bool &inputLoggedInStatus,
              bool &inputRunningStatus) {
  system("clear");

  inputLoggedInStatus = false;
  inputRunningStatus = false;

  std::cout << std::endl
            << "=============== Exit from AuthGen ===============" << std::endl
            << std::endl;

  std::cout << "Goodbye, " << inputAccount.getAccountDetails()["accountName"]
            << "! Hope you have a good day!" << std::endl;
}

void loadAllProfiles(Account inputUserAccount,
                     std::map<std::string, std::map<std::string, std::string>>
                         inputAccountsMap) {
  system("clear");

  std::string userChoice;
  bool validUserChoice;

  std::cout << std::endl
            << "=============== Welcome back to AuthGen, "
            << inputUserAccount.getAccountDetails()["accountName"]
            << " ===============" << std::endl
            << std::endl;

  std::cout << "Username     Passphrase     Name     Type" << std::endl
            << std::endl;

  for (auto account : inputAccountsMap) {
    std::string accountLoginUsername = account.second["loginUsername"];
    std::string accountLoginPassphrase = account.second["loginPassphrase"];
    std::string accountAccountName = account.second["accountName"];
    std::string accountAccountType = account.second["accountType"];

    std::cout << accountLoginUsername << "     " << accountLoginPassphrase
              << "     " << accountAccountName << "     " << accountAccountType
              << std::endl;
  }
}

void loadProfile(Account &inputUserAccount,
                 std::map<std::string, std::map<std::string, std::string>>
                     inputAccountsMap) {
  system("clear");

  std::string userChoice;
  bool validUserChoice;

  std::cout << std::endl
            << "=============== Welcome back to AuthGen, "
            << inputUserAccount.getAccountDetails()["accountName"]
            << " ===============" << std::endl
            << std::endl;

  std::cout << "Profile Details" << std::endl
            << "  Username: "
            << inputUserAccount.getAccountDetails()["loginUsername"]
            << std::endl
            << "  Passphrase: "
            << inputUserAccount.getAccountDetails()["loginPassphrase"]
            << std::endl
            << "  Name: " << inputUserAccount.getAccountDetails()["accountName"]
            << std::endl
            << "  Type: " << inputUserAccount.getAccountDetails()["accountType"]
            << std::endl
            << std::endl;

  std::cout << "Options:" << std::endl
            << "  1. Change Name" << std::endl
            << "  2. Change Passphrase" << std::endl
            << "  3. Exit" << std::endl
            << std::endl;

  std::cout << "Choose: ";
  std::cin >> userChoice;

  switch (std::stoi(userChoice)) {
  case 1:
    loadChangeName(inputUserAccount, inputAccountsMap);
    break;
  case 2:
    loadChangePassphrase(inputUserAccount, inputAccountsMap);
    break;
  case 3:
    system("clear");
    break;
  default:
    validUserChoice = false;

    while (!validUserChoice) {
      std::cout << "Invalid Choice! Try again: ";
      std::cin >> userChoice;

      validUserChoice =
          std::stoi(userChoice) >= 1 && std::stoi(userChoice) <= 3;
    }
    switch (std::stoi(userChoice)) {
    case 1:
      loadChangeName(inputUserAccount, inputAccountsMap);
      break;
    case 2:
      loadChangePassphrase(inputUserAccount, inputAccountsMap);
      break;
    case 3:
      system("clear");
      break;
    }
  }
};

void loadWelcome(Account &inputUserAccount, bool &inputRunningStatus,
                 std::map<std::string, std::map<std::string, std::string>>
                     inputAccountsMap) {
  system("clear");

  // --- Variables
  std::string userChoice;
  bool loggedInStatus = true;
  bool validUserChoice;

  while (loggedInStatus) {
    std::cout << std::endl
              << "=============== Welcome back to AuthGen, "
              << inputUserAccount.getAccountDetails()["accountName"]
              << " ===============" << std::endl
              << std::endl;

    if (inputUserAccount.getAccountDetails()["accountType"] == "USER") {
      std::cout << "Options:" << std::endl
                << "  1. Profile" << std::endl
                << "  2. Change Passphrase" << std::endl
                << "  3. Exit" << std::endl
                << std::endl;
    } else if (inputUserAccount.getAccountDetails()["accountType"] == "ADMIN") {
      std::cout << "Options:" << std::endl
                << "  1. Profile" << std::endl
                << "  2. Change Passphrase" << std::endl
                << "  3. See Accounts" << std::endl
                << "  4. Exit" << std::endl;
    }

    std::cout << "Choose: ";
    std::cin >> userChoice;

    if (inputUserAccount.getAccountDetails()["accountType"] == "USER") {
      switch (std::stoi(userChoice)) {
      case 1:
        loadProfile(inputUserAccount, inputAccountsMap);
        break;
      case 2:
        loadChangePassphrase(inputUserAccount, inputAccountsMap);
        break;
      case 3:
        loadExit(inputUserAccount, loggedInStatus, inputRunningStatus);
        break;
      default:
        validUserChoice = false;

        while (!validUserChoice) {
          std::cout << "Invalid Choice! Try again: ";
          std::cin >> userChoice;

          switch (std::stoi(userChoice)) {
          case 1:
            validUserChoice = true;
            loadProfile(inputUserAccount, inputAccountsMap);
            break;
          case 2:
            validUserChoice = true;
            loadChangePassphrase(inputUserAccount, inputAccountsMap);
            break;
          case 3:
            validUserChoice = true;
            loadExit(inputUserAccount, loggedInStatus, inputRunningStatus);
            break;
          }
        }
      }
    } else if (inputUserAccount.getAccountDetails()["accountType"] == "ADMIN") {
      switch (std::stoi(userChoice)) {
      case 1:
        loadProfile(inputUserAccount, inputAccountsMap);
        break;
      case 2:
        loadChangePassphrase(inputUserAccount, inputAccountsMap);
        break;
      case 3:
        loadAllProfiles(inputUserAccount, inputAccountsMap);
        break;
      case 4:
        loadExit(inputUserAccount, loggedInStatus, inputRunningStatus);
        break;
      default:
        validUserChoice = false;

        while (!validUserChoice) {
          std::cout << "Invalid Choice! Try again: ";
          std::cin >> userChoice;

          switch (std::stoi(userChoice)) {
          case 1:
            validUserChoice = true;
            loadProfile(inputUserAccount, inputAccountsMap);
            break;
          case 2:
            validUserChoice = true;
            loadChangePassphrase(inputUserAccount, inputAccountsMap);
            break;
          case 3:
            validUserChoice = true;
            loadAllProfiles(inputUserAccount, inputAccountsMap);
            break;
          case 4:
            validUserChoice = true;
            loadExit(inputUserAccount, loggedInStatus, inputRunningStatus);
            break;
          }
        }
      }
    }
  }
}

void loadLogin(
    std::map<std::string, std::map<std::string, std::string>> &inputAccountsMap,
    bool &inputRunningStatus) {
  system("clear");

  // --- Variables
  std::string userInputLoginUsername;
  std::string userInputLoginPassphrase;

  std::cout << std::endl
            << "=============== Login to AuthGen ===============" << std::endl
            << std::endl;

  std::cout << "Username: ";
  std::cin >> userInputLoginUsername;

  std::cout << "Passphrase: ";
  std::cin >> userInputLoginPassphrase;

  Account currentAccount(userInputLoginUsername, userInputLoginPassphrase,
                         inputAccountsMap);

  if (currentAccount.getAccountDetails().size() == 0) {
    return;
  } else {
    loadWelcome(currentAccount, inputRunningStatus, inputAccountsMap);
  }
};

void loadRegister(std::map<std::string, std::map<std::string, std::string>>
                      &inputAccountsMap) {
  system("clear");

  // --- Variables
  std::string userInputLoginUsername;
  std::string userInputLoginPassphrase;
  std::string userInputAccountName;
  bool validPassphrase;

  std::cout << std::endl
            << "=============== Register to AuthGen ==============="
            << std::endl
            << std::endl;

  std::cout << "Username: ";
  std::cin >> userInputLoginUsername;

  if (inputAccountsMap[userInputLoginUsername].size() != 0) {
    std::cout << "Invalid Username!" << std::endl;
    return;
  } else {
    std::cout << "Passphrase: ";
    std::cin >> userInputLoginPassphrase;
    std::cin.ignore();

    validPassphrase = validateAccountPassword(userInputLoginPassphrase);

    while (!validPassphrase) {
      std::cout << "Invalid Passphrase! Passphrase must be between 6 and 13 "
                   "characters, have at least one uppercase character, one "
                   "lowercase character, one digit, and one special character"
                << std::endl
                << "New passphrase: ";
      std::cin >> userInputLoginPassphrase;
      std::cin.ignore();

      validPassphrase = validateAccountPassword(userInputLoginPassphrase);
    }

    std::cout << "Name: ";
    std::getline(std::cin, userInputAccountName);

    std::map<std::string, std::string> accountMap;

    accountMap["loginUsername"] = userInputLoginUsername;
    accountMap["loginPassphrase"] = userInputLoginPassphrase;
    accountMap["accountName"] = userInputAccountName;
    accountMap["accountType"] = "USER";

    inputAccountsMap[userInputLoginUsername] = accountMap;
    setAccounts(inputAccountsMap);
  }
};
