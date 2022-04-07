// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    long long total_sum = 0;
    long long sum = 0;
    for (int i = 0; i < A.size(); i++) {
        total_sum += i + 1;
        sum += A[i];
    }
    return total_sum - sum + A.size() + 1;
}