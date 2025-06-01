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
    public List<List<Integer>> levelOrder(TreeNode root) {
        if(root == null){
            return List.of();
        }
        List<List<Integer>> result = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while(!queue.isEmpty()){
            queue = bfs(result, queue);
        }

        return result;
    }

    public Queue<TreeNode> bfs(List<List<Integer>> result, Queue<TreeNode> cur){
        List<Integer> sub = new ArrayList<>();
        Queue<TreeNode> child = new LinkedList<>();
        while(!cur.isEmpty()){
            TreeNode curNode = cur.poll();
            sub.add(curNode.val);
            if(curNode.left != null){
                child.add(curNode.left);
            }
            if(curNode.right != null){
                child.add(curNode.right);
            }
        }
        result.add(sub);
        return child;
    }
}