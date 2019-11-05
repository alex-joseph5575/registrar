#include <iostream>

using namespace std;

template <typename T>

class ListNode
{
  public:
    T data;
    ListNode* next;
    ListNode* prev; //doubly linked list only

    ListNode();
    ListNode(T d);
    ~ListNode();
};

///////////////////IMPLEMENTATION///////////////////////

template <typename T>
ListNode<T>::ListNode()
{
  data = NULL;
  next = NULL;
  prev = NULL;
}

template <typename T>
ListNode<T>::ListNode(T d)
{
  data = d;
  next = NULL; //nullptr
  prev = NULL; //doubly linked list only
}

template <typename T>
ListNode<T>::~ListNode()
{
  if (next == NULL)
  {
    delete next;
  }

    next = NULL;  //doubly linked list only
    prev = NULL;  //doubly linked list only
}
