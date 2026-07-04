class Solution {
    fun reverseVowels(s: String): String {
        var left = 0
        var right = s.length - 1
        val chars = s.toCharArray()
        val vowels = setOf('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U')

        while (left < right) {
            while (left < right && !vowels.contains(chars[left])) {
                left++
            }
            while (left < right && !vowels.contains(chars[right])) {
                right--
            }
            if (left < right) {
                val temp = chars[left]
                chars[left] = chars[right]
                chars[right] = temp
                left++
                right--
            }
        }

        return String(chars)
    }
}