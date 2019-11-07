#include "Simulation.h"
#include <iostream>
#include <fstream>

using namespace std;


Simulation::Simulation(string f){
  fileName = f;
}

Simulation::~Simulation(){
  delete studentQueue;
  delete studentList;
}

void Simulation::Simulate(){
  ifstream sourceFile;
  sourceFile.open(fileName);
  if(sourceFile.is_open()){
    int count = 1;
    string line;
    const char* temp;

    getline(sourceFile, line);//Line 1
    temp = line.c_str();
    int numWindows = atoi(temp);
    Window winArr[numWindows];
    for(int i = 0; i < numWindows; ++i){
      winArr[i] = Window();
    }

    getline(sourceFile, line);//Line 2
    int entryTick = atoi(line.c_str());

    int clockTick = 0;
    while(true){
      if(clockTick == entryTick){//Adding new set of students to the queue
        getline(sourceFile, line);
        for(int i = 0; i < atoi(line.c_str()); ++i){
          getline(sourceFile, line);
          int windowTime = atoi(line.c_str());
          studentQueue -> insert(Student(windowTime, entryTick));
        }

        getline(sourceFile, line);//new entry tick for next set of students
        entryTick = atoi(line.c_str());
      }
      for(int i = 0; i < numWindows; ++i){
        if(winArr[i].isOpen()){
          if(!studentQueue -> isEmpty()){
            winArr[i].currentStudent = studentQueue -> remove();
            winArr[i].responseTime = winArr[i].currentStudent.getWindowTime();
            winArr[i].currentStudent.setExit(clockTick);
            winArr[i].isOpen = false;
          }
          else{ //There is no student in the queue, so the window stays open and is idle
            ++winArr[i].idleTime;
          }
        }
        else { //Window is currently handling a student
          --winArr[i].responseTime;
        }

        if(winArr[i].responseTime == 0 && winArr[i].currentStudent != NULL){
          studentList -> insertFront(winnArr[i].currentStudent);
          winnArr[i].isOpen = true;
          winnArr[i].currentStudent = NULL;
        }
      }
      ++clockTick;
    }
  }
}
