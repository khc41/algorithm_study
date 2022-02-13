#include <iostream>	

using namespace std;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	if (n == 1) cout << "1";
	else if (n == 2) cout << min(4, (m + 1) / 2);
	else {
		if (m <= 6) cout << min(4, m);
		else cout << m - 2;
	}
}