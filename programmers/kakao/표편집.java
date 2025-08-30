import java.util.*;

class Solution {
    public String solution(int n, int k, String[] cmd) {
        int[] prev = new int[n];
        int[] next = new int[n];
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < n; i++) {
            prev[i] = i - 1;
            next[i] = i + 1;
        }
        prev[0] = -1;
        next[n - 1] = -1;
        int cur = k;
        for (String command : cmd) {
            String[] split = command.split(" ");
            if ("U".equals(split[0])) {
                int move = Integer.valueOf(split[1]);
                for (int i = 0; i < move; i++) {
                    cur = prev[cur];
                }
            } else if ("D".equals(split[0])) {
                int move = Integer.valueOf(split[1]);
                for (int i = 0; i < move; i++) {
                    cur = next[cur];
                }
            } else if ("C".equals(split[0])) {
                int pn = prev[cur];
                int nn = next[cur];

                if (pn != -1) next[pn] = nn;
                if (nn != -1) prev[nn] = pn;

                stack.add(cur);

                if (nn != -1) {
                    cur = nn;
                } else {
                    cur = pn;
                }

            } else if ("Z".equals(split[0])) {
                int restore = stack.pop();
                int pn = prev[restore];
                int nn = next[restore];
                if (nn != -1) prev[nn] = restore;
                if (pn != -1) next[pn] = restore;
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append("O");
        }
        while (!stack.isEmpty()) {
            sb.setCharAt(stack.pop(), 'X');
        }
        return sb.toString();
    }
}