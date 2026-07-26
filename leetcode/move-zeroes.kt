class Solution {
    fun moveZeroes(nums: IntArray): Unit {
        var numOfZero = 0
        var idx = 0
        while (idx < nums.size) {
            if (nums[idx] == 0) {
                numOfZero++
                idx++
                continue
            }
            nums[idx - numOfZero] = nums[idx]
            if (numOfZero > 0) {
                nums[idx] = 0
            }
            idx++
        }
    }
}