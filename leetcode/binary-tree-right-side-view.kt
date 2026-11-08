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
    fun rightSideView(root: TreeNode?): List<Int> {
        val result = arrayListOf<Int>()
        if (root == null) {
            return result
        }
        val q = ArrayDeque<Pair<TreeNode, Int>>()
        var depth = 1
        var saveDepth = 0
        q.addFirst(root!! to depth)
        while (q.isNotEmpty()) {
            val curr = q.removeLast()
            if (saveDepth < curr.second) {
                result.add(curr.first.`val`)
                saveDepth++
            }
            curr.first.right?.let { q.addFirst(curr.first.right to curr.second + 1) }
            curr.first.left?.let { q.addFirst(curr.first.left to curr.second + 1) }
        }
        return result
    }
}