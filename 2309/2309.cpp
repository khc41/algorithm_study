#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void pick(vector<int>& list, vector<int>& picked, vector<int>& compPick, int toPick) {
	if (toPick == 0) {
		int sum = 0;
		for (int i = 0; i < picked.size(); i++)
			sum += picked[i];
		if (sum == 100) {
			sort(picked.begin(), picked.end());
			for (int i = 0; i < picked.size(); i++)
				cout << picked[i] << endl;
			exit(0);
		}
	}

	int smallest = compPick.empty() ? 0 : compPick.back() + 1;
	for (int next = smallest; next < list.size(); next++) {
		picked.push_back(list[next]);
		compPick.push_back(next);
		pick(list, picked, compPick,toPick - 1);
		picked.pop_back();
		compPick.pop_back();
	}
}

int main() {
	int i, tall;
	vector<int> list;
	vector<int> compPick;
	for (i = 0; i < 9; i++) {
		cin >> tall;
		list.push_back(tall);
	}
	vector<int> picked;
	pick(list, picked, compPick,7);
}

