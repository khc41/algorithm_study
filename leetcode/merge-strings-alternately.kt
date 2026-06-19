class Solution {
    fun mergeAlternately(word1: String, word2: String): String {
        val size1 = word1.length
        val size2 = word2.length

        if(size1 > size2) {
            return merge(word1, word2, word1.substring(size2), size2)
        } else{
            return merge(word1, word2, word2.substring(size1), size1)
        }
    }

    fun merge(word1: String, word2: String, lastString: String, size: Int) : String {
        val sb = StringBuilder()
        for(i in 0 until size) {
            sb.append(word1[i])
            sb.append(word2[i])
        }
        sb.append(lastString)
        return sb.toString()
    }
}