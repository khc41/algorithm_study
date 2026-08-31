class Solution {
    fun asteroidCollision(asteroids: IntArray): IntArray {
        val stack = ArrayDeque<Int>()

        for (i in asteroids) {
            if (i > 0) {
                stack.addFirst(i)
                continue
            }
            var isExplode = false
            while (!stack.isEmpty()) {
                val last = stack.removeFirst()
                if (last < 0) {
                    stack.addFirst(last)
                    stack.addFirst(i)
                    break
                }
                if (abs(i) < abs(last)) {
                    stack.addFirst(last)
                    break
                }
                if (abs(i) == abs(last)) {
                    isExplode = true
                    break
                }
            }
            if (stack.isEmpty() && !isExplode) {
                stack.addFirst(i)
            }
        }
        return stack.reversed().toIntArray()
    }
}