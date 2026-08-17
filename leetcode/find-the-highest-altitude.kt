class Solution {
    fun largestAltitude(gain: IntArray): Int {
        var result = 0
        var sum = 0
        for (i in gain) {
            sum += i
            result = maxOf(sum, result)
        }
        return result
    }
}