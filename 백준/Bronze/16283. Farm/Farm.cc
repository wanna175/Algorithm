#include<iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, n, w;
	cin >> a >> b >> n >> w;
	int ans = -1;
	bool flag = false;
	for (int i = 1; i < n; ++i) {
		if (w == a * i + b * (n - i)) {
			if (flag) {
				ans = -1;
				break;
			}
			ans = i;
			flag = true;
		}
	}
	if (ans == -1)
		cout << ans;
	else
		cout << ans << " " << n - ans;
	return 0;
}