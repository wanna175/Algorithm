#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, K;
vector<int> adj[1001];
bool isvisited[1001];
int matched[1001];
bool dfs(int u) {
	for (int v : adj[u]) {
		if (isvisited[v]) continue;
		isvisited[v] = true;

		if (matched[v] == -1 || dfs(matched[v])) {
			matched[v] = u;
			return true;
		}
	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	//이분그래프 만들기
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			int m;
			cin >> m;
			adj[i].push_back(m);
		}
	}

	int cnt = 0;
	fill_n(&matched[0], 1001, -1);
	for (int i = 0; i < N; ++i) {
		fill_n(&isvisited[0], 1001, false);
		if (dfs(i)) cnt++;
	}
	int c = 0;
	for (int i = 0; i < N; ++i) {
		fill_n(&isvisited[0], 1001, false);
		if (dfs(i)) { cnt++; c++; }
		if (c == K) break;
	}

	cout << cnt;

	return 0;
}