#include <string>

class Course {
public:
  Course(std::string name, int credit, double gpa);
  std::string getName();
  int getCredit();
  double getGpa();

private:
  std::string name;
  int credit;
  double gpa;
};
