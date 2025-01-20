#include "quiz.h"
#include <cstddef>
#include <iostream>
#include <string>

Quiz::Quiz(std::string question, std::vector<std::string> options,
           int correctOption) {
  this->question = question;
  this->options = options;
  this->correctOption = correctOption;
}

void Quiz::displayQuiz() {
  int answerNum = 1;

  std::cout << "Question: " << this->question << " ?" << std::endl;
  for (std::string option : options) {
    std::cout << "  " << answerNum << ". " << option << std::endl;
    answerNum++;
  }
}

int Quiz::getAnswer() {
  std::cout << "Answer: ";
  std::string userAnswer;
  std::cin >> userAnswer;

  if (userAnswer == std::to_string(this->correctOption)) {
    std::cout << "Correct!" << std::endl << std::endl;
    return 1;
  } else {
    std::cout << "That's wrong!" << std::endl << std::endl;
    return 0;
  }
}
