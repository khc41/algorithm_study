#include <string>
#include <vector>
#include <iostream>
using namespace std;

int max_value = 0;
vector<int> ans(11);

void copy(vector<int>& a, vector<int>& b) {
    for (int i = 0; i < a.size(); i++) b[i] = a[i];
}

void solve(int n, int index, int sum, vector<int> pick, vector<int> info) {
    if (index >= 11) {
        int ryan = 0; int apeach = 0;
        for (int i = 0; i < 11; i++) {
            if (pick[i] == 0 && info[i] == 0) continue;
            else if (pick[i] <= info[i]) apeach += 10 - i;
            else if (pick[i] > info[i]) ryan += 10 - i;
        }

        if (ryan - apeach > max_value) {
            max_value = ryan - apeach;
            copy(pick, ans);
            if (sum < n) ans[10] = n - sum;
        }
        else if (ryan - apeach == max_value && max_value != 0) {
            for (int i = 10; i >= 0; i--) {
                if (pick[i] > ans[i]) {
                    copy(pick, ans);
                    if (sum < n) ans[10] = n - sum;
                }
                else if (pick[i] < ans[i]) break;
            }
        }

        return;
    }
    vector<int> v(pick.size());
    copy(pick, v);
    pick.push_back(0);
    solve(n, index + 1, sum, pick, info);
    if (info[index] + sum + 1 <= n) {
        v.push_back(info[index] + 1);
        solve(n, index + 1, sum + info[index] + 1, v, info);
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> v;
    vector<int> answer;
    solve(n, 0, 0, v, info);
    int sum = 0;
    for (int i = 0; i <= 10; i++) {
        sum += ans[i];
    }
    if (sum == 0) answer.push_back(-1);
    else answer = ans;
    return answer;
}