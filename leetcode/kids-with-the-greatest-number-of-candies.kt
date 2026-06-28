class Solution {
    fun kidsWithCandies(candies: IntArray, extraCandies: Int): List<Boolean> {
        val maxCandy = candies.max()
        val result = mutableListOf<Boolean>()
        for (i in candies.indices) {
            result.add(candies[i] + extraCandies >= maxCandy)
        }
        return result
    }
}