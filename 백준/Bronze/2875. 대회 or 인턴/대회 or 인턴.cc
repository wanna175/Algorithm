#include<iostream>
#include<cmath>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, K;
	cin >> N >> M >> K;
	int answer = 0;
	for (int i = 0; i < N + 1; ++i) 
		for (int j = 0; j < M + 1; ++j) {
			if (i + j != K) continue;
			int m = min((N - i) / 2, M - j);
			if (m > answer) answer = m;
		}
	cout << answer;

	return 0;
}