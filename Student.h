#include <iostream>

using namespace std;

class Student{
public:
  int windowTime; //amount of time the student needs at the window
  int waitTime; //how long the student is in the queue (exitTick - entryTick)
  int entryTick; //clock tick student entered the queue
  int exitTick; //clock tick student walks up to a window

  Student();
  Student(int wi, int en);
  ~Student();

};
