class Solution {
    fun isSubsequence(s: String, t: String): Boolean {
        var cur = 0
        val chars = s.toCharArray()
        if (s.length == 0) {
            return true
        }
        for (i in t) {
            if (chars[cur] == i) {
                if (cur == s.length - 1) {
                    return true;
                }
                cur++
            }
        }
        return false;
    }
}