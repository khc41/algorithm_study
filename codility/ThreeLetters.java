// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public String solution(int A, int B) {
        StringBuilder sb = new StringBuilder();
        boolean isA = A >= B;
        while (A >= 1 && B >= 1) {
            if (isA) {
                if (A - B > 1) {
                    sb.append("aa");
                    A -= 2;
                } else {
                    sb.append("a");
                    A--;
                }
            } else {
                if (B - A > 1) {
                    sb.append("bb");
                    B -= 2;
                } else {
                    sb.append("b");
                    B--;
                }
            }
            isA = !isA;
        }
        if (isA) {
            sb.append("a".repeat(A));
            sb.append("b".repeat(B));
        } else {
            sb.append("b".repeat(B));
            sb.append("a".repeat(A));
        }
        return sb.toString();
    }
}