#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int map[11][11];
int check[11][11];
int answer;
int n, m, c;

int get_honey(int x, int y, bool is_first) {
	vector<int> num;
	bool visited[10];
	memset(visited, false, sizeof(visited));
	int earn = 0;
	int sum = 0;
	int ret = 0;
	for (int i = x; i < x + m; i++) {
		check[y][i] = true;
		num.push_back(map[y][i]);
	}
	sort(num.rbegin(), num.rend());
	for (int i = 0; i < num.size(); i++) {
		earn = 0;
		sum = 0;
		if(!visited[i]){
			earn += (num[i] * num[i]);
			sum += num[i];
			visited[i] = true;
		}
		for (int j = 0; j < num.size(); j++) {
			if (!visited[j] && c >= sum + num[j]) {
				visited[j] = true;
				earn += (num[j] * num[j]);
				sum += num[j];
			}
		}
		ret = max(ret, earn);
	}
	if (!is_first) {
		for (int i = x; i < x + m; i++)
			check[y][i] = false;
	}
	return ret;
}

void solve(int x, int y) {
	int first = get_honey(x, y, true);
	for (int i = y; i < n; i++) {
		for (int j = 0; j <= n - m; j++) {
			bool visit = false;
			for (int k = j; k < j + m; k++)
				visit = visit || check[i][k];
			if(!visit){
				
				answer = max(answer, first + get_honey(j, i, false));
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		answer = 0;
		cin >> n >> m >> c;
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> map[i][j];

		for (int i = 0; i < n; i++)
			for (int j = 0; j <= n - m; j++){
				memset(check, false, sizeof(check));
				solve(j, i);
			}
		
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}