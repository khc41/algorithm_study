/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    fun oddEvenList(head: ListNode?): ListNode? {
        if (head == null || head?.next == null) {
            return head
        }
        var odd = head
        var even = head?.next
        val evenHead = even
        while (odd?.next != null && even?.next != null) {
            odd?.next = odd?.next?.next
            even?.next = even?.next?.next
            odd = odd.next
            even = even.next
        }
        odd.next = evenHead
        return head
    }
}