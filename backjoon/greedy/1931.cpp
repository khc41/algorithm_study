#include <iostream>
#include <vector>
#include <algorithm>
#define p pair<long long, long long>

using namespace std;

bool compare(p a, p b) {
	if (a.first < b.first) return true;
	else if (a.first == b.first) {
		if (a.second - a.first < b.second - b.first) return true;
		else return false;
	}
	else return false;
}

int main(){
	long long n, a, b;
	cin >> n;
	vector<p> v;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end(), compare);
	long long end = v[0].second;
	long long time = v[0].second - v[0].first;
	long long result = 1;
	for (int i = 1; i < v.size(); i++) {
		if (end <= v[i].first) {
			result++;
			end = v[i].second;
			time = v[i].second - v[i].first;
		}
		else{
			if (time > v[i].second - v[i].first && end > v[i].second) {
				time = v[i].second - v[i].first;
				end = v[i].second;
			}
		}
	}
	cout << result << endl;
}