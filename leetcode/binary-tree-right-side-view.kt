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
        if (root == null) return emptyList()

        val result = mutableListOf<Int>()
        val q = ArrayDeque<Pair<TreeNode, Int>>()

        q.addFirst(root to 1)
        var saveDepth = 0
        while (q.isNotEmpty()) {
            val (node, depth) = q.removeLast()

            if (saveDepth < depth) {
                result.add(node.`val`)
                saveDepth++
            }
            node.right?.let { q.addFirst(it to depth + 1) }
            node.left?.let { q.addFirst(it to depth + 1) }
        }
        return result
    }
}