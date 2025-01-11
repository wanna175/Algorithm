#include<iostream>

using namespace std;

int d[1000001];
int pre[1000001];
int N;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 2; i <= N; ++i) {
		d[i] = d[i - 1] + 1;
		pre[i] = i - 1;
		if (i % 2 == 0 && d[i] > d[i / 2] + 1) {
			d[i] = d[i / 2] + 1;
			pre[i] = i / 2;
		}
		if (i % 3 == 0 && d[i] > d[i / 3] + 1) {
			d[i] = d[i / 3] + 1;
			pre[i] = i / 3;
		}
	}
	cout << d[N] << '\n';
	while (true) {
		cout << N<<" ";
		if (N == 1)break;
		N = pre[N];
	}

	return 0;
}