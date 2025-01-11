#include<iostream>

using namespace std;
int N,M;
bool seat[41];
int dp[41][2];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int n;
		cin >> n;
		seat[n] = true;
	}
	dp[N][0] = 1;
	dp[N][1] = 0;

	dp[N - 1][0] = 1;
	dp[N - 1][1] = (seat[N - 1]||seat[N]) ? 0 : 1;
	for (int i = N-2; i >= 0; --i) {
		dp[i][0] = dp[i + 1][0] + dp[i + 1][1];
		dp[i][1] = (seat[i]||seat[i+1]) ? 0 : dp[i + 1][0];
	}
	cout << dp[0][0];
	return 0;
}