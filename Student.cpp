#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(){
  windowTime = 0;
  waitTime = 0;
  entryTick = 0;
  exitTick = 0;
}

Student::Student(int wi, int en){
  windowTime = wi; //given by file
  waitTime = 0;
  entryTick = en; //given by file
  exitTick = 0;
}

Student::~Student(){

}
