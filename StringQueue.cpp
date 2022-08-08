// File Name: StringQueue.cpp
// 
// Author: Rene A. Carbajal
// Date: 11/12/2021
// Assignment Number: 5
// CS2308.003 
// Instructor: Jill Seaman
// 
// This file contains the member functions definitions for StringQueue.h file.
// 

#include <string>
#include <assert.h>
#include <iostream>
#include "StringQueue.h"
using namespace std;

/*
  StringQueue: initializes the queue.
  param-1: int, the max value
  Returns: void
*/

  StringQueue::StringQueue(int n)
  {
    front = NULL;
    rear = NULL;
    
    maxSize = n;  //max size in queue
    counter = 0;
  }

/*
  ~StringQueue: cleans up the dynamically allocated memory.
  param-1: none
  Returns: void
*/

  StringQueue::~StringQueue()
  {
    while(front != NULL)
    {
      dequeue();
    }
  }

/*
  enqueue: adds string s to the queue and returns the position.
  param-1: string, the string we are sending to the end of the queue.
  Returns: int, the position of the string in the added queue.
*/

  int StringQueue::enqueue(string s)
  {
    assert(!isFull());

    int position = 0;

    StringNode *newNode = new StringNode;  //new node
    newNode->data = s;  //sets data of new node to s
    newNode->next = NULL;

    if(isEmpty())
    {
      front = newNode; //sets front and rear to node
      rear = newNode;
      position = position + 1;
    }
    else
    {
      rear->next = newNode;
      rear = newNode;

      StringNode *ptr = front;
      while(ptr != NULL)
      {
        position = position + 1;
        ptr = ptr->next;
      } 
    }

    counter++;

    return position;
  }

/*
  dequeue: removes the front node in queue and returns the next value.
  param-1: none
  Returns: string, the next value.
*/

  string StringQueue::dequeue()
  {
    assert(!isEmpty());
    
    string value = front->data;

    StringNode *ptr = front;
    front = front->next;
    delete ptr;

    counter--;

    return value;
  }

/*
  isEmpty: checks if queue is empty.
  param-1: none
  Returns: bool, true or false.
*/

  bool StringQueue::isEmpty()
  {
    return (front==NULL);
  }

/*
  isFull: checks if queue is full.
  param-1: none
  Returns: bool, true or false.
*/

  bool StringQueue::isFull()
  {      
    if(counter == maxSize)
      return true;
    else
      return false;
  }

/*
  display:  outputs the elements in the queue numbered starting at 1, 
            one per line, from front to rear, to the ostream.
  param-1: out, output of elements.
  Returns: void
*/

  void StringQueue::display(ostream& out)
  {
     StringNode *ptr = front;
     int num = 1;
     while(ptr != NULL)
     {
       out << num++ << " " << ptr->data << endl;
       ptr = ptr->next;
     }
     
  }

