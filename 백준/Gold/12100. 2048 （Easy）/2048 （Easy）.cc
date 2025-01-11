#include<iostream>
#include<cmath>
using namespace std;

int N;
int board[21][21],board2[21][21];
void rotate() {
	int tmp[21][21] = { 0 };
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			tmp[i][j] = board2[N - j - 1][i];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			board2[i][j] = tmp[i][j];
}
void tilt(int dir) {
	while (dir--) rotate();
	for (int k = 0; k < N; ++k) {
		int arr[21] = { 0 };
		int idx = 0;
		for (int i = 0; i < N; ++i) {
			if (board2[k][i] == 0) continue;
			if (arr[idx] == board2[k][i]) arr[idx++] *= 2;
			else if (arr[idx] == 0) arr[idx] = board2[k][i];
			else arr[++idx] = board2[k][i];
		}
		for (int i = 0; i < N; ++i) board2[k][i] = arr[i];
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];

	int m = 0;
	//4진법인데 5자리수까지 가능 4^5 = 2^10 = 1024가지의 경우
	for (int tmp = 0; tmp < 1024; ++tmp) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				board2[i][j] = board[i][j];
		
		int d = tmp;
		for (int i = 0; i < 5; ++i) {
			int dir = d % 4;
			d /= 4;
			tilt(dir);
		}

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				m = max(m, board2[i][j]);
	}
	cout << m;
	return 0;
}