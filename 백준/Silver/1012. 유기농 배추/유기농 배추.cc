#include <bits/stdc++.h>

using namespace std;
int T,N,M,K;

const int dy[] = {1,0,-1,0};
const int dx[] = {0,1,0,-1};

int a[54][54], visited[54][54];
void DFS(int y,int x){
	visited[y][x] = 1;
	for(int i=0;i<4;++i){
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(ny<0||nx<0||ny>=N||nx>=M) continue;
		if(visited[ny][nx]) continue;
		if(a[ny][nx] == 0) continue;
		DFS(ny,nx);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>T;
	while(T!=0){
		--T;
		int ret=0;
		cin>>M>>N>>K;
		fill(&a[0][0],&a[0][0]+54*54,0);
		fill(&visited[0][0],&visited[0][0]+54*54,0);
		for(int i=0;i<K;++i){
			int x,y;
			cin>>x>>y;
			a[y][x] = 1;
		}
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				if(visited[i][j]||!a[i][j]) continue;
				ret++;DFS(i,j);
			}
		}
		cout << ret << '\n';
	}
	return 0;
} 