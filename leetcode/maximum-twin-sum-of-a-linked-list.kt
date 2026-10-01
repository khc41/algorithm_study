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
        var result = 0
        var cur = head
        var prev: ListNode? = null
        val stack = ArrayDeque<Int>()
        while (cur != null) {
            stack.addFirst(cur.`val`)
            val nextTemp = cur.next
            cur.next = prev
            prev = cur
            cur = nextTemp
        }

        while (!stack.isEmpty()) {
            result = maxOf(stack.removeLast() + prev!!.`val`, result)
            prev = prev.next
        }
        return result
    }
}