#include<iostream>
#include<cmath>
using namespace std;
int N;

int dp[10001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> dp[i];

	for (int i = 2; i <= N; ++i)
		for (int j = i - 1; j > 0; --j) {
			if (2 * j < i) break;
			dp[i] = max(dp[j] + dp[i - j], dp[i]);
		}
	cout << dp[N];
	return 0;
}