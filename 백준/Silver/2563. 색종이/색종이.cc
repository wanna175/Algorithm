#include<iostream>

using namespace std;
int arrx[100], arry[100];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arrx[i] >> arry[i];
	int cnt = 0;
	for(int x=0;x<100;++x)
		for (int y = 0; y < 100; ++y) {
			for (int i = 0; i < N; ++i) {
				if (arrx[i] > x || arry[i] > y) continue;
				if (arrx[i] + 10 <= x || arry[i]+10 <= y) continue;
				cnt++;
				break;
			}
		}
	cout << cnt;
	return 0;
}