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
    fun maxDepth(root: TreeNode?): Int {
        if (root == null) return 0
        var depth = 0
        var queue = ArrayDeque<TreeNode>()
        queue.addLast(root)
        while (queue.isNotEmpty()) {
            val currSize = queue.size
            for (i in 0 until currSize) {
                val curr = queue.removeFirst()
                if (curr.left != null) queue.addLast(curr.left)
                if (curr.right != null) queue.addLast(curr.right)
            }
            depth++
        }
        return depth
    }
}