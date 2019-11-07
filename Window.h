#include <iostream>
#include "Student.h"

using namespace std;

class Window
{
  public:
    bool isOpen; //true if no student currently being helped,
    int idleTime; //amount of time spent with no student at the window
    int responseTime; //how long the window spends responding to a student
    Student currentStudent;

    Window();
    ~Window();
};
