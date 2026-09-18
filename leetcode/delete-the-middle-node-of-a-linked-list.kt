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
    fun deleteMiddle(head: ListNode?): ListNode? {
        if (head == null || head.next == null) return null

        var slow = head
        var fast = head.next?.next

        while (fast != null && fast?.next != null) {
            slow = slow?.next
            fast = fast?.next?.next
        }

        slow?.next = slow?.next?.next
        return head
    }
}