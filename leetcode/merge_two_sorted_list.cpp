/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

Solution help:
https://discuss.leetcode.com/topic/5513/my-recursive-way-to-solve-this-problem-java-easy-understanding

*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* ans;
        if(l1->val > l2-> val){
            ans = l2;
            ans->next = mergeTwoLists(l1, l2->next);

        }
        else{
            ans = l1;
            ans->next = mergeTwoLists(l1->next,l2);
        }

        return ans;
    }
};