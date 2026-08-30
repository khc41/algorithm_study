class Solution {
    fun removeStars(s: String): String {
        var stack = ArrayDeque<Char>()
        for (ch in s) {
            if (ch == '*') {
                stack.removeFirst()
                continue
            }
            stack.addFirst(ch)
        }
        return stack.reversed().joinToString("")
    }
}