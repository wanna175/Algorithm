#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAX 200001 
using namespace std;
int V, E, st;
//비용, 정점
vector<pair<int, int>> adj[20001];
int d[20001];
void dijkstra() {
	fill_n(&d[0], V+1, MAX);
	priority_queue<pair<int,int>> pq;
	d[st] = 0;
	pq.push({ -d[st],st });

	while (!pq.empty()) {
		int current = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (cost > d[current])continue;
		for (int i = 0; i < adj[current].size(); ++i) {
			int next = adj[current][i].second;
			int next_cost = cost + adj[current][i].first;

			if (next_cost < d[next]) {
				d[next] = next_cost;
				pq.push({ -next_cost,next });
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> V >> E >> st;
	for (int i = 0; i < E; ++i) {
		int u,v,w;
		cin >> u >> v>> w;
		adj[u].push_back({ w,v });
	}
	dijkstra();
	for (int i = 1; i <= V; ++i) {
		if (d[i] == MAX)
			cout << "INF\n";
		else
			cout << d[i] << '\n';
	}

	return 0;
}