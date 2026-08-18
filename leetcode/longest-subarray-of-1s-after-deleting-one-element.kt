class Solution {
    fun longestSubarray(nums: IntArray): Int {
        var left = 0
        var right = 0
        var k = 0
        var result = 0
        var containZero = false

        while (right < nums.size) {
            if (nums[right] == 0) {
                k++
                containZero = true
            }

            while (k > 1) {
                if (nums[left++] == 0) k--
            }

            result = maxOf(result, right - left + 1 - k)
            right++
        }

        return if (containZero) result else result - 1
    }
}