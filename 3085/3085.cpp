#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> changeBot(vector<vector<char>> v, int i, int j, int n) {
	if (i != n - 1) {
		char temp;
		temp = v[i + 1][j];
		v[i + 1][j] = v[i][j];
		v[i][j] = temp;
	}
	return v;
}

vector<vector<char>> changeRig(vector<vector<char>> v, int i, int j, int n) {
	if (j != n - 1) {
		char temp;
		temp = v[i][j + 1];
		v[i][j + 1] = v[i][j];
		v[i][j] = temp;
	}
	return v;
}

int inspect(vector<vector<char>> v, int n) {
	int i, j, max, lowCnt, colCnt;
	max = -1;
	for (i = 0; i < n; i++) {
		lowCnt = 1; colCnt = 1;
		for (j = 0; j < n; j++) {
			if(j > 0){
				if (v[i][j - 1] == v[i][j]) {
					lowCnt++;
				}
				if (v[i][j - 1] != v[i][j] || j == n-1){
					if (lowCnt > max)
						max = lowCnt;
					lowCnt = 1;
				}
				if (v[j-1][i] == v[j][i]) {
					colCnt++;
				}
				if (v[j - 1][i] != v[j][i] || j == n-1){
					if (colCnt > max) {
						max = colCnt;
					}
					colCnt = 1;
				}
			}
		}
	}
	return max;
}

int main() {
	int n, i, j, res1, res2, max;
	char in;
	cin >> n;
	max = -1;
	vector<vector<char>> v(n, vector<char>(n, ' '));
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> in;
			v[i][j] = in;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			res1 = inspect(changeBot(v, i, j, n), n);
			res2 = inspect(changeRig(v, i, j, n), n);
			if (max < ((res1 > res2) ? res1 : res2))
				max = res1 > res2 ? res1 : res2;
		}
	}
	cout << max << endl;
}