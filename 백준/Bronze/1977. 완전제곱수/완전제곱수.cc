#include<iostream>
#include<cmath>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int M, N;
	cin >> M >> N;
	int m = -1,sum=0;
	for (int i = 1; i < 101; ++i) {
		int a = i * i;
		if (a<M || a>N) continue;
		if (m == -1) m = a;
		sum += a;
	}
	if (m == -1)
		cout << -1;
	else
		cout << sum << '\n' << m;

	return 0;
}