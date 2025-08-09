/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int cur = l1.val + l2.val;
        ListNode head = new ListNode(cur % 10);
        sum(l1.next, l2.next, cur / 10, head);
        return head;
    }

    public void sum(ListNode l1, ListNode l2, int over, ListNode result) {
        if (l1 == null && l2 == null && over == 0) {
            return;
        }
        int cur = over;
        if (l1 != null) {
            cur += l1.val;
        }
        if (l2 != null) {
            cur += l2.val;
        }
        ListNode curNode = new ListNode(cur % 10);
        result.next = curNode;
        sum(l1 == null ? l1 : l1.next, l2 == null ? l2 : l2.next, cur / 10, curNode);
    }
}