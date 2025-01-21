#include "../include/course.h"
#include <string>

Course::Course(std::string name, int credit, double gpa) {
  this->name = name;
  this->credit = credit;
  this->gpa = gpa;
}

std::string Course::getName() { return this->name; }

int Course::getCredit() { return this->credit; }

double Course::getGpa() { return this->gpa; }
