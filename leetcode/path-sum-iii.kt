class Solution {
    fun pathSum(root: TreeNode?, targetSum: Int): Int {
        val map = HashMap<Long, Int>()
        map[0L] = 1
        return dfs(root, map, 0L, targetSum.toLong())
    }

    fun dfs(node: TreeNode?, map: HashMap<Long, Int>, sum: Long, targetSum: Long): Int {
        if (node == null) return 0

        val currentSum = sum + node.`val`
        var count = map.getOrDefault(currentSum - targetSum, 0)

        map[currentSum] = map.getOrDefault(currentSum, 0) + 1

        count += dfs(node.left, map, currentSum, targetSum)
        count += dfs(node.right, map, currentSum, targetSum)

        map[currentSum] = map.getOrDefault(currentSum, 0) - 1
        return count
    }
}