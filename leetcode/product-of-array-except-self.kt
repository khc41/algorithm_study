class Solution {
    fun productExceptSelf(nums: IntArray): IntArray {
        val len = nums.size
        val pre = IntArray(len)
        val sur = IntArray(len)
        val result = IntArray(len)
        pre[0] = 1
        sur[len - 1] = 1
        for (i in 0 until len - 1) {
            pre[i + 1] = pre[i] * nums[i]
            sur[len - i - 2] = sur[len - i - 1] * nums[len - i - 1]
        }
        for (i in 0 until len) {
            result[i] = pre[i] * sur[i]
        }
        return result
    }
}