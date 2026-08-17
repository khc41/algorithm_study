class Solution {
    fun longestOnes(nums: IntArray, k: Int): Int {
        var lp = 0
        var rp = 0
        var result = 0
        var zeros = 0

        while (rp < nums.size) {
            if (nums[rp] == 0) zeros++

            while (zeros > k) {
                if (nums[lp] == 0) {
                    zeros--
                }
                lp++
            }
            result = maxOf(result, rp - lp + 1)
            rp++
        }
        return result
    }
}