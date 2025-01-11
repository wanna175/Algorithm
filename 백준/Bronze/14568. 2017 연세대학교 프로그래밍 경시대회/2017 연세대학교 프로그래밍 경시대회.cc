#include<iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	int ans = 0;
	for(int i=1;i<N+1;++i)
		for(int j=1;j<N+1;++j)
			for (int k = 1; k < N + 1; ++k) {
				if (i + j + k != N) continue;
				if (k < j + 2) continue;
				if (i % 2 == 1) continue;
				ans++;
			}
	cout << ans;

	return 0;
}