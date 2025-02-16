#include <string>

class Book {
public:
  Book(std::string inputName, std::string inputAuthor, int inputReleasedYear);

  std::string getName();
  std::string getAuthor();
  int getReleasedYear();
  double getRating();

private:
  std::string name;
  std::string author;
  int releasedYear;
  double rating;
};
