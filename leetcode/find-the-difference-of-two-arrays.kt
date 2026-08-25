class Solution {
    fun findDifference(nums1: IntArray, nums2: IntArray): List<List<Int>> {
        val set1 = nums1.toSet()
        val set2 = nums2.toSet()

        val diff1 = (set1 - set2).toList()
        val diff2 = (set2 - set1).toList()

        return listOf(diff1, diff2)
    }
}