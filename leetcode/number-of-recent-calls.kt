class RecentCounter() {

    var queue = ArrayDeque<Int>()

    fun ping(t: Int): Int {
        while (queue.isNotEmpty()) {
            if (queue.first() < t - 3000) {
                queue.removeFirst()
            } else {
                break
            }
        }
        queue.addLast(t)
        return queue.size
    }

}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * var obj = RecentCounter()
 * var param_1 = obj.ping(t)
 */