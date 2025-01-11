#include<iostream>
#define MOD 10007
using namespace std;
int N;
int dp[1002][10];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < 10; ++i)
		dp[1][i] = 1;

	for (int i = 2; i < N+2; ++i) {
		dp[i][9] = dp[i - 1][9];
		for (int j = 8; j >= 0; --j)
			dp[i][j] = (dp[i][j + 1] + dp[i - 1][j])%MOD;
	}
	cout << dp[N + 1][0];
	return 0;
}