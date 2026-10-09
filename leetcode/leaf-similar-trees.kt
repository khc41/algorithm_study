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
    fun leafSimilar(root1: TreeNode?, root2: TreeNode?): Boolean {
        val list1 = getLeaf(root1)
        val list2 = getLeaf(root2)
        return list1 == list2
    }

    fun getLeaf(root: TreeNode?) :ArrayList<Int> {
        val list = arrayListOf<Int>()
        if(root == null) return list
        val stack = ArrayDeque<TreeNode>()
        stack.addLast(root)
        while(stack.isNotEmpty()) {
            val curr = stack.removeLast()
            if(curr.left == null && curr.right == null) list.add(curr.`val`)
            curr.right?.let { stack.addLast(it) }
            curr.left?.let { stack.addLast(it) }
        }
        return list
    }
}