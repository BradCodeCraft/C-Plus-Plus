// +---------------------------------+
// |            IMPORTS              |
// +---------------------------------+
#include "./loadEntities.cpp"
#include <cstdlib>

// +---------------------------------+
// |              MAIN               |
// +---------------------------------+
int main() {
  system("clear");

  bool isRunning = true;
  bool isValidOption;
  std::string userInputChoice;

  while (isRunning) {
    std::cout << "\n|" << std::string(20, ' ') << "The Book Nook"
              << std::string(20, ' ') << "|\n\n";

    std::cout << "Entities:\n"
              << "  1. Book\n"
              << "  2. Order\n"
              << "  3. Supplier\n"
              << "  4. Employee\n"
              << "  5. Member\n"
              << "  6. Sales\n"
              << "  7. Quit\n\n";

    std::cout << "Choice: ";
    std::cin >> userInputChoice;

    switch (std::stoi(userInputChoice)) {
    case 1:
      loadBookEntity();
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      isRunning = false;
      break;
    default:
      isValidOption = false;

      while (!isValidOption) {
        std::cout << "Invalid Option! Try again: ";
        std::cin >> userInputChoice;

        isValidOption =
            std::stoi(userInputChoice) >= 1 && std::stoi(userInputChoice) <= 7;

        switch (std::stoi(userInputChoice)) {
        case 1:
          loadBookEntity();
          break;
        case 2:
          break;
        case 3:
          break;
        case 4:
          break;
        case 5:
          break;
        case 6:
          break;
        case 7:
          isRunning = false;
          break;
        }
        break;
      }
    }
  }
  return 1;
}
