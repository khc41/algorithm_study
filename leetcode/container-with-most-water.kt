class Solution {
    fun maxArea(height: IntArray): Int {
        var left = 0
        var right = height.size - 1
        var result = getExtend(left, right, height)
        while (left < right) {
            if (height[left] < height[right]) {
                left++
            } else if (height[right] < height[left]) {
                right--
            } else {
                left++
                right--
            }
            result = Math.max(result, getExtend(left, right, height))
        }
        return result
    }

    fun getExtend(left: Int, right: Int, height: IntArray): Int {
        return Math.min(height[left], height[right]) * (right - left)
    }
}