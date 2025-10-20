#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int N,M,t=1,ret;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
queue<pii> q;
int a[100][100],visited_d[100][100],visited_b[100][100];
void check(int t){
	for(int i=1;i<N-1;++i){
		for(int j=1;j<M-1;++j){
			if (a[i][j]!=1) continue;
			if (visited_b[i][j]!=0) continue;
			for(int k=0;k<4;++k){
				if(a[i+dy[k]][j+dx[k]] == -1&&visited_b[i][j]==0){
					visited_b[i][j] = t;
					q.push({i,j});
				}
			}
		}
	}
}
void DFS(int y,int x){
	visited_d[y][x] = 1;
	a[y][x] = -1;
	for(int i=0;i<4;++i){
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(ny<0||nx<0||ny>=N||nx>=M) continue;
		if(a[ny][nx]==1) continue;
		if(visited_d[ny][nx]) continue;
		DFS(ny,nx);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>a[i][j];
		}
	}
	DFS(0,0);
	check(1);
	while(!q.empty()){
		int cy,cx;
		tie(cy,cx) = q.front();q.pop();
		a[cy][cx] = 0;
		if(visited_b[cy][cx] !=t){
			t++;
			fill(&visited_d[0][0],&visited_d[0][0]+10000,0);
			DFS(0,0);
			check(t);
		}
		for(int i=0;i<4;++i){
			int ny = cy+dy[i];
			int nx = cx+dx[i];
			if(visited_b[ny][nx]!=0) continue;
			if(a[ny][nx] != 1) continue;
			visited_b[ny][nx] = visited_b[cy][cx]+1;
			q.push({ny,nx});
			
		}
	}
	cout << t << '\n';
	for(int i=1;i<N-1;++i){
		for(int j=1;j<M-1;++j){
			if(visited_b[i][j] == t) ret++;
		}
	}
	cout << ret << '\n';
	return 0;
}