// you can also use imports, for example:

import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] A) {
        // Implement your solution here
        Set<Integer> nums = new HashSet<>();
        for (int i = 0; i < A.length; i++) {
            nums.add(A[i]);
        }
        for (int i = 1; i <= 1_000_000; i++) {
            if (!nums.contains(i)) {
                return i;
            }
        }
        return 1_000_001;
    }
}