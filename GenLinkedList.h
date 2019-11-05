#include <iostream>
#include "ListNode.h"

using namespace std;

template <typename T>

class GenLinkedList
{
  public:
    GenLinkedList();
    ~GenLinkedList();

    void insertFront(T d);
    void insertBack(T d); //doubly linked list only
    T removeFront();
    T removeBack(); //doubly linked list only
    T deletePos(int pos); //AKA removeAt()
    int find(T d);
    ListNode<T>* remove(T d);

    bool isEmpty();
    void printList();
    unsigned int getSize();

  private:
    ListNode<T>* front;
    ListNode<T>* back; //doubly linked list only
    unsigned int size;  //size can't be negative
};

///////////////////////////////////////////////


template <typename T>
GenLinkedList<T>::GenLinkedList()
{
  size = 0;
  front = NULL; //nullptr
  back = NULL; //doubly linked list only
}

template <typename T>
GenLinkedList<T>::~GenLinkedList()
{
  ListNode<T>* previous;
  while (front -> next != NULL)
  {
    previous = front;
    front = front -> next;
    front -> prev = NULL;
    delete previous;
  }
}

template <typename T>
unsigned int GenLinkedList<T>::getSize()
{
  return size;
}

template <typename T>
bool GenLinkedList<T>::isEmpty()
{
  if (size == 0)
  {
    return true;
  }
  return false;
}

template <typename T>
void GenLinkedList<T>::printList()
{
  ListNode<T>* current = front;

  while (current != NULL)
  {
    cout << current -> data << endl;
    current = current -> next;
  }
}

template <typename T>
void GenLinkedList<T>::insertFront(T d)
{
  ListNode<T>* node = new ListNode<T>(d);

  if (size == 0)
    back = node;
  else
    node -> next = front;
    front -> prev = node;

  front = node;
  ++size;
}

template <typename T>
T GenLinkedList<T>::removeFront()
{
  ListNode<T>* ft = front;
  if (size == 1)
  {
    back = NULL;
  }
  else
  {
    front -> next -> prev = NULL;
  }
  front = front -> next;
  T temp = ft -> data;
  ft -> next = NULL;
  delete ft;
  --size;
  return temp;
}

template <typename T>
void GenLinkedList<T>::insertBack(T d)
{
  ListNode<T>* node = new ListNode<T>(d);
  if (size == 0)
      front = node;
  else
      node -> prev = back;
      back -> next = node;

  back = node;
  ++size;
}

template <typename T>
T GenLinkedList<T>::removeBack()
{
  ListNode<T>* bk = back;
  if (size == 1)
  {
    front = NULL;
  }
  else
  {
    back -> prev -> next = NULL;
  }
  back = back -> prev;
  T temp = bk -> data;
  bk -> next = NULL;
  delete bk;
  --size;
  return temp;
}

template <typename T>
T GenLinkedList<T>::deletePos(int pos)
{
  int idx = 0;  //tracks position
  ListNode<T>* current = front;
  ListNode<T>* previous = front;
  while (idx != pos)
  {
    ++idx;
    previous = current;
    current = current -> next;
  }

  T temp = current -> data;
  previous -> next = current -> next;
  current -> next = NULL;
  delete current;
  --size;
  return temp;
}

template <typename T>
ListNode<T>* GenLinkedList<T>::remove(T d)
{
  //check if list is empty
  ListNode<T>* current = front;

  while (current -> data != d)
  {
    current = current -> next;
    if (current == NULL)
    {
      return NULL;
    }
  }

  if (current == front)
  {
    front = current -> next;
  }
  else
  {
    current -> prev -> next = current -> next;
  }

  if (current == back)
  {
    back = current -> prev;
  }
  else
  {
    current -> next -> prev = current -> prev;
  }
  current -> next = NULL;
  current -> prev = NULL;
  --size;
  return current;
}

template <typename T>
int GenLinkedList<T>::find(T d)
{
  int idx = 0;
  ListNode<T>* current = front;
  while (current != NULL)
  {
    if (current -> data == d)
    {
      return idx;
    }
    ++idx;

    current = current -> next;
  }
  return -1;
}
