// File Name: SortedList.cpp
// 
// Author: Rene A. Carbajal
// Date: 11/13/2021
// Assignment Number: 5
// CS2308.003 
// Instructor: Jill Seaman
// 
// This file contains the member functions definitions for SortedList.h file.
// 


#include <iostream>
#include <cassert>
using namespace std;

#include "SortedList.h"

/*
  SortedList: creates an empty list, n is the maximum size of the list.
  param-1: int, the max value
  Returns: void
*/

  SortedList::SortedList(int size) 
  {
    head = NULL;
    maxSize = size;
    count = 0;
  }

/*
  ~SortedList: cleans up the dynamically allocated memory.
  param-1: none
  Returns: bool, true or false.
*/

  SortedList::~SortedList() 
  {
    ListNode *p;
    while (!isEmpty()) 
    {
        p = head;
        head = head->next;
        delete p;
    }
  }

/*
  isEmpty: checks if list is empty.
  param-1: none
  Returns: bool, true or false.
*/

  bool SortedList::isEmpty() 
  {
    return (head==NULL);
  }

/*
  isFull: checks if list is full.
  param-1: none
  Returns: bool, true or false.
*/

  bool SortedList::isFull() 
  {     
    if(maxSize == count)
      return true;
    else
      return false;
  }

/*
  displayList: outputs the elements in the list, 
               in sorted order, numbered starting at 1, to the ostream. 
  param-1: out, output elements.
  Returns: void
*/

  void SortedList::displayList(ostream& out) {
    int num = 1;
    ListNode *p = head;
    while (p!=NULL) 
    {
        out << num++ << " " << p->value  << endl;
        p = p->next;
    }
  }

/*
  remove: finds a string, and if found, removes s from the list.
  param-1: string, the string we are looking for.
  Returns: void
*/

  void SortedList::remove(string val) 
  {
    
    ListNode *p = head;      // to traverse the list
    ListNode *n = NULL;   // trailing node pointer
    
    // skip nodes not equal to val, stop at last
    while (p && p->value!=val) 
    {
        n = p;        // save it!
        p = p->next;  // advance it
    }
    
    // p not null: val is found, set links + delete
    if (p) 
    {
        if (n==NULL) 
        {   // p points to the first elem.
            head = p->next;
            delete p;
        } 
        else 
        {            // n points to the predecessor
            n->next = p->next;
            delete p;
        }
        count--;
    }
  }

/*
  insert: Inserts string val into the list, 
          in the position that will keep the list in ascending order.
  param-1: string, the string we want to insert into the list.
  Returns: void
*/

  void SortedList::insert(string val) 
  {
    assert(!isFull());

    ListNode *newNode = new ListNode;
    newNode->value = val;
    newNode->next = NULL;

    ListNode *p = head;
    ListNode *c = NULL;

    if(head == NULL)
    {
      head = newNode;
    }
    else if(p->value > val) //if first element is bigger than val
      {
        head = newNode;
        newNode->next = p;
      }
    else
    {
      while(p && p->value < val) //stop when p is bigger than val
      { 
        c = p;
        p = p->next;
      }
      c->next = newNode;
      newNode->next = p;
    }

    count++;
    
  }
