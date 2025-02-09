// +---------------------------------+
// |            IMPORTS              |
// +---------------------------------+
#include "../include/book.h"
#include <chrono>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <ostream>
#include <pqxx/pqxx>
#include <string>
#include <thread>

// +---------------------------------+
// |         GLOBAL VARIABLE         |
// +---------------------------------+
const std::string HOST = "127.0.0.1";
const std::string USER = "itsbradnguyen";
const std::string PASSWORD = "1225";
const std::string DBNAME = "bookshop_management_system";
const std::string PORT = "5432";
const std::string databaseUrl = "user=" + USER + " password=" + PASSWORD +
                                +" host=" + HOST + " port=" + PORT +
                                " dbname=" + DBNAME;

// +---------------------------------+
// |           PUBLIC METHOD         |
// +---------------------------------+
void Book::createBook() {
  try {
    pqxx::connection cx(databaseUrl);

    if (cx.is_open()) {
      system("clear");

      std::cout << "\n|" << std::string(20, ' ') << "The Book Nook"
                << std::string(20, ' ') << "|\n\n";

      pqxx::work tx(cx);

      this->bookId = tx.exec("SELECT * FROM books;").size() + 1;

      std::cin.ignore();
      std::cout << "Enter Book Name: ";
      std::getline(std::cin, this->bookName);

      std::cout << "Enter Book Author: ";
      std::getline(std::cin, this->bookAuthor);

      std::cout << "Enter Book Price: ";
      std::cin >> this->bookPrice;

      std::cout << "Enter Book Quantity: ";
      std::cin >> this->bookQuantity;

      tx.exec("INSERT INTO books VALUES (" + std::to_string(this->bookId) +
              ", '" + this->bookName + "', '" + this->bookAuthor + "', " +
              std::to_string(this->bookPrice) + ", " +
              std::to_string(this->bookQuantity) + ");");
      tx.commit();

      return;
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void Book::readAllBooks() {
  try {
    pqxx::connection cx(databaseUrl);

    if (cx.is_open()) {
      system("clear");

      std::cout << "\n|" << std::string(20, ' ') << "The Book Nook"
                << std::string(20, ' ') << "|\n\n";

      pqxx::work tx(cx);
      pqxx::result results = tx.exec("SELECT * FROM books ORDER BY book_id;");
      int userInputChoice;
      bool isValidChoice;

      formatTable(results);

      std::cout << "\nOption:\n"
                << "  1. Back\n\n";

      std::cout << "Choice: ";
      std::cin >> userInputChoice;

      switch (userInputChoice) {
      case 1:
        system("clear");

        break;
      default:
        isValidChoice = false;

        while (!isValidChoice) {
          std::cout << "Invalid Option! Try again:";
          std::cin >> userInputChoice;

          isValidChoice = userInputChoice == 1;
        }
        switch (userInputChoice) {
        case 1:
          system("clear");

          break;
        }
      }

      return;
    };
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
};

void Book::readBook() {
  try {
    pqxx::connection cx(databaseUrl);

    if (cx.is_open()) {
      system("clear");

      std::string userInputSearch;
      int userInputChoice;
      bool isValidChoice;

      std::cout << "\n|" << std::string(20, ' ') << "The Book Nook"
                << std::string(20, ' ') << "|\n\n";

      pqxx::work tx(cx);
      pqxx::result results;

      std::cin.ignore();
      std::cout << "Search: ";
      std::getline(std::cin, userInputSearch);

      results =
          tx.exec("SELECT * FROM books WHERE CAST(book_id AS TEXT) LIKE '%" +
                  userInputSearch + "%' OR book_name LIKE '%" +
                  userInputSearch + "%' OR book_author LIKE '%" +
                  userInputSearch + "%' OR CAST(book_price AS TEXT) LIKE '$" +
                  userInputSearch + "%' OR CAST(book_quantity AS TEXT) LIKE '" +
                  userInputSearch + "%' ORDER BY book_id;");

      formatTable(results);

      std::cout << "\nOption:\n"
                << "  1.Back\n\n";

      std::cout << "Choice: ";
      std::cin >> userInputChoice;

      switch (userInputChoice) {
      case 1:
        system("clear");

        break;
      default:
        isValidChoice = false;

        while (!isValidChoice) {
          std::cout << "Invalid Option! Try again:";
          std::cin >> userInputChoice;

          isValidChoice = userInputChoice == 1;
        }
        switch (userInputChoice) {
        case 1:
          system("clear");

          break;
        }
      }
    } else {
      std::cout << "Failed To Connect To Database!\n";
    }

    return;
  } catch (const std::exception &e) {
    std::cerr << e.what() << "\n";
  }
};

void Book::updateAllBooks() {
  try {
    pqxx::connection cx(databaseUrl);

    if (cx.is_open()) {
      system("clear");

      int userInputChoice;
      bool isValidChoice;

      std::cout << "\n|" << std::string(20, ' ') << "The Book Nook"
                << std::string(20, ' ') << "|\n\n";

      std::cout << "Columns:\n"
                << "  1.Price\n"
                << "  2.Quantity\n\n";

      std::cout << "Choice: ";
      std::cin >> userInputChoice;
      switch (userInputChoice) {
      case 1:
        updateAllBooksPrice(&cx);
        break;
      case 2:
        updateAllBooksQuantity(&cx);
        break;
      default:
        isValidChoice = false;

        while (!isValidChoice) {
          std::cout << "\nInvalid Option! Try again: ";
          std::cin >> userInputChoice;

          isValidChoice = userInputChoice >= 1 && userInputChoice <= 2;
        }

        switch (userInputChoice) {
        case 1:
          updateAllBooksPrice(&cx);
          break;
        case 2:
          updateAllBooksQuantity(&cx);
          break;
        }
      };
    } else {
      std::cout << "Failed To Connect To Database!\n";
    }

    return;
  } catch (const std::exception e) {
    std::cerr << e.what() << "\n";
  }
};

void Book::updateBook() {
  try {
    pqxx::connection cx(databaseUrl);

    if (cx.is_open()) {
      system("clear");

      int userInputChoice;
      bool isValidChoice;

      std::cout << "\n|" << std::string(20, ' ') << "The Book Nook"
                << std::string(20, ' ') << "|\n\n";

      std::cout << "Options:\n"
                << "  1. By Book ID\n"
                << "  2. By Book Name\n\n";
      std::cin >> userInputChoice;

      switch (userInputChoice) {
      case 1:
        updateBookById(&cx);
        break;
      case 2:
        updateBookByName(&cx);
        break;
      default:
        isValidChoice = false;

        while (!isValidChoice) {
          std::cout << "\nInvalid Option! Try again: ";
          std::cin >> userInputChoice;

          isValidChoice = userInputChoice >= 1 && userInputChoice <= 2;
        }

        switch (userInputChoice) {
        case 1:
          updateBookById(&cx);
          break;
        case 2:
          updateBookByName(&cx);
          break;
        }
      }

    } else {
      std::cout << "Failed To Connect To Database!\n";
    }

    return;
  } catch (const std::exception &e) {
    std::cerr << e.what() << "\n";
  }
};

// +---------------------------------+
// |          PRIVATE METHODS        |
// +---------------------------------+
void Book::formatTable(pqxx::result results) {
  const char line = ' ';
  const std::string columnSeparator = "|";
  int bookIdColumnSize = 1;
  int bookNameColumnSize = 1;
  int bookAuthorColumnSize = 1;
  int bookPriceColumnSize = 1;
  int bookQuantityColumnSize = 1;

  for (int i = 0; i < results.size(); i++) {
    if (results[i]["book_id"].as<std::string>().size() > bookIdColumnSize) {
      bookIdColumnSize = results[i]["book_id"].as<std::string>().size();
    }
    if (results[i]["book_name"].as<std::string>().size() > bookNameColumnSize) {
      bookNameColumnSize = results[i]["book_name"].as<std::string>().size();
    }
    if (results[i]["book_author"].as<std::string>().size() >
        bookAuthorColumnSize) {
      bookAuthorColumnSize = results[i]["book_author"].as<std::string>().size();
    }
    if (results[i]["book_price"].as<std::string>().size() >
        bookPriceColumnSize) {
      bookPriceColumnSize = results[i]["book_price"].as<std::string>().size();
    }
    if (results[i]["book_quantity"].as<std::string>().size() >
        bookQuantityColumnSize) {
      bookQuantityColumnSize =
          results[i]["book_quantity"].as<std::string>().size();
    }
  }

  std::cout << columnSeparator << std::string(bookIdColumnSize, line) << "ID"
            << std::string(bookIdColumnSize, line) << columnSeparator
            << std::string(bookNameColumnSize, line) << "NAME"
            << std::string(bookNameColumnSize, line) << columnSeparator
            << std::string(bookAuthorColumnSize, line) << "AUTHOR"
            << std::string(bookAuthorColumnSize, line) << columnSeparator
            << std::string(bookPriceColumnSize, line) << "PRICE"
            << std::string(bookPriceColumnSize, line) << columnSeparator
            << std::string(bookQuantityColumnSize, line) << "QUANTITY"
            << std::string(bookQuantityColumnSize, line) << columnSeparator
            << "\n";

  for (int i = 0; i < results.size(); i++) {
    std::string bookId = results[i]["book_id"].as<std::string>();
    std::string bookName = results[i]["book_name"].as<std::string>();
    std::string bookAuthor = results[i]["book_author"].as<std::string>();
    std::string bookPrice = results[i]["book_price"].as<std::string>();
    std::string bookQuantity = results[i]["book_quantity"].as<std::string>();

    std::cout
        << columnSeparator
        << std::string(bookIdColumnSize + 2 - bookId.length(), line) << bookId
        << std::string(bookIdColumnSize, line) << columnSeparator << line
        << bookName
        << std::string(bookNameColumnSize * 2 + 3 - bookName.length(), line)
        << columnSeparator << line << bookAuthor
        << std::string(bookAuthorColumnSize * 2 + 5 - bookAuthor.length(), line)
        << columnSeparator
        << std::string(bookPriceColumnSize * 2 + 4 - bookPrice.length(), line)
        << bookPrice << line << columnSeparator
        << std::string(bookQuantityColumnSize * 2 + 7 - bookQuantity.length(),
                       line)
        << bookQuantity << line << columnSeparator;

    std::cout << "\n";
  }
};

void Book::updateAllBooksPrice(pqxx::connection *inputConnection) {
  system("clear");

  std::cout << "\n|" << std::string(20, ' ') << "The Book Nook"
            << std::string(20, ' ') << "|\n\n";

  pqxx::work tx(*inputConnection);
  double inputPrice;

  std::cout << "New Price: ";
  std::cin >> inputPrice;

  tx.exec("UPDATE books SET book_price = " + std::to_string(inputPrice) + ";");

  tx.commit();

  system("clear");

  return;
};

void Book::updateAllBooksQuantity(pqxx::connection *inputConnection) {
  system("clear");

  std::cout << "\n|" << std::string(20, ' ') << "The Book Nook"
            << std::string(20, ' ') << "|\n\n";

  pqxx::work tx(*inputConnection);
  double inputQuantity;

  std::cout << "New Quantity: ";
  std::cin >> inputQuantity;

  tx.exec("UPDATE books SET book_quantity = " + std::to_string(inputQuantity) +
          ";");

  tx.commit();

  system("clear");

  return;
};

// TODO: add third case: results.size() > 1 (else)
void Book::updateBookById(pqxx::connection *inputConnection) {
  system("clear");

  std::cout << "\n|" << std::string(20, ' ') << "The Book Nook"
            << std::string(20, ' ') << "|\n\n";

  pqxx::work tx(*inputConnection);
  pqxx::result results;
  int inputBookId;
  int userInputChoice;
  bool isValidChoice;

  std::cout << "Book ID: ";
  std::cin >> inputBookId;

  results = tx.exec("SELECT * FROM books WHERE book_id =" +
                    std::to_string(inputBookId) + ";");

  if (results.size() == 0) {
    std::cout << "There are no books matched ID " << inputBookId << ".\n";
  } else if (results.size() == 1) {
    system("clear");

    std::cout << "\n|" << std::string(20, ' ') << "The Book Nook"
              << std::string(20, ' ') << "|\n\n";
    formatTable(results);

    std::cout << "\n Options:\n"
              << "     1. Price\n"
              << "     2. Quantity\n\n";

    std::cout << "Choice: ";
    std::cin >> userInputChoice;

    switch (userInputChoice) {
    case 1:
      updateBookPrice(&results);
      break;
    case 2:
      updateBookQuantity(&results);
      break;
    default:
      isValidChoice = false;

      while (!isValidChoice) {
        std::cout << "Invalid Option! Try again: ";
        std::cin >> userInputChoice;

        isValidChoice = userInputChoice >= 1 && userInputChoice <= 2;
      }

      switch (userInputChoice) {
      case 1:
        updateBookPrice(&results);
        break;
      case 2:
        updateBookQuantity(&results);
        break;
      }
    }
  }
};

void Book::updateBookByName(pqxx::connection *inputConnection) {}

void Book::updateBookPrice(pqxx::result *inputResult) {};
void Book::updateBookQuantity(pqxx::result *inputResult) {};
