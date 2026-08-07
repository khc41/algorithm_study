class Solution {
    fun maxVowels(s: String, k: Int): Int {
        var sum = 0
        for (i in 0 until k) {
            sum += isVowel(s[i])
        }
        var maxSum = sum
        for (i in k until s.length) {
            sum += (isVowel(s[i]) - isVowel(s[i - k]))
            maxSum = maxOf(sum, maxSum)
        }
        return maxSum
    }

    fun isVowel(ch: Char): Int = if (ch in "aeiou") 1 else 0

}