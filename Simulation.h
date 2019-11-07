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

  double averageWait;
  double medianWait;
  double longestWait;
  int tenPlus;
  double averageIdle;
  double longestIdle;
  int fivePlus;
};
