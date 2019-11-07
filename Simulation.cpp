#include "Simulation.h"
#include <iostream>
#include <fstream>

using namespace std;


Simulation::Simulation(string f){
  fileName = f;
  averageWait = 0.0;
  medianWait = 0.0;
  longestWait = 0.0;
  tenPlus = 0.0;
  averageIdle = 0.0;
  longestIdle = 0.0;
  fivePlus = 0.0;
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

    getline(sourceFile, line);//Line 1: number of windows
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
        cout << studentQueue -> getSize() << endl;
      for(int i = 0; i < numWindows; ++i){
        cout << "Test1" << endl;
        cout << winArr[i].isOpen << endl;
        if(winArr[i].isOpen){
          cout << "Test2" << endl;
          if(!studentQueue -> isEmpty()){
            cout << "Test3" << endl;
            Student stud;
            cout << "Studdy" << endl;
            stud = studentQueue -> remove();
            cout << "Stud time" << endl;
            winArr[i].currentStudent = stud;
            cout << "Test4" << endl;
            winArr[i].responseTime = winArr[i].currentStudent.windowTime;
            cout << "Test5" << endl;
            winArr[i].currentStudent.exitTick = clockTick;
            cout << "Test6" << endl;
            winArr[i].isOpen = false;
            cout << "Test7" << endl;

          }
          else{ //There is no student in the queue, so the window stays open and is idle
            ++winArr[i].idleTime;
          }
        }
        else { //Window is currently handling a student
          --winArr[i].responseTime;
        }

        cout << winArr[i].isOpen << endl;
        if(winArr[i].responseTime == 0 && !winArr[i].isOpen){
          cout << "true" << endl;
          studentList -> insertFront(winArr[i].currentStudent);
          cout << "insertfront works" << endl;
          winArr[i].isOpen = true;
          cout << "got here" << endl;
        }
      }
      if(sourceFile.eof()){
        break;
      }
      ++clockTick;
    }

    //Calculate metrics
    double numStudents = 0.0;
    int listSize = studentList -> getSize();
    Student s;

    for (int i = 0; i < listSize; ++i)
    {
      s = studentList -> removeFront();
      ++numStudents;
      averageWait += s.waitTime;
      medianWait += s.waitTime;
      if (s.waitTime > longestWait)
      {
        longestWait = s.waitTime;
      }

      if (s.waitTime >= 10.0)
      {
        ++tenPlus;
      }

      averageWait /= numStudents;
      medianWait /= 2.0;
    }

    for (Window w : winArr)
    {
      averageIdle += w.idleTime;
      if (w.idleTime > longestIdle)
      {
        longestIdle = w.idleTime;
      }

      if (w.idleTime >= 5.0)
      {
        ++fivePlus;
      }
    }

  }
  sourceFile.close();


  //Print metrics
  cout << "Average student wait time: " << averageWait << " minutes" << endl;
  cout << "Median student wait time: " << medianWait << " minutes" << endl;
  cout << "Longest student wait time: " << longestWait << " minutes" << endl;
  cout << "Number of students who waited longer than ten minutes: " << tenPlus << endl;
  cout << "Average window idle time: " << averageIdle << " minutes" << endl;
  cout << "Longest window idle time: " << longestIdle << " minutes" << endl;
  cout << "Number of windows that idled longer than 5 minutes: " << fivePlus << endl;
}
