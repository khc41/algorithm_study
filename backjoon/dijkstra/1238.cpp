#include <iostream>
#include <queue>
using namespace std;

int n, m, x;
vector<pair<int, int>> road[1001];
int min_d[1001];
int min_x[1001];
int result[1001];

void dijkstra(int *min_dis, int start) {
	min_dis[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ start, 0 });
	while (!pq.empty()) {
		int distance = -pq.top().second;
		int cur = pq.top().first;
		pq.pop();
		if (min_dis[cur] < distance) continue;
		for (int i = 0; i < road[cur].size(); i++) {
			int next = road[cur][i].first;
			int dis = road[cur][i].second;
			if (min_dis[next] > min_dis[cur] + dis) {
				min_dis[next] = min_dis[cur] + dis;
				pq.push({ next, -min_dis[next] });
			}
		}
	}
}

int main() {
	cin >> n >> m >> x;
	
	for (int i = 0; i < m; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		road[s].push_back({ e, t });
	}
	for(int i = 1; i <= n; i++){
		if (i == x){
			for (int i = 1; i <= n; i++) min_d[i] = 987654321;
			dijkstra(min_d, i);
		}
		else {
			for (int i = 1; i <= n; i++) min_x[i] = 987654321;
			dijkstra(min_x, i);
			result[i] = min_x[x];
		}
	}
	int max_time = 0;
	for (int i = 1; i <= n; i++) {
		max_time = max(max_time, min_d[i] + result[i]);
	}
	cout << max_time;
}