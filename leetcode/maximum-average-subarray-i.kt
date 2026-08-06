class Solution {
    fun findMaxAverage(nums: IntArray, k: Int): Double {
        var sum = 0.0
        var result = 0.0
        for (i in 0 until nums.size) {
            if (i < k) {
                sum += nums[i]
                if (i == k - 1) {
                    result = sum / k
                }
                continue
            }
            sum += (nums[i] - nums[i - k])
            result = maxOf(result, sum / k)
        }
        return result
    }
}