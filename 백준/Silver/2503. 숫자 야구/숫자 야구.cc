#include<iostream>

using namespace std;
int num[100], strike[100], ball[100];
bool isCollect(int i,int j,int k,int n) {
	int number = num[n];
	int st = 0, ba = 0;
	if (number % 10 == k)
		st++;
	if (number % 10 == j)
		ba++;
	if (number % 10 == i)
		ba++;
	number /= 10;
	if (number % 10 == k)
		ba++;
	if (number % 10 == j)
		st++;
	if (number % 10 == i)
		ba++;
	number /= 10;
	if (number % 10 == k)
		ba++;
	if (number % 10 == j)
		ba++;
	if (number % 10 == i)
		st++;
	if (strike[n] == st && ball[n] == ba)
		return true;
	return false;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> num[i] >> strike[i] >> ball[i];
	int cnt = 0;
	for(int i=1;i<10;++i)
		for(int j=1;j<10;++j)
			for (int k = 1; k < 10; ++k) {
				if (i == j || j == k || i == k) continue;
				bool flag = false;
				for (int n = 0; n < N; ++n) {
					if (!isCollect(i, j, k, n)) {
						flag = true;
						break;
					}
				}
				if (!flag) cnt++;
			}
	cout << cnt;
	return 0;
}