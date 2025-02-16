#include "../lib/Book/book.h"
#include <iostream>

int main() {
  Book test("The Great Gatsby", "F.Scott Fitzgerald", 1925);

  std::cout << "Name: " << test.getName() << "\n"
            << "Author: " << test.getAuthor() << "\n"
            << "Released Year: " << test.getReleasedYear() << "\n"
            << "Library Rating: " << test.getRating() << "\n\n";
  return 1;
}
