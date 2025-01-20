#include "quiz.cpp"
#include <iostream>
#include <string>

void getQuizzes(std::vector<Quiz> &quizzes) {
  std::cout << "Enter quiz question: ";
  std::string question;
  std::getline(std::cin, question);

  std::cout << "Enter option 1: ";
  std::string optionOne;
  std::getline(std::cin, optionOne);

  std::cout << "Enter option 2: ";
  std::string optionTwo;
  std::getline(std::cin, optionTwo);

  std::cout << "Enter option 3: ";
  std::string optionThree;
  std::getline(std::cin, optionThree);

  std::cout << "Enter option 4: ";
  std::string optionFour;
  std::getline(std::cin, optionFour);

  std::cout << "Which is the correct option: ";
  std::string correctOptionString;
  std::cin >> correctOptionString;
  std::cin.ignore();
  std::cout << std::endl;
  int correctOption = std::stoi(correctOptionString);

  std::vector<std::string> options{optionOne, optionTwo, optionThree,
                                   optionFour};

  quizzes.push_back(Quiz(question, options, correctOption));
}

int main() {
  int userScore = 0;
  int numOfQuestion;
  std::vector<Quiz> quizzes;

  std::cout << "How many question is in this quiz? ";
  std::cin >> numOfQuestion;
  std::cin.ignore();

  for (int i = 0; i < numOfQuestion; i++) {
    getQuizzes(quizzes);
  }

  for (Quiz quiz : quizzes) {
    quiz.displayQuiz();
    userScore += quiz.getAnswer();
  }

  std::cout << "That was the last question! You scored: " << userScore << "/"
            << quizzes.size() << " (" << userScore * 100 / quizzes.size()
            << "%)";

  return 1;
}
