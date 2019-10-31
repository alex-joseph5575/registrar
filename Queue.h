#include <iostream>
#include "LinkedList.h"

using namespace std;

template <typename E>
class Queue
{
  public:
    Queue(); //constructor
    ~Queue(); //destructor

    void insert(E d);
    E remove();
    E peek();
    bool isEmpty();

    int front;
    int rear;
    int size;
    int getSize();

    LinkedList<E> myLinkedList;
};

template <typename E>Queue<E>::Queue(){
  //initialize Linked List
  size = 0;
  front = 0;
  rear = -1;
}

template <typename E>Queue<E>::~Queue(){
  
}

template <typename E>void Queue<E>::insert(E d){
  //LinkedList insertBack function
  size++;
  rear++;
}

template <typename E> E Queue<E>::remove(){
  //Check ifEmpty
  if(!isEmpty()){
      //LinkedList removeFront function
  } else {
    throw QueueException("Queue is empty, nothing to remove");
  }
}

template <typename E> E Queue<E>::peek(){
  //Might not be necessary
  //check ifEmpty
}

template <typename E> bool Queue<E>::isEmpty(){
  return myLinkedList.isEmpty();
}

template <typename E> int Queue<E>::getSize(){
  return size;
}
