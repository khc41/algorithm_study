class Solution {
    fun longestSubarray(nums: IntArray): Int {
        var left = 0
        var k = 0
        var result = 0

        for (right in nums.indices) {
            if (nums[right] == 0) k++

            while (k > 1) {
                if (nums[left++] == 0) k--
            }

            result = maxOf(result, right - left)
        }

        return result
    }
}