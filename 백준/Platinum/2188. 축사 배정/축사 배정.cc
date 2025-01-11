#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> adj[201];
bool isvisited[201];
int matched[201];
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
	cin >> N >> M;
	//이분그래프 만들기
	for (int i = 1; i <= N; ++i) {
		int n;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			int m;
			cin >> m;
			adj[i].push_back(m);
		}
	}

	int cnt = 0;
	fill_n(&matched[0], 201, -1);
	for (int i = 1; i <= N; ++i) {
		fill_n(&isvisited[0], 201, false);
		if (dfs(i)) cnt++;
	}
	cout << cnt;
	
	return 0;
}