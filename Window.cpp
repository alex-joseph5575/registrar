#include <iostream>
#include "Window.h"

using namespace std;

Window::Window()
{
  isOpen = true; //no student at creation, so set to true
  idleTime = 0;
  responseTime = 0;
}

Window::~Window()
{

}
