#pragma once
#include "patient.h"
// #include "abstractLinkedList.h"
// I decided to not inherit this since this is gonna be a queue and I don't want list functions mixed up in here

 class NumQueue{
 private:
     struct NumQueueNode {
         int qNum;
         Patient p;
         NumQueueNode* next;
     };
     NumQueueNode* frontNode;
     NumQueueNode* backNode;
 public:
     // Inherited functions taken feom abstractList
    // Constructor
    // getLength()
    // isEmpty()
     NumQueue ();

     bool isEmpty ();                   // Same as the lists, if empty return true
     bool enqueue (Patient pt);
     bool dequeue ();
     int getQNum ();
     Patient getPatient ();
 };