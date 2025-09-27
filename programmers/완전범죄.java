import java.util.*;

class Solution {
    private Map<String, Integer> memo = new HashMap<>();

    public int solution(int[][] info, int n, int m) {
        memo.clear();
        int result = select(info, n, m, 0);
        return result == Integer.MAX_VALUE ? -1 : result;
    }

    public int select(int[][] info, int n, int m, int depth) {
        if (depth == info.length) {
            return 0;
        }

        String key = n + "," + m + "," + depth;
        if (memo.containsKey(key)) {
            return memo.get(key);
        }

        int result = Integer.MAX_VALUE;

        if (info[depth][0] < n) {
            int choice1 = select(info, n - info[depth][0], m, depth + 1);
            if (choice1 != Integer.MAX_VALUE) {
                result = Math.min(result, choice1 + info[depth][0]);
            }
        }
        if (info[depth][1] < m) {
            int choice2 = select(info, n, m - info[depth][1], depth + 1);
            if (choice2 != Integer.MAX_VALUE) {
                result = Math.min(result, choice2);
            }
        }

        memo.put(key, result);
        return result;
    }
}