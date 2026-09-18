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

        var size = 0
        var node = head
        while (node != null) {
            size++
            node = node.next
        }
        val idx = size / 2 - 1
        node = head
        for (i in 0 until idx) {
            node = node?.next
        }
        node?.next = node?.next?.next
        return head
    }
}