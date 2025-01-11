#include<iostream>

using namespace std;
int N;
long d[91][2];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	d[1][1] = 1;
	d[1][0] = 0;
	for (int i = 2; i <= N; ++i) {
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}
	cout << d[N][0] + d[N][1] << '\n';

	return 0;
}