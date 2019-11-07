#include <iostream>
#include "GenLinkedList.h"

using namespace std;

template <typename T>
class Queue
{
  public:
    Queue(); //constructor
    ~Queue(); //destructor

    void insert(T d);
    T remove();
    bool isEmpty();

    int front;
    int rear;
    int getSize();

    GenLinkedList<T>* myLinkedList;
};

template <typename T>
Queue<T>::Queue(){
  myLinkedList = new GenLinkedList<T>();
  front = 0;
  rear = -1;
}

template <typename T>
Queue<T>::~Queue(){
  delete myLinkedList;
}

template <typename T>
void Queue<T>::insert(T d){ //calls the LinkedList insert front function
  myLinkedList -> insertFront(d);
  rear++;
}

template <typename T>
T Queue<T>::remove(){ //calls the LinkedList removefron function after error checking
  //Check ifEmpty
  T d;
  if(!isEmpty()){
    cout << "Queue is working" << endl;
      d = myLinkedList -> removeFront();
  } else {
    cout << "Queue is empty, nothing to remove";
    exit(0);
  }
  cout << "Queue is still working" << endl;
  return d;
}


template <typename T>
bool Queue<T>::isEmpty(){
  return myLinkedList -> isEmpty();
}

template <typename T>
int Queue<T>::getSize(){
  return myLinkedList -> getSize();
}
