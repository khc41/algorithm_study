class Solution {
    fun reverseWords(s: String): String {
        val stack = ArrayDeque<String>()
        val chars = s.trim().toCharArray()
        val result = StringBuilder()
        val sb = StringBuilder()
        for (i in 0 until chars.size) {
            if (chars[i] == ' ') {
                if (sb.length == 0) {
                    continue
                }
                stack.addFirst(sb.toString())
                sb.setLength(0)
                continue
            }
            if (i == chars.size - 1) {
                sb.append(chars[i])
                stack.addFirst(sb.toString())
                continue
            }
            sb.append(chars[i])
        }
        while (stack.size > 1) {
            result.append(stack.removeFirst())
            result.append(" ")
        }
        result.append(stack.removeFirst())
        return result.toString()
    }
}