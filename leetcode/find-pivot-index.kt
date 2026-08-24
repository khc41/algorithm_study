class Solution {
    fun pivotIndex(nums: IntArray): Int {
        val array = IntArray(nums.size)
        array[nums.size - 1] = 0
        var sum = 0
        for (i in (nums.size - 2) downTo 0) {
            sum += nums[i + 1]
            array[i] = sum
        }
        if (array[0] == 0) return 0
        sum = 0
        for (i in 1 until nums.size) {
            sum += nums[i - 1]
            if (sum == array[i]) {
                return i
            }
        }
        return -1
    }
}