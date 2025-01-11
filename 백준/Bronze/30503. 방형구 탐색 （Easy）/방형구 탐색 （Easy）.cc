#include <iostream>
#include <vector>
using namespace std;
int N,Q;
int arr[1001] = { 0 };
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> answer;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int n, l, r, k;
		cin >> n;
		if (n == 1) {
			int ret=0;
			cin >> l >> r >> k;
			for (int j = l; j <= r; ++j)
				if (arr[j] == k)
					++ret;
			answer.push_back(ret);
		}
		else {
			cin >> l >> r;
			for (int j = l; j <= r; ++j)
				arr[j] = -1;
		}
	}
	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << '\n';
	return 0;
}