#include<iostream>

using namespace std;
int arr[1000001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 1;
	int idx = 1;
	while(num<1000001){
		int n = idx;
		bool visit[10] = { false };
		bool flag = false;
		while (n!=0) {
			if (visit[n % 10]) { flag = true; break; }
			visit[n % 10] = true;
			n /= 10;
		}
		if (flag) {
			idx++;
		}
		else {
			arr[num++] = idx++;
		}
	}

	while (true) {
		int n;
		cin >> n;
		if (n == 0)break;
		cout << arr[n] << '\n';
	}
	return 0;
}