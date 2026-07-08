class Solution {
    fun reverseWords(s: String): String {
        val chars = s.trim().reversed().toCharArray()
        var rp = 0
        var wp = 0
        var i = 0

        while (rp < chars.size) {
            while (rp < chars.size && chars[rp] == ' ') {
                rp++
            }
            if (rp >= chars.size) break
            if (wp > 0) {
                chars[wp++] = ' '
            }
            var wordStart = wp
            while (rp < chars.size && chars[rp] != ' ') {
                chars[wp++] = chars[rp++]
            }

            var wordEnd = wp - 1

            while (wordStart < wordEnd) {
                val tmp = chars[wordEnd]
                chars[wordEnd] = chars[wordStart]
                chars[wordStart] = tmp
                wordEnd--
                wordStart++
            }

        }
        return String(chars, 0, wp)
    }
}