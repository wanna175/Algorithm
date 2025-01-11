#include <iostream>
#include <vector>
using namespace std;
int arr[12] = { 0 };
void solve(int n) {
	if (n > 11)
		return;
	if (n != 0)
		arr[n]++;
	solve(n + 1);
	solve(n + 2);
	solve(n + 3);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	solve(0);
	vector<int> answer(T, 0);
	for (int i = 0; i < T; ++i) {
		int tmp;
		cin >> tmp;
		answer[i]=arr[tmp];
	}
	for (int i = 0; i < T; ++i)
		cout << answer[i] << '\n';
	return 0;
}