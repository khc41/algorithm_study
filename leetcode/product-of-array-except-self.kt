class Solution {
    fun productExceptSelf(nums: IntArray): IntArray {
        val len = nums.size
        val result = IntArray(len)
        result[0] = 1
        for (i in 0 until len - 1) {
            result[i + 1] = result[i] * nums[i]
        }
        var last = 1
        for (i in 0 until len - 1) {
            last *= nums[len - i - 1]
            result[len - i - 2] *= last
        }
        return result
    }
}