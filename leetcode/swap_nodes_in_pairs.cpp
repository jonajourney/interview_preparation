/*

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 #include <iostream>
 #include <algorithm>

 using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      //gotta take lots of time to digest it nicely:
      //this diagram helps:
      /*
      prev\head\head->next\head->next->next
      TO
      prev\head->next\head\head->next->next
      */

      ListNode* dummy = new ListNode(0);
      dummy->next = head;
      ListNode* prev = dummy;

      while(head!=NULL &&head->next!=NULL){
        ListNode* nnext = head->next->next;
        prev->next = head->next;
        head->next->next = head;
        head->next=nnext;
        prev = head;
        head = nnext;
      }
      return dummy->next; //why?because this is the swapped "new head"
    }

    ListNode* swapPairs2(ListNode* head) {
      //solution inspiration by : leetcode
      if(head==NULL || head->next == NULL) return head;
      swap(head,head->next);
      head->next->next =  swapPairs(head->next->next);
      return head;
    }
};


/*
ListNode* dummy = new ListNode(0);
dummy->next = head;
ListNode* left = dummy ;//initialize the left node
ListNode* right = head;//initialize the right node
ListNode* temp;

while(left && right){//both left and right not null
  temp = left;
  left = right;
  right = temp;
}
*/
