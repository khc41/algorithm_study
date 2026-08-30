class Solution {
    fun removeStars(s: String): String {
        var sb = StringBuilder()
        for (ch in s) {
            if (ch == '*') {
                sb.setLength(sb.length - 1)
                continue
            }
            sb.append(ch)
        }
        return sb.toString()
    }
}