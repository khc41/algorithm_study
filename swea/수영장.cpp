#include <iostream>
#include <vector>

using namespace std;

int answer;

void solve(int idx, int sum, vector<int> fee, vector<int> month) {
	if (idx >= 12) {
		answer = min(sum, answer);
		return;
	}
	if (sum > answer) return;
	if (month[idx] == 0) solve(idx + 1, sum, fee, month);
	else {
		solve(idx + 1, sum + fee[0] * month[idx], fee, month);
		solve(idx + 1, sum + fee[1], fee, month);
		solve(idx + 3, sum + fee[2], fee, month);
		solve(idx + 12, sum + fee[3], fee, month);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		answer = 987654321;
		vector<int> fee(4);
		vector<int> month(12);
		for (int i = 0; i < 4; i++) cin >> fee[i];
		for (int i = 0; i < 12; i++) cin >> month[i];
		solve(0, 0, fee, month);
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}