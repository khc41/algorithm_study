class Solution {
    fun gcdOfStrings(str1: String, str2: String): String {
        val len1 = str1.length
        val len2 = str2.length

        if (str1 + str2 != str2 + str1) {
            return ""
        }

        return str1.substring(0, gcd(len1, len2));
    }

    fun gcd(a: Int, b: Int): Int {
        if (b == 0) return a
        return gcd(b, a % b)
    }
}