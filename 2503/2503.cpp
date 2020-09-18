#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
	int i, j, k, t, test_case,answer;
	answer = 0;
	cin >> test_case;
	vector<vector<int>> ball;
	vector<vector<int>> strike;
	bool check[1000];
	for (i = 1; i <= 9; i++) {
		for (j = 0; j <= 9; j++) {
			for (k = 0; k <= 9; k++) {
				if (i == j || j == k || k == i || j == 0 || k == 0)
					check[i * 100 + j * 10 + k] = false;
				else
					check[i * 100 + j * 10 + k] = true;
			}
		}
	}
	for (t = 0; t < test_case; t++) {
		string num, str;
		int b, s,tmpS, tmpB;
		cin >> num >> s >> b;
		
		for (k = 100; k < 999; k++) {
			if (check[k] == false)
				continue;
			tmpS = 0; tmpB = 0;
			str = to_string(k);
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) {
					if (num[i] == str[j] && i == j)
						tmpS++;
					if (num[i] == str[j] && i != j)
						tmpB++;
				}
			}
			if (s != tmpS || b != tmpB)
				check[k] = false;
		}
	}
	for (i = 100; i < 999; i++) {
		if (check[i] == true) {
			answer++;
		}
			
	}
	cout << answer;
}