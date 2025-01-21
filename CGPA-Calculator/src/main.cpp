#include "cgpa.cpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

double convertLetterGradeToGpa(std::string letterGrade) {
  if (letterGrade[0] == 'A') {
    if (letterGrade[1] == '-') {
      return 3.7;
    }
    return 4.0;
  } else if (letterGrade[0] == 'B') {
    if (letterGrade[1] == '+') {
      return 3.3;
    } else if (letterGrade[1] == '-') {
      return 2.7;
    } else {
      return 3.0;
    }
  } else if (letterGrade[0] == 'C') {
    if (letterGrade[1] == '+') {
      return 2.3;
    } else if (letterGrade[1] == '-') {
      return 1.7;
    } else {
      return 2.0;
    }
  } else if (letterGrade[0] == 'D') {
    if (letterGrade[1] == '+') {
      return 1.3;
    } else if (letterGrade[1] == '-') {
      return 0.7;
    } else {
      return 1.0;
    }
  } else {
    return 0.0;
  }
}

void loadCurrentGpa(CGPA calculator, bool &running) {
  // -- Clear Console
  system("clear");

  // -- Variables
  std::string userChoice;

  // -- Header
  std::cout << std::endl
            << "==================== CGPA ====================" << std::endl
            << std::endl;

  std::cout.precision(2);
  std::cout << "Your Current GPA: " << std::fixed << calculator.showCurrentGPA()
            << std::endl
            << std::endl;

  std::cout << "Available Options:" << std::endl;
  std::cout << "  1. Go Back" << std::endl;
  std::cout << "  2. Quit" << std::endl << std::endl;

  std::cout << "Choose: ";
  std::cin >> userChoice;

  if (userChoice == "1") {
    system("clear");

    return;
  } else if (userChoice == "2") {
    running = false;
  }
}

void loadAddCourse(CGPA &calculator, bool &running) {
  // -- Clear Console
  system("clear");

  // -- Variables
  std::string courseName;
  std::string stringCredit;
  std::string stringGrade;
  std::string userConfirmChoice;
  bool validUserChoice;
  int courseCredit;
  double courseGpa;

  // -- Header
  std::cout << std::endl
            << "==================== CGPA ====================" << std::endl
            << std::endl;

  std::cout << "Course Details:" << std::endl;
  std::cin.ignore();
  std::cout << "  Name: ";
  std::getline(std::cin, courseName);

  std::cout << "  Credit: ";
  std::cin >> stringCredit;
  courseCredit = std::stoi(stringCredit);

  std::cout << "  Letter Grade: ";
  std::cin >> stringGrade;
  courseGpa = convertLetterGradeToGpa(stringGrade);

  std::cout << std::endl
            << "You have entered:" << std::endl
            << "  Name: " << courseName << std::endl
            << "  Credit: " << courseCredit << std::endl
            << "  Grade: " << courseGpa << std::endl
            << std::endl;

  std::cout << "Confirm [Y/N]? ";
  std::cin >> userConfirmChoice;

  if (userConfirmChoice == "Y") {
    Course newCourse(courseName, courseCredit, courseGpa);

    calculator.insertCourse(newCourse, true);

    system("clear");
  } else if (userConfirmChoice == "N") {
    system("clear");
    return;
  } else {
    validUserChoice = false;
    while (!validUserChoice) {
      std::cout << "Invalid choice! Please try again: ";
      std::cin >> userConfirmChoice;

      if (userConfirmChoice == "Y") {
        validUserChoice = true;
        Course newCourse(courseName, courseCredit, courseGpa);

        calculator.insertCourse(newCourse, true);
      } else if (userConfirmChoice == "N") {
        validUserChoice = true;
        return;
      }
    }
  }
}

void loadShowCourses(CGPA &calculator, bool &running) {
  // -- Clear Console
  system("clear");

  // -- Variables
  std::string userChoice;

  // -- Header
  std::cout << std::endl
            << "==================== CGPA ====================" << std::endl
            << std::endl;

  // NOTE: header: |    Name    |   Credit   |   Grade   |
  std::cout << "|    Name    |   Credit   |   Grade   |" << std::endl;
  calculator.showCourses();

  std::cout << std::endl << "Available Options:" << std::endl;
  std::cout << "  1. Go Back" << std::endl;
  std::cout << "  2. Quit" << std::endl << std::endl;

  std::cout << "Choose: ";
  std::cin >> userChoice;

  if (userChoice == "1") {
    system("clear");

    return;
  } else if (userChoice == "2") {
    running = false;
  }
}

int main() { // TODO:
  // -- Clear Console
  system("clear");

  // -- Variables
  CGPA calculator;
  bool running = true;
  bool validUserChoice;

  // -- Header
  while (running) {
    std::cout << std::endl
              << "==================== Welcome To CGPA ===================="
              << std::endl
              << std::endl;

    std::cout << "Available Options: " << std::endl;
    std::cout << "  1. Show Current GPA" << std::endl;
    std::cout << "  2. Add Courses" << std::endl;
    std::cout << "  3. Show Courses" << std::endl;
    std::cout << "  4. Clear Courses" << std::endl;
    std::cout << "  5. Load" << std::endl;
    std::cout << "  6. Save" << std::endl;
    std::cout << "  7. Quit" << std::endl << std::endl;

    std::cout << "Choose: ";
    std::string userChoice;
    std::cin >> userChoice;

    if (userChoice == "1") {
      loadCurrentGpa(calculator, running);
    } else if (userChoice == "2") {
      loadAddCourse(calculator, running);
    } else if (userChoice == "3") {
      loadShowCourses(calculator, running);
    } else if (userChoice == "4") {
      system("clear");

      calculator.clear();

      std::cout << "Calculator cleared";
    } else if (userChoice == "5") {
      system("clear");

      calculator.load();
    } else if (userChoice == "6") {
      system("clear");

      calculator.save();
    } else if (userChoice == "7") {
      running = false;
    } else {
      validUserChoice = false;
      while (!validUserChoice) {
        std::cout << "Invalid choice! Please try again: ";
        std::cin >> userChoice;

        if (userChoice == "1") {
          validUserChoice = true;
          loadCurrentGpa(calculator, running);
        } else if (userChoice == "2") {
          validUserChoice = true;
          loadAddCourse(calculator, running);
        } else if (userChoice == "3") {
          validUserChoice = true;
          loadShowCourses(calculator, running);
        } else if (userChoice == "4") {
          validUserChoice = true;

          system("clear");

          calculator.clear();

          std::cout << "Calculator cleared";

        } else if (userChoice == "5") {
          validUserChoice = true;

          system("clear");

          calculator.load();
        } else if (userChoice == "6") {
          validUserChoice = true;

          system("clear");

          calculator.save();
        } else if (userChoice == "7") {
          validUserChoice = true;
          running = false;
        }
      }
    }
  }
  return 1;
}
