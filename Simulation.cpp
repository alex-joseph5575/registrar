#include "Simulation.h"
#include <iostream>
#include <fstream>

using namespace std;


Simulation::Simulation(string f){
  fileName = f;
}

Simulation::~Simulation(){
  delete studentQueue;
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
    Window winArr[atoi(temp)];
    for(int i = 0; i < winArr.size; ++i){
      winArr[i] = Window();
    }

    getline(sourceFile, line);//Line 2
    int entryTick = atoi(line);

    int clockTick = 0;
    while(true){
      if(clockTick == entryTick){//Adding new set of students to the queue
        getline(sourceFile, line);
        for(int i = 0; i < atoi(line); ++i){
          getline(sourceFile, line);
          int windowTime = atoi(line);
          studentQueue.insert(Student(windowTime, entryTick));
        }

        getline(sourceFile, line);//new entry tick for next set of students
        entryTick = atoi(line);
      }

      clockTick++;
    }

    }
  }
}
