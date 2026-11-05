/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    var maxLen = 0
    fun longestZigZag(root: TreeNode?): Int {
        zigzag(root!!.left, false, 0)
        zigzag(root!!.right, true, 0)
        return maxLen
    }

    fun zigzag(node: TreeNode?, isRight: Boolean, length: Int) {
        if (node == null) {
            return
        }
        val newLength = length + 1
        maxLen = maxOf(maxLen, newLength)
        if (isRight) {
            zigzag(node.left, false, newLength)
            zigzag(node.right, true, 0)
        } else {
            zigzag(node.right, true, newLength)
            zigzag(node.left, false, 0)
        }
    }
}