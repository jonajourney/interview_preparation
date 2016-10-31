/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

note:
Help from benyin in leetcode discussion
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;
        ListNode* current = head;

        while(current->next!=NULL){
            if(current->next->val == val){
                current->next = current->next->next;
            }
            else{
                current = current->next;
            }
        }

        if(head->val == val) return head->next;

        return head;
    }
};

//other neat solutions:
/*
public ListNode removeElements(ListNode head, int val){
    if(head == null) return head;
    head.next = removeElements(head->next, val);
    return (head.val = val?) head.next : head;
}
*/


/*
ListNode * removeElements(ListNode* head, int val){
    ListNode **list = &head;

    while(*list!= nullptr){
        if((*list)->val == val){
            *list = (*list)->next
        }
        else{
            list = &(*list)->next;
        }
    }
}
*/

/*
void removeHelper(ListNode *&head, int val){
    if(head == nullptr){
        return;
    }
    else if(head->val == val){
        head = head->next;
    }
    else{
        removeHelper(head->next, val);   
    }
}
*/