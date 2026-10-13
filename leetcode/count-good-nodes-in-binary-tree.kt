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
    fun goodNodes(root: TreeNode?): Int {
        return dfs(root, root!!.`val`)
    }

    fun dfs(node: TreeNode?, maxNum: Int): Int {
        if (node == null) {
            return 0
        }

        if (maxNum <= node.`val`) {
            return dfs(node.left, node.`val`) + dfs(node.right, node.`val`) + 1
        }

        return dfs(node.left, maxNum) + dfs(node.right, maxNum)
    }
}