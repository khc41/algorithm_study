class Solution {
    fun kidsWithCandies(candies: IntArray, extraCandies: Int): List<Boolean> {
        val maxCandy = candies.max()
        return candies.map { it + extraCandies >= maxCandy}
    }
}