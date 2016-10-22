/*
Given a linked list, determine if it has a cycle in it.

Note:
use floyd cycle detection algorithm
-both slow pointer and fast pointer need to start at the same point!
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
    bool hasCycle(ListNode *head) {
      if(head==NULL || head->next==NULL) return false;
      ListNode* slow=head;
      ListNode* fast=head->next;

      while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
          return true;
        }

      }

      return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
      if(head==NULL ) return false;
      ListNode* slow=head;
      ListNode* fast=head;

      while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
          return true;
        }

      }

      return false;
    }
};

/*
nice python solution:
by StefanPochmann
Took 88 ms and the "Accepted Solutions Runtime Distribution" doesn't show any faster Python submissions. The "trick" is to not check all the time whether we have reached the end but to handle it via an exception. "Easier to ask for forgiveness than permission."

The algorithm is of course Tortoise and hare.


WHY?
Because there's only two conditions that the correct code should return False:

    when the linked list is empty.
    when there's no cycle in the linked list. Because the cycle could only happen at the end of the list, this condition also means that the last node in the list has a Null "node.next" property and an assignment such as fast = fast.next.next will fail.



def hasCycle(self, head):
    try:
        slow = head
        fast = head.next
        while slow is not fast:
            slow = slow.next
            fast = fast.next.next
        return True
    except:
        return False
*/
