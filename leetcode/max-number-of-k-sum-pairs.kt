class Solution {
    fun maxOperations(nums: IntArray, k: Int): Int {
        var result = 0
        val hashMap = HashMap<Int, Int>()
        for (i in nums) {
            hashMap.compute(i) { _, value -> (value ?: 0) + 1 }
        }

        for ((key, value) in hashMap) {
            if (key > k) {
                continue
            }
            if ((k - key) == key) {
                hashMap.put(key, 0)
                result += value / 2
                continue
            }
            val pair = hashMap.get(k - key) ?: continue
            val minValue = minOf(pair, value)
            result += minValue
            hashMap.put(key, value - minValue)
            hashMap.put(k - key, pair - minValue)
        }
        return result
    }
}