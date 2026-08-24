class Solution {
    fun pivotIndex(nums: IntArray): Int {
        val total = nums.sum()
        var left = 0

        for (i in nums.indices) {
            val right = total - left - nums[i]

            if (left == right) {
                return i
            }

            left += nums[i]
        }

        return -1
    }
}