#include <bits/stdc++.h>

using namespace std;
int n,m,ret;
const int dy[] = {0,-1,0,1};
const int dx[] = {-1,0,1,0};
int a[54][54],visited[54][54],adj[2504][2504];
int sum[2504];
void dfs(int y,int x,int num){
	sum[num]++;
	visited[y][x] = num;
	for(int i=0;i<4;++i){
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(ny<0||nx<0||ny>=m||nx>=n) continue;
		if(visited[ny][nx]){
			adj[num][visited[ny][nx]] = 1;
			continue;
		}
		if(a[y][x]&(1<<i)) continue;
		dfs(ny,nx,num);
	}
}
void solve(int num){
	for(int i=1;i<=num;++i){
		for(int j=i+1;j<=num;++j){
			if(adj[i][j]||adj[j][i]) ret = max(ret,sum[i]+sum[j]);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cin>>a[i][j];
		}
	}
	int cnt = 1;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			if(visited[i][j]) continue;
			dfs(i,j,cnt++);
		}
	}
	solve(cnt-1);
	cout << cnt-1 << '\n';
	cout << *max_element(&sum[0],&sum[0]+n*m) << '\n';
	cout << ret <<'\n';
	return 0;
}