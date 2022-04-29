#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
struct belt {
public:
	int value;
	bool robot;
	belt(int a, bool b) {
		this->value = a;
		this->robot = b;
	}
	void minus() {
		if (this->value > 0) this->value--;
	}
};

deque<belt> front;
deque<belt> back;

bool check() {
	int cnt = 0;
	for (int i = 0; i < n; i++) if (front[i].value == 0) cnt++;
	for (int i = 0; i < n; i++) if (back[i].value == 0) cnt++;
	return cnt < k;
}

int main() {
	int in;
	int stage = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> in;
		front.push_back(belt(in, false));
	}
	for (int i = 0; i < n; i++) {
		cin >> in;
		back.push_back(belt(in, false));
	}
	//reverse(back.begin(), back.end());

	while (check()) {
		stage++;
		back.push_front(front.back());
		front.pop_back();
		front.push_front(back.back());
		back.pop_back();
		front.back().robot = false;
	
		for (int i = n - 1; i > 0; i--) {
			if (!front[i].robot && front[i].value > 0 && front[i-1].robot) {
				front[i - 1].robot = false;
				front[i].robot = true;
				front[i].minus();
			}
		}
		front.back().robot = false;
		if(front.front().value > 0 && !front.front().robot){
			front.front().robot = true;
			front.front().minus();
		}
	}
	cout << stage << endl;
}