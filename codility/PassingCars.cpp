// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = 0;
    int dp[A.size()];
    dp[A.size() - 1] = A[A.size() - 1];
    for (int i = A.size() - 2; i >= 0; i--) {
        if (A[i] == 1) dp[i] = dp[i + 1] + 1;
        else dp[i] = dp[i + 1];
    }
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == 0) answer += dp[i];
        if (answer > 1000000000) {
            answer = -1;
            break;
        }
    }
    return answer;
}