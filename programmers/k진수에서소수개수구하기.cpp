#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> ret;
long long answer = 0;

bool check_prime(long long n) {
    if (n == 0 || n == 1) return false;
    long long i = 2;
    while (i * i <= n) {
        if (n % i == 0)
            return false;
        i++;
    }
    return true;
}

void solve(int index, long long sum) {
    if (index == ret.size() || ret[index] == 0) {
        if (check_prime(sum)) answer++;
        sum = 0;
    }
    else {
        sum *= 10;
        sum += ret[index];
    }
    if (index == ret.size()) return;
    solve(index + 1, sum);
}

void calculate(long long n, long long k) {
    while (n >= 1) {
        ret.push_back(n % k);
        n /= k;
    }
    reverse(ret.begin(), ret.end());
    for (int i = 0; i < ret.size(); i++)
        cout << ret[i];
    cout << endl;
}


int main() {
    calculate(524287, 2);
    solve(0, 0);
}