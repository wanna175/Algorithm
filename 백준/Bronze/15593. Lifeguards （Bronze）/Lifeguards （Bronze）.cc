#include<iostream>
using namespace std;
int startT[100], endT[100];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> startT[i] >> endT[i];
	int maxT = 0;
	for (int i = 0; i < N; ++i) {
		//i번째 가드 해고
		int curT = 0;
		for (int t = 0; t < 1000; ++t) {
			for (int j = 0; j < N; ++j) {
				if (i == j) continue;
				if (startT[j] <= t && endT[j] > t) {
					curT++; break;
				}
			}
		}
		if (curT > maxT) maxT = curT;
	}
	cout << maxT;

	return 0;
}