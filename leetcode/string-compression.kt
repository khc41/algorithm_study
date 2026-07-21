class Solution {
    fun compress(chars: CharArray): Int {
        var rp = 0
        var wp = 0
        var lastChar = chars[0]
        var repeat = 0
        while (rp < chars.size) {
            if (lastChar != chars[rp] && wp <= rp) {
                chars[wp++] = lastChar
                lastChar = chars[rp]
                if (repeat != 1) {
                    for (c in repeat.toString()) {
                        chars[wp++] = c
                    }
                }
                repeat = 0
                continue
            } else if (rp == chars.size - 1) {
                chars[wp++] = lastChar
                repeat++
                if (repeat != 1) {
                    for (c in repeat.toString().toCharArray()) {
                        chars[wp++] = c
                    }
                }
            }
            rp++
            repeat++
        }
        return wp
    }
}