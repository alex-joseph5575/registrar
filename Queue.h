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
    T peek();
    bool isEmpty();

    int front;
    int rear;
    int getSize();

    GenLinkedList<T> myLinkedList;
};

template <typename T>Queue<T>::Queue(){
  myLinkedList = new GenLinkedList<T>();
  front = 0;
  rear = -1;
}

template <typename T>Queue<T>::~Queue(){

}

template <typename T>void Queue<T>::insert(T d){
  myLinkedList.insertFront(d);
  rear++;
}

template <typename T> T Queue<T>::remove(){
  //Check ifEmpty
  T d = NULL;
  if(!isEmpty()){
      d = myLinkedList.removeFront();
  } else {
    //throw QueueException("Queue is empty, nothing to remove");
    cout << "Queue is empty, nothing to remove";
    exit(0);
  }
  return d;
}

template <typename T> T Queue<T>::peek(){
  //Might not be necessary
  //check ifEmpty
}

template <typename T> bool Queue<T>::isEmpty(){
  return myLinkedList.isEmpty();
}

template <typename T> int Queue<T>::getSize(){
  return myLinkedList.getSize();
}
