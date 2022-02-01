#include <iostream>
#include <vector>
using namespace std;

int a[1000001];
int b[1000001];
int c[2000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, i, j;
	cin >> n >> m;
	for (i = 0; i < n; i++) cin >> a[i];
	for (i = 0; i < m; i++) cin >> b[i];
	int N = 0, M = 0, index = 0;
	while (N < n && M < m) {
		if (a[N] < b[M])
			c[index++] = a[N++];
		else
			c[index++] = b[M++];
	}
	while (N < n) c[index++] = a[N++];
	while (M < m) c[index++] = b[M++];
	for (i = 0; i < index; i++)
		cout << c[i] << " ";
}