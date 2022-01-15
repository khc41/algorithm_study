#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class student {
public:
	string name;
	int k;
	int e;
	int m;
	student(string name, int k, int e, int m) {
		this->name = name;
		this->k = k;
		this->e = e;
		this->m = m;
	}
};

bool compare(student& a, student& b) {
	if (a.k > b.k) return true;
	else if (a.k == b.k) {
		if (a.e < b.e) return true;
		else if (a.e == b.e) {
			if (a.m > b.m) return true;
			else if (a.m == b.m) {
				if (a.name < b.name) return true;
				else return false;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

int main() {
	int n, i, k, e, m;
	string name;
	cin >> n;
	vector<student> s;
	for (i = 0; i < n; i++) {
		cin >> name >> k >> e >> m;
		s.push_back(student(name, k, e, m));
	}
	sort(s.begin(), s.end(), compare);
	for (i = 0; i < n; i++) {
		printf("%s\n", s[i].name.c_str());
	}
}