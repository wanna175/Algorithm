#include<iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int A, B;
	cin >> A >> B;
	int cnt = 0;
	int i = -3000;
	while (i<=3000) {
		if (i * i + 2 * i * A + B == 0)
			cout<<i<<' ';
		i++;
	}

	return 0;
}