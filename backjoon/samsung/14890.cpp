#include <iostream>

using namespace std;

int n, l;
int map[101][101];
int cp[101][101][2];

int main() {
	int answer = 0;
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++) {
		int x = 1;
		int y = 1;
		for (int j = 1; j < n; j++) {
			if (map[i][j] == map[i][j - 1]) 
				x++;
			else {
				if (x >= l) {
					for (int k = j - x; k <= j - 1; k++) {
						cp[i][k][0] = 1;
					}
				}
				x = 1;
			}

			if (map[j][i] == map[j - 1][i]) 
				y++;
			else {
				if (y >= l) {
					for (int k = j - y; k <= j - 1; k++) {
						cp[k][i][1] = 1;
					}
				}
				y = 1;
			}

			if (j == n - 1) {
				if (x >= l) {
					for (int k = j - x + 1; k <= j; k++) {
						cp[i][k][0] = 1;
					}
				}
				if (y >= l) {
					for (int k = j - y + 1; k <= j; k++) {
						cp[k][i][1] = 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int x = 0;
		int y = 0;
		bool width = false;
		bool height = false;
		for (int j = 1; j < n; j++) {
			if (map[i][j] != map[i][j - 1] && !width) {
				width = true;
				int cnt = 0;
				if (map[i][j] - map[i][j - 1] == 1) {
					// left
					if (j - l >= 0) {
						for (int k = j - l; k < j; k++) {
							if (cp[i][k][0] == 1) cnt++;
						}
						if (cnt == l) {
							for (int k = j - l; k < j; k++) {
								cp[i][k][0] = 0;
							}
							width = false;
						}
					}
				}
				else if (map[i][j] - map[i][j - 1] == -1) {
					// right
					cnt = 0;
					if (j + l <= n) {
						for (int k = j; k < j + l; k++) {
							if (cp[i][k][0] == 1) cnt++;
						}
						if (cnt == l) {
							for (int k = j; k < j + l; k++) {
								cp[i][k][0] = 0;
							}
							width = false;
						}
					}
				}
			}

			if (map[j][i] != map[j - 1][i] && !height) {
				height = true;
				int cnt = 0;
				if (map[j][i] - map[j - 1][i] == 1) {
					// top
					if (j - l >= 0) {
						for (int k = j - l; k < j; k++) {
							if (cp[k][i][1] == 1) cnt++;
						}
						if (cnt == l) {
							for (int k = j - l; k < j; k++) {
								cp[k][i][1] = 0;
							}
							height = false;
						}
					}
				}
				else if (map[j][i] - map[j -1][i] == -1) {
					// bottom
					cnt = 0;
					if (j + l <= n) {
						for (int k = j; k < j + l; k++) {
							if (cp[k][i][1] == 1) cnt++;
						}
						if (cnt == l) {
							for (int k = j; k < j + l; k++) {
								cp[k][i][1] = 0;
							}
							height = false;
						}
					}
				}
			}
		}
		if (!width) 
			answer++;
		
		if (!height) 
			answer++;
	}
	
	cout << answer << endl;
}