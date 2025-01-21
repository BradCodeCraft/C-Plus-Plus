#include "../include/cgpa.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

CGPA::CGPA() {};

double CGPA::showCurrentGPA() {
  int totalCredits = 0;
  double totalPoints = 0;

  for (Course course : this->courses) {
    totalCredits += course.getCredit();
    totalPoints += (course.getGpa() * course.getCredit());
  }

  if (totalCredits == 0) {
    return 0.0;
  } else {
    return totalPoints / totalCredits;
  }
}

void CGPA::insertCourse(Course course, bool showMessage) {
  int oldSize = this->courses.size();

  this->courses.push_back(course);

  if (showMessage) {
    if (this->courses.size() > oldSize) {
      std::cout << "Course Added!";
    } else {
      std::cout << "Error! Course Not Added!";
    }
  }
}

void CGPA::showCourses() {
  for (Course course : this->courses) {
    if (course.getName().length() % 2 == 0) {
      std::cout << "|" << std::string((12 - course.getName().length()) / 2, ' ')
                << course.getName()
                << std::string((12 - course.getName().length()) / 2, ' ')
                << "|";
    } else {
      std::cout << "|" << std::string((12 - course.getName().length()) / 2, ' ')
                << course.getName()
                << std::string((12 - course.getName().length()) / 2 + 1, ' ')
                << "|";
    }

    std::cout << std::string(5, ' ') << course.getCredit()
              << std::string(6, ' ') << "|";

    std::cout.precision(1);
    std::cout << std::string(4, ' ') << std::fixed << course.getGpa()
              << std::string(4, ' ') << "|" << std::endl;
  }
}

void CGPA::clear() { this->courses.clear(); }

void CGPA::load() {
  std::ifstream data("./src/data.json");
  nlohmann::json dataJson = nlohmann::json::parse(data);
  auto coursesJson = dataJson["courses"];
  int numOfCoursesAdded = 0;

  for (auto course : coursesJson) {
    Course currentCourse(course["name"], course["credit"], course["gpa"]);
    this->insertCourse(currentCourse, false);

    numOfCoursesAdded++;
  }

  if (numOfCoursesAdded > 0) {
    if (numOfCoursesAdded == 1) {
      std::cout << "Course Loaded" << std::endl;
    } else {
      std::cout << numOfCoursesAdded << " Courses Loaded" << std::endl;
    }
  } else {
    std::cout << "Course Failed To Load";
  }

  return;
}

void CGPA::save() {
  nlohmann::json dataJson;
  int index = 0;

  for (Course course : this->courses) {
    nlohmann::json courseJson;

    courseJson["name"] = course.getName();
    courseJson["credit"] = course.getCredit();
    courseJson["gpa"] = course.getGpa();

    dataJson["courses"][index] = courseJson;
    index++;
  }

  if (index > 0) {
    std::cout << "Saved Successfully" << std::endl;
  } else {
    std::cout << "Saved Failed" << std::endl;
  }

  std::ofstream data("./src/data.json");
  data << std::setw(2) << dataJson << std::endl;
  data.close();

  return;
}
