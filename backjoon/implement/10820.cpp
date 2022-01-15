#include <iostream>
#include <string>
using namespace std;

int main() {
	int i, j, k;
	string s;
	while(getline(cin, s)) {
		int ans[4] = { 0, };
		for (j = 0; j < s.size(); j++) {
			if ('a' <= s[j] && s[j] <= 'z')
				ans[0] ++;
			else if ('A' <= s[j] && s[j] <= 'Z')
				ans[1] ++;
			else if ('0' <= s[j] && s[j] <= '9')
				ans[2] ++;
			else if (' ' == s[j])
				ans[3]++;
		}
		for (i = 0; i < 4; i++) {
			printf("%d ", ans[i]);
		}
		cout << "\n";
	}
	
}