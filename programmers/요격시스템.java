import java.util.*;

class Solution {
    public int solution(int[][] targets) {
        int answer = 0;
        Arrays.sort(targets, (a, b) -> a[1] - b[1]);
        double shot = -1;
        for (int[] target : targets) {
            if (target[0] <= shot && shot <= target[1]) {
                continue;
            }
            shot = target[1] - 0.5;
            answer++;
        }
        return answer;
    }
}