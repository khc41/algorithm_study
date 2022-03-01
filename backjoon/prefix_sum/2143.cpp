#include <iostream>
#include <map>
using namespace std;

int a[1001];
int b[1001];
map<long long , long long> sub_sum;

int main() {
	long long T;
	int n, m;
	cin >> T;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> b[i];

	for (int i = 0; i < n; i++) { // 개수
		for (int j = 0; j < n - i; j++) { // 시작
			int idx = j; long long sum = 0;
			while (idx <= i + j) {
				sum += a[idx++];
			}
			sub_sum[sum]++;
		}
	}
	long long ret = 0;
	for (int i = 0; i < m; i++) { // 개수
		for (int j = 0; j < m - i; j++) { // 시작
			int idx = j; long long sum = 0;
			while (idx <= i + j) {
				sum += b[idx++];
			}
			ret += sub_sum[T - sum];
		}
	}
	cout << ret;
}