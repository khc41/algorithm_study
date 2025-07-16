/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean hasPathSum(TreeNode root, int targetSum) {
        return dfs(root, 0, targetSum);
    }

    public boolean dfs(TreeNode cur, int curSum, int targetSum) {
        if (cur == null) return false;

        curSum += cur.val;

        if (cur.left == null && cur.right == null) {
            return curSum == targetSum;
        }

        return dfs(cur.left, curSum, targetSum) || dfs(cur.right, curSum, targetSum);
    }
}
