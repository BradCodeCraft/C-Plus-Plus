#include "./book.h"
#include <string>

Book::Book(std::string inputName, std::string inputAuthor,
           int inputReleasedYear) {
  this->name = inputName;
  this->author = inputAuthor;
  this->releasedYear = inputReleasedYear;
  this->rating = 0.0;
}

std::string Book::getName() { return this->name; };

std::string Book::getAuthor() { return this->author; };

int Book::getReleasedYear() { return this->releasedYear; };

double Book::getRating() { return this->rating; };
