#include "Queue.h"
#include "Window.h"
#include <iostream>

using namespace std;

class Simulation{
public:
  Queue<Student>* studentQueue;
  GenLinkedList<Student>* studentList;
  string fileName;


  Simulation(string f);
  ~Simulation();

  void Simulate();

  int meanWait();
  int medianWait();
  int longestWait();
  int longWait();
  int meanIdle();
  int longestIdle();
  int idleNum();
};
