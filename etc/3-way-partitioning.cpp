#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int> &arr, int begin, int end) {
	int lo = begin, hi = end, i = begin;
	if (begin >= end) return;
	while (i <= hi) {
		if (arr[lo] > arr[i]) swap(arr[lo++], arr[i++]);
		else if (arr[i] == arr[lo]) i++;
		else swap(arr[i], arr[hi--]);
	}
	sort(arr, begin, lo-1);
	sort(arr, i, end);
}

int main () {
	int n;
	cin >> n;
	vector<int> ar(n);
	for (int i = 0; i < n; ++i)
		cin >> ar[i];
	sort(ar, 0, n-1);
	return 0;
}

