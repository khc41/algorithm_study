#include <iostream>
#include <vector>

using namespace std;

int main() {
	int i, j, k, plus, n, in, test_case, answer;
	vector<int> tri;
	vector<int> input;
	plus = 1; 
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> in;
		input.push_back(in);
	}
	for (i = 1; i <= 1000; i = i + plus) {
		tri.push_back(i);
		plus++;
	}
	for (test_case = 0; test_case < n; test_case++) {
		answer = 0;
		for (i = 0; i < tri.size() && tri[i] < input[test_case]; i++) {
			for (j = 0; j < tri.size() && tri[j] < input[test_case]; j++) {
				for (k = 0; k < tri.size() && tri[k] < input[test_case]; k++) {
					if (input[test_case] == tri[i] + tri[j] + tri[k]) {
						answer = 1;
						break;
					}
				}
			}
		}
		cout << answer << endl;
	}
	
}