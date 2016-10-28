/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

Note:
this answer is from : satyakam  at leetcode discussion
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
 using namespace std;
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      ListNode *ptr1 = headA;
      ListNode *ptr2 = headB;

      if(ptr1==NULL || ptr2==NULL) return NULL;
      while(p1!=NULL && ptr2!=NULL &&  ptr1!=ptr2){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

        if(ptr1==ptr2){
          return ptr1;
        }

        if(ptr1==NULL) ptr1 = headB;
        if(ptr2==NULL) ptr2 = headA;

      }
      return ptr1;
    }
};
