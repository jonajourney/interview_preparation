/*
got solution from leetcode : tamugaoqi 
still not that familiar with linked list (need more practice!)
*/

#include <iostream>
#include <vector>

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
    ListNode* reverseList(ListNode* head) {
            ListNode* prev=NULL;
            ListNode* curr = head;
            ListNode* temp;

            while(curr){
                //while current is not null, point temp to curr-> next and link current to the back of prev
                temp = curr->next;
                curr->next = prev;
                prev=curr;
                curr=temp;
            }
            return prev;
    }
};

/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        int i=0;
        ListNode* temp = head;
        ListNode* new_node;
        vector <int> array;

        while(temp!=NULL){
            array.push_back(temp->val);
            temp = temp->next;
        }

        new_node->val = new ListNode(array.at(array.size()));

        for(int i=array.size()-1;i>=0;i--){
            new_node->next->val = new ListNode(array.at(i));
        }

        return new_node;
    }
};
*/