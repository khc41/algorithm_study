class Solution {
    fun maxOperations(nums: IntArray, k: Int): Int {
        nums.sort()
        var left = 0
        var right = nums.size - 1
        var result = 0
        while (left < right) {
            if (nums[left] + nums[right] == k) {
                result++
                left++
                right--
            } else if (nums[left] + nums[right] > k) {
                right--
            } else {
                left++
            }
        }

        return result
    }
}