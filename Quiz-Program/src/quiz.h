#include <string>
#include <vector>

class Quiz {
public:
  // Constructors
  Quiz(std::string question, std::vector<std::string> options,
       int correctOption);
  // Methods
  void displayQuiz();
  int getAnswer();

private:
  std::string question;
  std::vector<std::string> options;
  int correctOption;
};
