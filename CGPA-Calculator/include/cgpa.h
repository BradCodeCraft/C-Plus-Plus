#include "../src/course.cpp"
#include <string>
#include <vector>

class CGPA {
public:
  CGPA();
  double showCurrentGPA();
  void insertCourse(Course course, bool showMessage);
  void showCourses();
  void clear();
  void load();
  void save();

private:
  std::vector<Course> courses = {};
};
