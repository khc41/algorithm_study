class Solution {
    fun asteroidCollision(asteroids: IntArray): IntArray {
        val stack = ArrayDeque<Int>()

        for (i in asteroids) {
            var isExplode = false
            while (stack.isNotEmpty() && i < 0 && stack.last() > 0) {
                val last = stack.last()

                if (abs(i) < last) {
                    isExplode = true
                    break
                } else if (abs(i) == last) {
                    isExplode = true
                    stack.removeLast()
                    break
                } else {
                    stack.removeLast()
                }
            }

            if (!isExplode) {
                stack.addLast(i)
            }
        }
        return stack.toIntArray()
    }
}