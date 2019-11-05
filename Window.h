#include <iostream>
#include "Student.h"

using namespace std;

class Window
{
  public:
    bool isOpen;
    int idleTime;
    int responseTime;
    Student currentStudent;

    Window();
    ~Window();
};
