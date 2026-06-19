class Solution {
    fun mergeAlternately(word1: String, word2: String): String {
        val sb = StringBuilder()
        var i = 0
        val len1 = word1.length
        val len2 = word2.length

        // 두 문자열 중 하나라도 문자가 남아있다면 계속 반복
        while (i < len1 || i < len2) {
            if (i < len1) {
                sb.append(word1[i])
            }
            if (i < len2) {
                sb.append(word2[i])
            }
            i++
        }

        return sb.toString()
    }
}