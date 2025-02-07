// +---------------------------------+
// |            IMPORTS              |
// +---------------------------------+
#include <iostream>
#include <pqxx/pqxx>
#include <string>

// +---------------------------------+
// |            BOOK CLASS           |
// +---------------------------------+
class Book {
public:
  void createBook();
  void readAllBooks();
  void readBook();
  void updateAllBooks();
  void updateBook();
  void deleteAllBooks();
  void deleteBook();

private:
  int bookId;
  std::string bookName;
  std::string bookAuthor;
  double bookPrice;
  int bookQuantity;

  void formatTable(pqxx::result inputResult);
  void updateAllBooksPrice(pqxx::connection *inputConnection);
  void updateAllBooksQuantity(pqxx::connection *inputConnection);
};
