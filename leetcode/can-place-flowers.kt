class Solution {
    fun canPlaceFlowers(flowerbed: IntArray, n: Int): Boolean {
        val len = flowerbed.size
        var rest = n
        if (n == 0) {
            return true
        }
        if (len == 1) {
            if (flowerbed[0] == 0)
                return true
            return false
        }
        if (len > 1 && flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1
            rest--
        }
        for (i in 1 until len - 1) {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1
                rest--
            }
        }
        if (len > 1 && flowerbed[len - 2] == 0 && flowerbed[len - 1] == 0) {
            rest--
        }
        return rest <= 0
    }
}