class Solution {
    fun predictPartyVictory(senate: String): String {
        var rCount = 0
        var dCount = 0
        var queue = ArrayDeque<Char>()

        for (ch in senate) {
            queue.addLast(ch)
            if (ch == 'R') rCount++ else dCount++
        }

        var rBan = 0
        var dBan = 0

        while (rCount > 0 && dCount > 0) {
            val current = queue.removeFirst()

            if (current == 'R') {
                if (rBan > 0) {
                    rCount--
                    rBan--
                } else {
                    dBan++
                    queue.addLast(current)
                }
            } else {
                if (dBan > 0) {
                    dCount--
                    dBan--
                } else {
                    rBan++
                    queue.addLast(current)
                }
            }
        }

        return if (rCount > 0) "Radiant" else "Dire"
    }
}