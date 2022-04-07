// you can use includes, for example:
// #include <algorithm>
#include <algorithm>

using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = 0;
    sort(A.begin(), A.end());

    for (int i = 0; i < A.size(); i += 2) {
        if (i == A.size() - 1) {
            answer = A[i];
            break;
        }
        if (A[i] != A[i + 1]) {
            answer = A[i];
            break;
        }
    }
    return answer;
}