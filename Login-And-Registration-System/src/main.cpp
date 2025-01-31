#include "loadFunctions.cpp"
#include "nlohmann/json.hpp"
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>

int main() {
  // --- Clear Console
  system("clear");

  // --- Variables
  std::map<std::string, std::map<std::string, std::string>> accountsMap =
      loadAccounts();
  std::string userChoice;
  bool runningStatus = true;
  bool validUserChoice;

  while (runningStatus) {
    std::cout << std::endl
              << "=============== Welcome to AuthGen ==============="
              << std::endl
              << std::endl;

    std::cout << "Options:" << std::endl
              << "  1. Login" << std::endl
              << "  2. Register" << std::endl
              << "  3. Exit" << std::endl
              << std::endl;

    std::cout << "Choose: ";
    std::cin >> userChoice;

    switch (std::stoi(userChoice)) {
    case 1:
      loadLogin(accountsMap, runningStatus);
      break;
    case 2:
      loadRegister(accountsMap);
      break;
    case 3:
      loadExit(runningStatus);
      break;
    default:
      validUserChoice = false;

      while (!validUserChoice) {
        std::cout << "Invalid Option! Try again: ";
        std::cin >> userChoice;

        validUserChoice =
            1 <= std::stoi(userChoice) && std::stoi(userChoice) <= 3;
      }
      switch (std::stoi(userChoice)) {
      case 1:
        loadLogin(accountsMap, runningStatus);
        break;
      case 2:
        loadRegister(accountsMap);
        break;
      case 3:
        loadExit(runningStatus);
        break;
      }
    }
  }
}
