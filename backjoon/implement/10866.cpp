#include <iostream>
#include <deque>
using namespace std;

int main() {
	int n, i, num;
	string cmd;
	deque<int> q;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "push_front") {
			cin >> num;
			q.push_front(num);
		}
		else if (cmd == "push_back") {
			cin >> num;
			q.push_back(num);
		}
		else if (cmd == "pop_front") {
			if (q.size() == 0)
				printf("-1\n");
			else {
				printf("%d\n", q.front());
				q.pop_front();
			}
		}
		else if (cmd == "pop_back") {
			if (q.size() == 0)
				printf("-1\n");
			else {
				printf("%d\n", q.back());
				q.pop_back();
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