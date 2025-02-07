// +---------------------------------+
// |            IMPORTS              |
// +---------------------------------+
#include "../include/book.h"
#include <cstdlib>
#include <exception>
#include <iostream>
#include <ostream>
#include <pqxx/pqxx>
#include <string>

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
      std::string bookPriceString;
      std::string bookQuantityString;
      this->bookId = tx.exec("SELECT * FROM books;").size() + 1;

      std::cin.ignore();
      std::cout << "Enter Book Name: ";
      std::getline(std::cin, this->bookName);

      std::cout << "Enter Book Author: ";
      std::getline(std::cin, this->bookAuthor);

      std::cout << "Enter Book Price: ";
      std::getline(std::cin, bookPriceString);
      this->bookPrice = std::stod(bookPriceString);

      std::cout << "Enter Book Quantity: ";
      std::getline(std::cin, bookQuantityString);
      this->bookQuantity = std::stoi(bookQuantityString);

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
      pqxx::result results = tx.exec("SELECT * FROM books;");
      std::string userInputChoice;
      bool isValidChoice;

      formatTable(results);

      std::cout << "\nOption:\n"
                << "  1. Back\n\n";

      std::cout << "Choice: ";
      std::cin >> userInputChoice;

      switch (std::stoi(userInputChoice)) {
      case 1:
        system("clear");

        break;
      default:
        isValidChoice = false;

        while (!isValidChoice) {
          std::cout << "Invalid Option! Try again:";
          std::cin >> userInputChoice;

          isValidChoice = std::stoi(userInputChoice) == 1;
        }
        switch (std::stoi(userInputChoice)) {
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
      std::string userInputChoice;
      bool isValidChoice;

      std::cout << "\n|" << std::string(20, ' ') << "The Book Nook"
                << std::string(20, ' ') << "|\n\n";

      pqxx::work tx(cx);
      pqxx::result results;

      std::cin.ignore();
      std::cout << "Search: ";
      std::getline(std::cin, userInputSearch);

      results = tx.exec(
          "SELECT * FROM books WHERE CAST(book_id AS TEXT) LIKE '%" +
          userInputSearch + "%' OR book_name LIKE '%" + userInputSearch +
          "%' OR book_author LIKE '%" + userInputSearch +
          "%' OR CAST(book_price AS TEXT) LIKE '$" + userInputSearch +
          "%' OR CAST(book_quantity AS TEXT) LIKE '" + userInputSearch + "%';");

      formatTable(results);

      std::cout << "\nOption:\n"
                << "  1.Back\n\n";

      std::cout << "Choice: ";
      std::cin >> userInputChoice;

      switch (std::stoi(userInputChoice)) {
      case 1:
        system("clear");

        break;
      default:
        isValidChoice = false;

        while (!isValidChoice) {
          std::cout << "Invalid Option! Try again:";
          std::cin >> userInputChoice;

          isValidChoice = std::stoi(userInputChoice) == 1;
        }
        switch (std::stoi(userInputChoice)) {
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

      std::string userInputColumn;
      std::string userInputChoice;
      bool isValidChoice;

      std::cout << "\n|" << std::string(20, ' ') << "The Book Nook"
                << std::string(20, ' ') << "|\n\n";

      std::cout << "Columns:\n"
                << "  1.Price\n"
                << "  2.Quantity\n\n";
    } else {
      std::cout << "Failed To Connect To Database!\n";
    }

    return;
  } catch (const std::exception e) {
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
