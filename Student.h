#include <iostream>

using namespace std;

class Student{
public:
  int windowTime;
  int waitTime;
  int entryTick;
  int exitTick;

  Student();
  Student(int wi, int wa, int en, int ex);
  ~Student();

  int getWindowTime();
  int getWaitTime();
  void setWaitTime(int w);
  int getEntry();
  void setEntry(int en);
  int getExit();
  void setExit(int ex);
};
