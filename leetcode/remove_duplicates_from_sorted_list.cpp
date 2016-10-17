/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

Additional note : we can instantiate the struct ListNode using :

ListNode * test = new ListNode(0);
*/

#include <iostream>

using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * current = head;

        if(head==NULL) return head;
        while(current->next!=NULL){
            if((current->val) != (current->next->val)){
                //means a different element appeared
                //just a normal operation (do not do anything)
                current=current->next;
            }
            else{
                //same element found, what u need to do is "skip" the repeated element(s)
                current->next = current->next->next;
            }
        }

        return head;
    }
};
