#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> r[20001];
int d[20001];

void dijkstra(int n) {
    d[n] = 0;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < r[cur].size(); i++) {
            int next = r[cur][i];
            if (d[next] > d[cur] + 1) {
                d[next] = d[cur] + 1;
                q.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    for (int i = 0; i < edge.size(); i++) {
        r[edge[i][0]].push_back(edge[i][1]);
        r[edge[i][1]].push_back(edge[i][0]);
    }

    for (int i = 1; i <= n; i++) {
        d[i] = 987654321;
    }

    dijkstra(1);

    int max_value = 0;
    for (int i = 1; i <= n; i++) {
        max_value = max(d[i], max_value);
    }

    for (int i = 1; i <= n; i++) {
        if (max_value == d[i]) answer++;
    }

    return answer;
}