#ifndef LINKEDLIST
#define LINKEDLIST
#include <iostream>

using namespace std;

struct node{
  int value;
  node *next;
}

class LinkedList{
private:
  node *head;
  int listLength;
public:
  LinkedList();
  bool insertNode(node * newNode, int position);
  bool removeNode(int position);
  void printList();
  ~LinkedList();
  }

}
