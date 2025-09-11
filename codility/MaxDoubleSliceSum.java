// you can also use imports, for example:
import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] A) {
        int n = A.length;

        int[] maxEndingHere = new int[n];
        int[] maxStartingHere = new int[n];

        int maxSum = 0;

        for(int i = 1; i < n - 1; i ++){
            maxEndingHere[i] = Math.max(0, maxEndingHere[i - 1] + A[i]);
        }

        for(int i = n - 2; i > 0; i--){
            maxStartingHere[i] = Math.max(0, maxStartingHere[i + 1] + A[i]);
        }

        for(int i = 1; i < n - 1; i++){
            maxSum = Math.max(maxSum, maxEndingHere[i - 1] + maxStartingHere[i + 1]);
        }

        return maxSum;
    }
}