class Solution {
    fun equalPairs(grid: Array<IntArray>): Int {

        val map = HashMap<List<Int>, Int>()
        var result = 0

        for (row in grid) {
            val list = row.asList()
            map[list] = map.getOrPut(list) { 0 } + 1
        }

        for (i in grid.indices) {
            val col = grid.map { it[i] }
            result += map[col] ?: 0
        }

        return result
    }
}