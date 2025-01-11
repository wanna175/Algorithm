#include<iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int A, B, C, N;
	cin >> A >> B >> C >> N;
	int ans = 0;
	for(int i=0;i<N+1;i+=A)
		for(int j=0;j<N+1;j+=B)
			for (int k = 0; k < N + 1; k+=C) {
				if (i + j + k != N) continue;
				ans = 1;
				break;
			}
	cout << ans;

	return 0;
}