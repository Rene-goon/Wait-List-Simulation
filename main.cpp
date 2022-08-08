// File Name: main.cpp
// 
// Author: Rene A. Carbajal
// Date: 11/12/2021
// Assignment Number: 6
// CS2308.003 Fall 2021
// Instructor: Jill Seaman
//
// This program should promt the user for the class size 
// and the wait list size
//

#include<iostream>
#include<iomanip>
#include <cassert>
using namespace std;

#include "SortedList.h"
#include "StringQueue.h"

int main()
{
  int classSize, waitList, position = 0;
  string option, name, ListName;
  char subOption;

  cout << "Enter class size: ";
  cin >> classSize;

  SortedList list(classSize);
  
  cout << "Enter wait list size: ";
  cin >> waitList;

  StringQueue myQueue(waitList);

  cout << "Enter the commands:" << endl;

  while(option != "quit")
  {
    cin >> option;

    if(option == "add")      //add option
    {
      cin >> name;

      if(list.isFull())
      {
        cout << ">Class is full, join the wait list (y/n)?" << endl;
        cin >> subOption;

        if(subOption == 'y' && !myQueue.isFull())
        {
          position = myQueue.enqueue(name);
          cout << ">Added at position " << position << endl;
        }
        else
          cout << ">Wait List is also full. Sorry." << endl;
      }
      else 
        list.insert(name);
    }

    else if(option == "drop")      //drop option
    {
      assert(!list.isEmpty());

      cin >> name;

      list.remove(name);

      if(!myQueue.isEmpty())
      {
        do
        {
          ListName = myQueue.dequeue();
          cout << ">Add "<< ListName << " to the class (y/n)?" << endl;
          cin >> subOption;
        }while(subOption == 'n' && !myQueue.isEmpty());
        
        if(subOption == 'y')
          list.insert(ListName);

      }
      else 
      {
        cout << ">No one added to the roster. Wait list is empty." << endl;
      }

    }

    else if(option == "pr")      //pr option
      list.displayList(cout);

    else if(option == "pwl")      //pwl option
    {
      myQueue.display(cout);
    }
  }





}