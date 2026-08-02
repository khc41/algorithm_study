class Solution {
    fun isSubsequence(s: String, t: String): Boolean {
        var map = hashMapOf<Char, ArrayList<Int>>()
        for (i in t.indices) {
            map.getOrPut(t[i]) { arrayListOf() }.add(i)
        }
        var last = -1
        for (i in s) {
            val list = map[i] ?: return false
            val idx = upperBound(list, last)

            if (idx >= list.size) return false
            last = list[idx]
        }
        return true
    }

    fun upperBound(list: ArrayList<Int>, target: Int): Int {
        var left = 0
        var right = list.size

        while (left < right) {
            val mid = left + (right - left) / 2

            if (list[mid] <= target) {
                left = mid + 1
            } else {
                right = mid
            }
        }

        return left
    }
}