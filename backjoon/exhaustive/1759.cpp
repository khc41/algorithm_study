#include <iostream>	
#include <vector>
#include <algorithm>

using namespace std;

int l, c;

vector<char> v;
vector<string> ret;
bool *visited;

bool check(string s) {
	int cnt[2];
	cnt[0] = 0; cnt[1] = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			cnt[0]++;
		else
			cnt[1]++;
	}
	if (cnt[0] >= 1 && cnt[1] >= 2) return true;
	else return false;
}

void dfs(int n, string s) {
	s += v[n];
	if (s.size() == l){
		if(check(s))
			ret.push_back(s);
		return;
	}
	visited[n] = true;
	for (int i = n + 1; i < c; i++) {
		if (!visited[i])
			dfs(i, s);
	}
	visited[n] = false;
}

int main() {
	cin >> l >> c;
	visited = new bool[c];
	for (int i = 0; i < c; i++) {
		char in;
		cin >> in;
		v.push_back(in);
		visited[i] = false;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < c - l + 1; i++) {
		dfs(i, "");
	}
	sort(ret.begin(), ret.end());
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << "\n";
}