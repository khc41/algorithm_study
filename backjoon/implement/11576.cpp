#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main() {
	int a, b, m, i, in, num = 0, cnt = 0;
	cin >> a >> b;
	cin >> m;
	stack<int> s;
	for (i = 0; i < m; i++) {
		cin >> in;
		s.push(in);
	}
	while(!s.empty()) {
		num += s.top() * pow(a, cnt++);
		s.pop();
	}
	while (num > 0) {
		s.push(num % b);
		num /= b;
	}
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}