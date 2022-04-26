#include <iostream>
#include <map>
using namespace std;

int n;
int dessert[21][21];
bool visited[101];
int dir[4][2] = { {-1, 1}, {1, 1}, {1, -1}, {-1, -1} };
int answer = -1;

void move(int x, int y, int direction, int left, int down, int depth) {
	if (direction == 4) {
		answer = max(answer, depth);
		return;
	}

	int nx = x + dir[direction][0];
	int ny = y + dir[direction][1];

	if (direction == 0) {
		if(!visited[dessert[ny][nx]] && nx >= 0 && ny < n){
			visited[dessert[ny][nx]] = true;
			move(nx, ny, direction, left + 1, down, depth + 1);
			visited[dessert[ny][nx]] = false;
		}
		if (left != 0)
			move(x, y, direction + 1, left, down, depth);
	}
	else if (direction == 1){
		if (!visited[dessert[ny][nx]] && nx < n && ny < n) {
			visited[dessert[ny][nx]] = true;
			move(nx, ny, direction, left, down + 1, depth + 1);
			visited[dessert[ny][nx]] = false;
		}
		if (down != 0)
			move(x, y, direction + 1, left, down, depth);
	}
	else if (direction == 2) {
		if(left == 0)
			move(x, y, direction + 1, left, down, depth);
		else{
			if (visited[dessert[ny][nx]] || nx >= n || ny >= n || left < 0) return;
			visited[dessert[ny][nx]] = true;
			move(nx, ny, direction, left - 1, down, depth + 1);
			visited[dessert[ny][nx]] = false;
		}
	}
	else {
		if (down == 0)
			move(x, y, direction + 1, left, down, depth);
		else {
			if (visited[dessert[ny][nx]] || nx < 0 || ny < 0 || down < 0) return;
			visited[dessert[ny][nx]] = true;
			move(nx, ny, direction, left, down - 1, depth + 1);
			visited[dessert[ny][nx]] = false;
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
		cin >> n;
		answer = -1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> dessert[i][j];
		for(int i = 0; i < n - 2; i++)
			for (int j = 1; j < n - 1; j++) {
				cout << i << " " << j << endl;
				move(j, i, 0, 0, 0, 0);
				cout << endl;
			}
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}