#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int N,M,ret=-1;
int a[54][54],visited[54][54];
const int dy[] = {1,0,-1,0};
const int dx[] = {0,1,0,-1};
int BFS(int y,int x){
	int r=0;
	fill(&visited[0][0],&visited[0][0]+54*54,0);
	queue<pii> q;
	q.push({y,x});
	visited[y][x] = 1;
	while(!q.empty()){
		int cy,cx;
		tie(cy,cx) = q.front();q.pop();
		for(int i=0;i<4;++i){
			int ny = cy+dy[i];
			int nx = cx+dx[i];
			if(ny<0||nx<0||ny>=N||nx>=M) continue;
			if(visited[ny][nx]) continue;
			if(a[ny][nx]!=1) continue;
			visited[ny][nx] = visited[cy][cx]+1;
			r = max(r,visited[ny][nx]);
			q.push({ny,nx});
		}
	}
	return r;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	
	cin>>N>>M;
	for(int i=0;i<N;++i){
		string s;
		cin >> s;
		for(int j=0;j<M;++j){
			if(s[j]=='L') a[i][j] = 1;
		}
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(a[i][j]!=1) continue;
			ret = max(ret,BFS(i,j));
		}
	}
	cout << ret-1 << '\n';
	return 0;
}