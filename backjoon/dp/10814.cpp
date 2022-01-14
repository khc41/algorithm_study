#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class user {
public :
	int age;
	string name;
	int index;
	user(int age, string name, int index) {
		this->age = age;
		this->name = name;
		this->index = index;
	}
};

bool compare(user& a, user& b) {
	if (a.age < b.age) return true;
	else if (a.age == b.age) {
		if (a.index < b.index) return true;
		else return false;
	}
	else return false;
}

int main() {
	int n, i, age;
	string name;
	cin >> n;
	vector<user> u;
	for (i = 0; i < n; i++) {
		cin >> age >> name;
		u.push_back(user(age, name, i));
	}
	
	sort(u.begin(), u.end(), compare);
	for (i = 0; i < n; i++) {
		printf("%d %s\n", u[i].age, u[i].name.c_str());
	}
}

