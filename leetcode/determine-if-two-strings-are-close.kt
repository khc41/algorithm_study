class Solution {
    fun closeStrings(word1: String, word2: String): Boolean {
        if (word1.length != word2.length) return false
        if (word1.toSet() != word2.toSet()) return false
        if (word1.groupingBy { it }.eachCount().values.groupingBy { it }.eachCount() != word2.groupingBy { it }
                .eachCount().values.groupingBy { it }.eachCount()) return false
        return true
    }
}