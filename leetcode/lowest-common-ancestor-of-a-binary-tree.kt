/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int = 0) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

class Solution {
    fun lowestCommonAncestor(root: TreeNode?, p: TreeNode?, q: TreeNode?): TreeNode? {
        if (root == null || root == p || root == q) {
            return root
        }

        val leftNode = lowestCommonAncestor(root.left, p, q)
        val rightNode = lowestCommonAncestor(root.right, p, q)

        if (leftNode != null && rightNode != null) {
            return root
        }

        return leftNode ?: rightNode
    }
}