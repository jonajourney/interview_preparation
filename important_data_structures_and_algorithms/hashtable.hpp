#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <iostream>
using namespace std;

class linked_list{
private:
  int value;
  linked_list next;
public:
  //constructor of linked list
  linked_list(int value){
    this.value = value;
    next = NULL;
  }

  void insert(int insert_value, linked_list next_list=NULL){
    linked_list new_list = new linked_list();
    new_list.value = insert_value;
    if(next_list != NULL){
      //means inserting to a place with previous list and next list
      previous_list.next = new_list.prev;
      new_list.next = next_list.prev;
    }
    else{
      //this is the end of the list
      if(previous_list ==NULL){
        //the first list
      }
    }

  }

}

#endif
