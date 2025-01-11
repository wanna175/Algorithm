#include <iostream>
#include <vector>
using namespace std;
int N,M;
int arr[1001][2] = {0};
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a,c;
		char b;
		cin >> a >> b >> c;
		if (b == 'P') {
			arr[a][0] = c + 1;
		}
		else
			arr[a][1] = c+1;
	}
	int MM = 0, mm = 0;
	for (int i = 1; i <= N; ++i) {
		if (arr[i][0] == 2 && arr[i][1] == 1) {
			++MM; ++mm;
		}
		else if ((arr[i][0] == 2 && arr[i][1] == 0)
			|| (arr[i][1] == 1 && arr[i][0] == 0))
			++MM;
		else if ((arr[i][0] == 0 && arr[i][1] == 0))
			++MM;
	}
	cout << mm << ' ' << MM;
	return 0;
}