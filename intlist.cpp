// intlist.cpp
// Implements class IntList
// Beatriz Cruz – Jan 16, 2026

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = nullptr;
    if (source.head == nullptr){
        return;
    }
    head = new Node;
    head->info = source.head->info;
    head-> next = nullptr;

    Node* source1= source.head->next;
    Node* curr = head;
    while(source1!=nullptr){
        curr->next = new Node;
        curr = curr->next;
        curr->info = source1->info;
        curr->next = nullptr;
        source1= source1->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* curr = head;
    while(curr != nullptr){
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
}


// return sum of values in list
int IntList::sum() const {
   int sum = 0;
   for (Node*curr = head; curr != nullptr; curr = curr->next){
    sum += curr->info;
   }
   return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
   for (Node*curr = head; curr != nullptr; curr = curr->next){
    if (curr->info == value){
        return true;
    }
   }
   return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if(head == nullptr){
    return 0;
    }
    int max = head->info;
   for (Node*curr = head; curr != nullptr; curr = curr->next){
    if (curr->info > max){
        max = curr->info;
    }

   }
   return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    int tot = 0;
    int i = 0;
    for (Node*curr = head; curr != nullptr; curr = curr->next){
        tot +=curr->info;
        i++;
   }
   if(i==0){
    return 0.0;
   }
   return static_cast<double>(tot) / static_cast<double>(i);
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode-> next = head;
    head = newNode;
}

// append value at end of list
void IntList::push_back(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode-> next = nullptr;
    if(head == nullptr){
        head = newNode;
        return;
    }

    Node* curr = head;
    while(curr->next != nullptr){
        curr = curr->next;
    }
    curr->next = newNode;
 
}

// return count of values
int IntList::count() const {
   int count = 0;
   for (Node*curr = head; curr != nullptr; curr = curr->next){
    count += 1;
   }
   return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    if (this == &source){
        return *this;
}
    Node* curr = head;
    while (curr !=nullptr){
        Node* next = curr->next;
        delete curr;
        curr = next;

    }
    head = nullptr;

    if(source.head == nullptr){
        return *this;
    }
    head = new Node;
    head->info = source.head->info;
    head->next = nullptr;
    Node* source1 = source.head->next;
    Node* tail = head;

    while(source1 != nullptr){
        tail->next = new Node;
        tail = tail->next;
        tail->info = source1->info;
        tail->next = nullptr;
        source1 = source1->next;
    }
    return *this;
    }
    

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

