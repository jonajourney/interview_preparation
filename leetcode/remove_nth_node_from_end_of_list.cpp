/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

UNRESOLVED:
why do i have to return dummy->next, why cant i return head?

RESOLVED!:
apparently both dummy and head points to 1 lol;
*/

#include <iostream>

using namespace std;

  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution{
public:
  ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode* dummy = new ListNode(0);
    dummy->next=head;
    ListNode* ptr1 = dummy;
    ListNode* ptr2 = head;

    while(n>0){
      ptr2 = ptr2->next;
      n--;
    }

    while(ptr2){
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }

    ptr1->next = ptr1->next->next;

    //why do i have to return dummy->next, why cant i return head?
    return dummy->next;
  }


};

/*
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      int count=0;
      ListNode * tempPtr=head;
      ListNode * current=head;

      while(current !=NULL){
        count++;
        // cout<<"count"<<count<<endl;
        current = current->next;
      }


      int number = count-n;
      int counter=0;
      // cout<<"number:"<<number<<endl;

      while(counter!=number){

        tempPtr = tempPtr->next;
        counter++;
      }

      if(count==1){
        tempPtr->next =NULL;
      }
      else{
        //count  > 1
        if(tempPtr->next->next !=NULL){
          tempPtr->next = tempPtr->next->next;
        }
        else{
          tempPtr->next = NULL;
        }
      }

      return head;
    }
};

int main(){
  ListNode * head = new ListNode(1);
  Solution tester;

  cout<<tester.removeNthFromEnd(head,1);
}
*/
