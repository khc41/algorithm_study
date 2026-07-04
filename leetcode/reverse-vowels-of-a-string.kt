class Solution {
    fun reverseVowels(s: String): String {
        val sb = StringBuilder()
        val stack = ArrayDeque<Char>()
        val vowels = setOf('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U')
        for (i in 0 until s.length) {
            if (vowels.contains(s[i])) {
                stack.addLast(s[i])
            }
        }
        for (i in 0 until s.length) {
            if (vowels.contains(s[i])) {
                sb.append(stack.removeLast())
                continue
            }
            sb.append(s[i])
        }
        return sb.toString()
    }
}