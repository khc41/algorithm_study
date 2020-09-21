#include <iostream>
#include <vector>

using namespace std;

void pick(vector<int>& num, vector<int>& picked, int s, int toPick, int& res, int idx) {
	int i, sum;
	if (toPick == 0) {
		sum = 0;
		for (i = 0; i < picked.size(); i++)
			sum += picked[i];
		if (sum == s) {
			for (i = 0; i < picked.size(); i++)
				cout << picked[i] << " ";
			cout << endl;
			res++;
		}
		return;
	}

	for (i = idx; i < num.size(); i++) {
		picked.push_back(num[i]);
		pick(num, picked, s, toPick - 1, res, i + 1);
		picked.pop_back();
	}
}

int main() {
	int i, n, s;
	int res = 0;
	vector<int> picked;
	cin >> n >> s;
	vector<int> num(n,0);
	for (i = 0; i < n; i++)
		cin >> num[i];
	
	for (i = 1; i <= n; i++) {
		pick(num, picked, s, i, res, 0);
	}
	cout << res;
}