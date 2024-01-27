/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

void splitHelper(Node*& in, Node*& odds, Node*& evens, Node*& lastOdd, Node*& lastEven) {
    if (in == nullptr) {
        return;
    }

    Node* nextNode = in->next; 
    in->next = nullptr;

    if (in->value % 2 == 1) { 
        if (lastOdd != nullptr) {
            lastOdd->next = in; 
        } else {
            odds = in;
        }
        lastOdd = in; 
    } else {
        if (lastEven != nullptr) {
            lastEven->next = in; 
        } else {
            evens = in;
        }
        lastEven = in;
    }
    
    splitHelper(nextNode, odds, evens, lastOdd, lastEven);
}

void split(Node*& in, Node*& odds, Node*& evens){
    Node* lastOdd = nullptr;
    Node* lastEven = nullptr;
    splitHelper(in, odds, evens, lastOdd, lastEven);
    in = nullptr; // Ensure 'in' is set to nullptr at the end
}



/* If you needed a helper function, write it here */