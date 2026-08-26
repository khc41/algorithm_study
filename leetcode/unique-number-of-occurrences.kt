class Solution {
    fun uniqueOccurrences(arr: IntArray): Boolean {
        val map = arr.toList().groupingBy { it }.eachCount()
        return map.values.size == map.values.toSet().size
    }
}