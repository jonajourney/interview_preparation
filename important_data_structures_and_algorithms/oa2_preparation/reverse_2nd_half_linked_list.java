/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

public class Solution{
    public static ListNode reverseList(ListNode head){
        ListNode dummy = new ListNode(0);
        dummy.next=head;
        if (head==null || head.next == null) return head;

        ListNode fast = dummy;
        ListNode slow = dummy;

        while(fast.next!=null && fast.next.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }

        //now slow is pointing at the middle of the linked list
        ListNode pre = null;
        ListNode temp;
        head = slow.next;
        while(head!=null){
            temp = head.next;
            head.next = pre;
            pre = head;
            head = temp; 
        }

        slow.next = pre;
        return dummy.next;
    }
}