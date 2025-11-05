#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int r,c,k,ret;
char a[10][10];
int visited[10][10];
const int dy[] = {1,0,-1,0};
const int dx[] = {0,1,0,-1};
void dfs(int y,int x,int dep){
	if(dep==k){
		if(y==0&&x==c-1) ret++;
		return;
	}

	for(int i=0;i<4;++i){
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(ny<0||nx<0||ny>=r||nx>=c) continue;
		if(visited[ny][nx]) continue;
		if(a[ny][nx] == 'T') continue;
		visited[ny][nx] = 1;
		dfs(ny,nx,dep+1);
		visited[ny][nx] = 0;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>r>>c>>k;
	for(int i=0;i<r;++i){
		string s;
		cin>>s;
		for(int j=0;j<c;++j){
			a[i][j] = s[j];
		}
	}
	visited[r-1][0] = 1;
	dfs(r-1,0,1);
	cout << ret << '\n';
	return 0;
}