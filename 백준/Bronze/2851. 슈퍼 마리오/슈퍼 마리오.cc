#include<iostream>
using namespace std;
int arr[10];
int score[10];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int sum = 0;
	for (int i = 0; i < 10; ++i) {
		cin >> arr[i];
		sum += arr[i];
		score[i] = sum-100;
	}
	int answer=-101;
	for (int i = 0; i < 10; ++i) {
		if (score[i] < 0) {
			answer = max(answer, score[i]);
		}
		else {
			if (-answer >= score[i]) {
				answer = score[i];
				break;

			}
		}
	}
	cout << answer + 100;

	return 0;
}