#include<iostream>
#include<algorithm>
using namespace std;
int n;
int grape[10001];
int d[10001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> grape[i];

	d[1] = grape[1];
	d[2] = grape[2] + grape[1];
	for (int i = 3; i <= n; ++i)
		d[i] = max({ d[i - 1],d[i - 2] + grape[i],d[i - 3] + grape[i - 1] + grape[i] });

	cout << d[n];
	return 0;
}