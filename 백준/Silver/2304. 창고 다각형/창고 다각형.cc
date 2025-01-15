#include<iostream>

using namespace std;
int height[1001];
int right(int x) {
	if (x + 1 > 1000) return 0;
	int mh = 0,tx=-1;
	for(int i=x+1;i<1001;++i)
		if (mh <= height[i]) {
			tx = i;
			mh = height[i];
		}
	return (tx - x) * mh + right(tx);
}
int left(int x) {
	if (x - 1 < 0)return 0;
	int mh = 0, tx = -1;
	for (int i = x - 1; i > 0; --i)
		if (mh <= height[i]) {
			tx = i;
			mh = height[i];
		}
	return (x-tx) * mh + left(tx);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N,mh=-1;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int L, H;
		cin >> L >> H;
		height[L] = H;
		if (mh < H) mh = H;
	}
	int fx = -1, sx = -1;
	for (int i = 0; i < 1001; ++i) {
		if (height[i] != mh)continue;
		if (fx == -1) fx = i;
		sx = i;
	}
	int sum = left(fx) + right(sx) + (sx - fx + 1) * mh;
	cout << sum;
	return 0;
}