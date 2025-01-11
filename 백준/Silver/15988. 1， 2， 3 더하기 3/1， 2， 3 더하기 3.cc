#include<iostream>
#define mod 1000000009

using namespace std;
int T;
long long d[1000001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;

	d[1] = 1;
	d[2] = 2;
	d[3] = 4;

	//dp배열 구하기
	for (int i = 4; i < 1000001; ++i)
		d[i] = (d[i - 1] + d[i - 2] + d[i - 3])% mod;

	//test case만큼 돌리기
	for (int i = 0; i < T; ++i) {
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}
	return 0;
}