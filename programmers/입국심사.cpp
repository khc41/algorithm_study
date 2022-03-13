#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool check(long long mid, vector<int> times, int n) {
    long long sum = 0;
    for (int i = 0; i < times.size(); i++) {
        sum += mid / times[i];
    }
    if (n >= sum) return true;
    else return false;
}

long long solution(int n, vector<int> times) {
    long long answer = 1e18;
    sort(times.begin(), times.end());
    long long high = times[times.size() - 1] * n;
    long long low = times[0];;
    while (low <= high) {
        long long mid = (high + low) / 2;
        if (check(mid, times, n)) {
            if (answer <= mid) answer = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    answer = low;
    return answer;
}