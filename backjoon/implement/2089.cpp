#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;

	stack<int> s;
	if (n == 0)
		s.push(0);
	else {
		while (n != 0) {
			if (n % -2 == -1) {
				n /= -2;
				n++;
				s.push(1);
			}
			else {
				s.push(n % -2);
				n /= -2;
			}
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}