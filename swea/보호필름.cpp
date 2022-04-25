#include<iostream>

using namespace std;

int d, w, k;
int film[14][21];
int cp[14][21];
int answer;
bool visited[14];

bool solved = false;

bool check() {
	for (int i = 0; i < w; i++) {
		int zero = 0;
		int one = 0;
		bool flag = false;
		for (int j = 0; j < d; j++) {
			if (film[j][i] == 0) {
				one = 0;
				zero++;
			}
			else {
				zero = 0;
				one++;
			}
			if (zero == k || one == k) {
				flag = true;
				break;
			}
		}
		if (!flag) return false;
	}
	return true;
}

void solve(int depth, int idx) {
	if (depth > k || answer <= depth) return;
	if (check()) {
		answer = min(answer, depth);
		return;
	}

	for (int i = idx; i < d; i++) {
		if(!visited[i]){
			for(int j = 0; j < 2; j++){
				visited[i] = true;
				for (int k = 0; k < w; k++) film[i][k] = j;
				solve(depth + 1, i);
				for (int k = 0; k < w; k++) film[i][k] = cp[i][k];
				visited[i] = false;
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
		cin >> d >> w >> k;
		for (int i = 0; i < d; i++)
			for (int j = 0; j < w; j++){
				cin >> film[i][j];
				cp[i][j] = film[i][j];
			}
		answer = 987654321;
		for (int i = 0; i < d; i++) visited[i] = false;
		if (check()) cout << "#" << test_case << " " << 0 << "\n";
		else {
			solve(0, 0);
			cout << "#" << test_case << " " << answer << "\n";
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}