#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(){
  windowTime = 0;
  waitTime = 0;
  entryTick = 0;
  exitTick = 0;
}

Student::Student(int wi, int wa, int en, int ex){
  windowTime = wi;
  waitTime = wa;
  entryTick = en;
  exitTick = ex;
}

Student::~Student(){

}

int Student::getWindowTime(){
  return windowTime;
}

int Student::getWaitTime(){
  return waitTime;
}

void Student::setWaitTime(int w){
  waitTime = w;
}

int Student::getEntry(){
  return entryTick;
}

void Student::setEntry(int en){
  entryTick = en;
}

int Student::getExit(){
  return exitTick;
}

void Student::setExit(int ex){
  exitTick = ex;
}