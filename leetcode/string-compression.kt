class Solution {
    fun compress(chars: CharArray): Int {
        var rp = 0
        var wp = 0

        while (rp < chars.size) {
            val currentChar = chars[rp]
            var repeat = 0

            while (rp < chars.size && chars[rp] == currentChar) {
                rp++
                repeat++
            }

            chars[wp++] = currentChar

            if (repeat != 1) {
                for (c in repeat.toString()) {
                    chars[wp++] = c
                }
            }
        }

        return wp
    }
}