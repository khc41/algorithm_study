import java.util.*;

class Solution {
    public int solution(int n, int[][] q, int[] ans) {
        int answer = 0;
        Set<List<Integer>> result = new HashSet<>();
        combination(n, q, ans, 1, new ArrayList<>(), result);
        return result.size();
    }

    public void combination(int n, int[][] q, int[] ans, int start, List<Integer> cur, Set<List<Integer>> result) {
        int m = ans.length;
        if (cur.size() == 5) {
            Set<Integer> comb = new HashSet<>(cur);
            int total = 0;
            for (int i = 0; i < q.length; i++) {
                int duplicate = 0;
                for (int quizNum : q[i]) {
                    if (comb.contains(quizNum)) {
                        duplicate++;
                    }
                }
                if (duplicate == ans[i]) {
                    total++;
                }
            }
            if (total == m) {
                result.add(new ArrayList<>(cur));
            }
            return;
        }

        for (int i = start; i <= n; i++) {
            cur.add(i);
            combination(n, q, ans, i + 1, cur, result);
            cur.remove(cur.size() - 1);
        }
    }
}