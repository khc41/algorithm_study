class Solution {
    fun decodeString(s: String): String {
        val numStack = ArrayDeque<Int>()
        val stringStack = ArrayDeque<String>()

        var currentNum = 0
        var currentStr = StringBuilder()

        for (ch in s) {
            if (ch.isDigit()) {
                currentNum = currentNum * 10 + (ch - '0')
                continue
            }
            if (ch == '[') {
                numStack.addFirst(currentNum)
                stringStack.addFirst(currentStr.toString())
                currentNum = 0
                currentStr.clear()
                continue
            }
            if (ch == ']') {
                val num = numStack.removeFirst()
                val str = stringStack.removeFirst()
                val repeat = currentStr.toString().repeat(num)
                currentStr = StringBuilder(str).append(repeat)
                continue
            }
            currentStr.append(ch)
        }
        return currentStr.toString()
    }
}