#include <iostream>

using namespace std;

Window::Window()
{
  isOpen = true;
  idleTime = 0;
  responseTime = 0;
  currentStudent = NULL;
}

Window::~Window()
{

}
