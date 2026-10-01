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
    fun pairSum(head: ListNode?): Int {
        var slow = head
        var fast = head

        while (fast?.next != null) {
            slow = slow?.next
            fast = fast.next?.next
        }

        var cur = slow
        var prev: ListNode? = null
        while (cur != null) {
            val nextTemp = cur.next
            cur.next = prev
            prev = cur
            cur = nextTemp
        }

        var result = 0
        var left = head
        var right = prev

        while (right != null) {
            result = maxOf(left!!.`val` + right.`val`, result)
            left = left.next
            right = right.next
        }

        return result
    }
}