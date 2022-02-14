#include <iostream>	

using namespace std;

int map[1001][1001];
int r, c;
string result;

int main() {
	int i, j;
	cin >> r >> c;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			cin >> map[i][j];
	if (r % 2) {
		for (int y = 0; y < r; y++) {
			for(int x = 0; x < c - 1; x++){
				if (y % 2 == 0)
					result += 'R';
				else
					result += 'L';
			}
			if (y != r - 1)
				result += 'D';
		}
	}
	else if (c % 2) {
		for (int x = 0; x < c; x++) {
			for (int y = 0; y < r - 1; y++) {
				if (x % 2 == 0)
					result += 'D';
				else
					result += 'U';
			}
			if (x != c - 1)
				result += 'R';
		}
	}
	else {
		pair<int, int> min_p;
		int min_v = 1001;
		for(i = 0; i < r; i++)
			for (j = 0; j < c; j++) {
				if ((i + j) % 2 && map[i][j] < min_v) {
					min_v = map[i][j];
					min_p = { i, j };
				}
			}
		int new_r = min_p.first % 2 ? min_p.first - 1 : min_p.first;
		for (int y = 0; y < new_r; y++) {
			for (int x = 0; x < c - 1; x++) {
				if (y % 2 == 0)
					result += 'R';
				else
					result += 'L';
			}
			result += 'D';
		}
		int new_c = min_p.second;
		for (int x = 0; x < new_c; x++) {
			if (x % 2 == 0)
				result += "DR";
			else
				result += "UR";
		}
		for (int x = new_c; x < c - 1; x++) {
			if (x % 2 == 0)
				result += "RD";
			else
				result += "RU";
		}
		int start_c = min_p.first % 2 ? min_p.first : min_p.first + 1;
		for (int y = start_c; y < r - 1; y++) {
			result += 'D';
			for (int x = 0; x < c - 1; x++) {
				if (y % 2 == 0)
					result += 'R';
				else
					result += 'L';
			}
		}
	}
	cout << result;
}