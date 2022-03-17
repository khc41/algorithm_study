#include <string>
#include <vector>
#include <iostream> 

using namespace std;

bool win[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for (int i = 0; i < results.size(); i++) {
        win[results[i][0]][results[i][1]] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (win[j][i] && win[i][k])
                    win[j][k] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (win[i][j] || win[j][i]) cnt++;
        }
        if (cnt == n - 1) answer++;
    }
    return answer;
}