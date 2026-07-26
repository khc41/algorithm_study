class Solution {
    fun moveZeroes(nums: IntArray): Unit {
        var lastNonZeroIdx = 0

        for (i in nums.indices) {
            if (nums[i] != 0) {
                if (i != lastNonZeroIdx) {
                    var temp = nums[lastNonZeroIdx]
                    nums[lastNonZeroIdx] = nums[i]
                    nums[i] = temp
                }
                lastNonZeroIdx++
            }
        }
    }
}