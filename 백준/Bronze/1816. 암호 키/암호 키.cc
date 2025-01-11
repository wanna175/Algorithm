#include<iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		long long S;
		bool flag = false;
		cin >> S;
		for(long long j=2;j<1000000;++j)
			if (S % j == 0) {
				flag = true;
				break;
			}
		if (flag) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}