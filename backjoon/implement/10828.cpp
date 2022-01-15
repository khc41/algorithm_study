#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, i, in;
	string cmd;
	vector<int> v;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> in;
			v.push_back(in);
		}
		else if (cmd == "pop") {
			if (v.size() == 0)
				printf("-1\n");
			else{
				printf("%d\n", v[v.size() - 1]);
				v.pop_back();
			}
		}
		else if (cmd == "size") {
			printf("%d\n", v.size());
		}
		else if (cmd == "empty") {
			if (v.empty()) 
				printf("1\n");
			else
				printf("0\n");
		}
		else if (cmd == "top") {
			if (v.size() == 0)
				printf("-1\n");
			else 
				printf("%d\n", v[v.size() - 1]);
		}
	}
}