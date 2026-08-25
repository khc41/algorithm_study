class Solution {
    fun findDifference(nums1: IntArray, nums2: IntArray): List<List<Int>> {
        var result = ArrayList<ArrayList<Int>>()
        var distinct1 = nums1.toSet()
        var distinct2 = nums2.toSet()
        getResult(distinct1, distinct2, result)
        getResult(distinct2, distinct1, result)

        return result
    }

    fun getResult(nums1: Set<Int>, nums2: Set<Int>, result: ArrayList<ArrayList<Int>>) {
        var result1 = ArrayList<Int>()
        for (i in nums1) {
            if (!nums2.contains(i)) {
                result1.add(i)
            }
        }
        result.add(result1)
    }
}