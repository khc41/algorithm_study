class Solution {
    fun increasingTriplet(nums: IntArray): Boolean {
        var first = Int.MAX_VALUE
        var second = Int.MAX_VALUE
        for (i in 0 until nums.size) {
            if (nums[i] <= first) {
                first = nums[i]
                continue
            } else if (nums[i] <= second) {
                second = nums[i]
                continue
            }
            return true
        }
        return false
    }
}