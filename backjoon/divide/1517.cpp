#include <iostream>
#include <algorithm>
using namespace std;

int a[500001];
int sorted[500001];
long long cnt = 0;

void merge(int left, int mid, int right) {
	int leftIndex = left;
	int rightIndex = mid + 1;
	int index = left;
	while (leftIndex <= mid && rightIndex <= right) {
		if (a[leftIndex] <= a[rightIndex]) {
			sorted[index++] = a[leftIndex++];
		}
		else {
			sorted[index++] = a[rightIndex++];
			cnt += (mid + 1 - leftIndex);
		}
	}
	if (leftIndex > mid) {
		for (int i = rightIndex; i <= right; i++)
			sorted[index++] = a[i];
	}
	else {
		for (int i = leftIndex; i <= mid; i++)
			sorted[index++] = a[i];
	}
	for (int i = left; i <= right; i++) {
		a[i] = sorted[i];
	}		
}

void merge_sort(int left, int right) {
	int mid = (left + right) / 2;
	if (left < right) {
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	merge_sort(0, N - 1);
	cout << cnt;
}