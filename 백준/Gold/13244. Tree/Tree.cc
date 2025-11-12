#include <bits/stdc++.h>

using namespace std;
int t,n,m,e1,e2,visited[1001];
int adj[1001][1001];
bool bfs(){
	queue<int> q;
	q.push(1);
	visited[1]=1;
	while(q.size()){
		int cur = q.front();q.pop();
		for(int i=1;i<=n;++i){
			if(!adj[cur][i]) continue;
			adj[i][cur] = 0;
			if(visited[i]) return 0;
			visited[i] = visited[cur]+1;
			q.push(i);
		}
	}
	for(int i=1;i<=n;++i){
		if(!visited[i]) return 0;
	}
	return 1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	while(t--){
		bool ret = 1;
		fill(&adj[0][0],&adj[0][0]+1001*1001,0);
		fill(&visited[0],&visited[0]+1001,0);
		cin>>n>>m;
		for(int i=0;i<m;++i){
			cin>>e1>>e2;
			if(adj[e1][e2]) ret = 0; 
			adj[e1][e2] = 1;
			adj[e2][e1] = 1;
		}	
		if(!ret){
			cout <<"graph\n";
			continue;
		}
		ret = bfs();
		if(ret){
			cout <<"tree\n";
		}else{
			cout <<"graph\n";
		}
	}
	return 0;
}