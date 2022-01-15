#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, i, num;
	string cmd;
	queue<int> q;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> num;
			q.push(num);
		}
		else if (cmd == "pop") {
			if (q.size() == 0)
				printf("-1\n");
			else {
				printf("%d\n", q.front());
				q.pop();
			}
		}
		else if (cmd == "size") {
			printf("%d\n", q.size());
		}
		else if (cmd == "empty") {
			if (q.size() == 0)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (cmd == "front") {
			if (q.size() == 0)
				printf("-1\n");
			else
				printf("%d\n", q.front());
		}
		else if (cmd == "back") {
			if (q.size() == 0)
				printf("-1\n");
			else
				printf("%d\n", q.back());
		}
	}
}