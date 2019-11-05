#include <iostream>

using namespace std;

class Student{
public:
  int windowTime;
  int waitTime;
  int entryTick;
  int exitTick;

  Student();
  Student(int wi, int en);
  ~Student();

  int getWindowTime();
  int getWaitTime();
  void setWaitTime(int w);
  int getEntry();
  void setEntry(int en);
  int getExit();
  void setExit(int ex);
};
