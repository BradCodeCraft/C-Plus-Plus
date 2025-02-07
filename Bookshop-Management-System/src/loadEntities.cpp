// +---------------------------------+
// |            IMPORTS              |
// +---------------------------------+
#include "./book.cpp"
#include <cstdlib>
#include <iostream>

// +---------------------------------+
// |              MAIN               |
// +---------------------------------+
void loadBookEntity() {
  system("clear");

  Book b;
  bool isValidOption;
  int userInputChoice;

  std::cout << "\n|" << std::string(20, ' ') << "The Book Nook"
            << std::string(20, ' ') << "|\n\n";

  std::cout << "Options:\n"
            << "  1. Add Book\n"
            << "  2. See All Books\n"
            << "  3. Search Book\n"
            << "  4. Update All Books\n"
            << "  5. Update Book\n"
            << "  6. Delete All Books\n"
            << "  7. Delete Book\n"
            << "  8. Exit\n\n";

  std::cout << "Choice: ";
  std::cin >> userInputChoice;

  switch (userInputChoice) {
  case 1:
    b.createBook();
    break;
  case 2:
    b.readAllBooks();
    break;
  case 3:
    b.readBook();
    break;
  case 4:
    b.updateAllBooks();
    break;
  case 5:
    b.updateBook();
    break;
  case 6:
    break;
  case 7:
    break;
  case 8:
    system("clear");

    return;
    break;
  default:
    isValidOption = false;
    while (!isValidOption) {
      std::cout << "Invalid Option! Try again: ";
      std::cin >> userInputChoice;

      isValidOption = userInputChoice >= 1 && userInputChoice <= 8;
    }
    switch (userInputChoice) {
    case 1:
      b.createBook();
      break;
    case 2:
      b.readAllBooks();
      break;
    case 3:
      b.readBook();
      break;
    case 4:
      b.updateAllBooks();
      break;
    case 5:
      b.updateBook();
      break;
    case 6:
      break;
    case 7:
      break;
    case 8:
      system("clear");

      return;
      break;
    }
  }
  return;
}
