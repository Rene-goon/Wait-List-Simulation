// File Name: StringQueue.h
// 
// Author: Rene A. Carbajal
// Date: 11/12/2021
// Assignment Number: 5
// CS2308.003 
// Instructor: Jill Seaman
//
// This file contains the StringQueue class which contain
// the private/public meber variables
//

#include <string>
using namespace std;


class StringQueue
{
  private:
    struct StringNode  //nodes of linked list
    {
        string data;  
        StringNode *next;
    };

   StringNode *front;
   StringNode *rear;
   
   int maxSize;
   int counter;
    
  public:
    // Constructor
    StringQueue(int);
    ~StringQueue();  
    
    // Queue operations
    int enqueue(string);  //returns position where inserted, front is 1
    string dequeue();
    bool isEmpty();
    bool isFull();
    void display(ostream& out);
};
