#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string _str;
bool isPalin[2501][2501] = { false };
int dp[2501] = { 0 };
void make_Palindrome() {
	for (int i = 1; i <= _str.size(); ++i)
		isPalin[i][i] = true;
	for (int i = 1; i < _str.size(); ++i)
		if (_str[i-1] == _str[i]) isPalin[i][i + 1] = true;
	for (int size = 3; size <= _str.size(); ++size) {
		for (int i = 1; i <= _str.size() - size+1; ++i) {
			if (_str[i-1] == _str[i + size - 2] && isPalin[i + 1][i + size - 2])
				isPalin[i][i + size - 1] = true;
		}
	}
}
void solve() {
	for (int i = 1; i <= _str.size(); ++i) {
		dp[i] = 2501;
		for (int j = 1; j <= i; ++j) {
			if (isPalin[j][i])
				dp[i] = min(dp[i], dp[j - 1] + 1);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> _str;
	make_Palindrome();
	solve();
	cout << dp[_str.size()];
	return 0;
}