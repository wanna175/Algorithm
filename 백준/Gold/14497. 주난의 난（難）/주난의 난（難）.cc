#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int N,M,turn = 1;
const int dy[] = {1,0,-1,0};
const int dx[] = {0,1,0,-1};
int _y1,_x1,_y2,_x2;
int a[304][304];
int visited[304][304];
void BFS(){
	queue<pii> q;
	while(true){
		if(visited[_y2][_x2]) return;
		fill(&visited[0][0],&visited[0][0]+304*304,0);
		visited[_y1][_x1] = 1;
		q.push({_y1,_x1});
		while(!q.empty()){
			int cy,cx;
			tie(cy,cx) = q.front();q.pop();
			for(int i=0;i<4;++i){
				int ny = cy+dy[i];
				int nx = cx+dx[i];
				if(ny<0||nx<0||ny>=N||nx>=M) continue;
				if(visited[ny][nx]) continue;
				visited[ny][nx] = 1;
				if(a[ny][nx] == 1){
					a[ny][nx] = 0;
					continue;
				}
				q.push({ny,nx});
			}
		}
		turn++;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>N>>M;
	cin>>_y1>>_x1>>_y2>>_x2;
	_y1--;_x1--;_y2--;_x2--;
	for(int i=0;i<N;++i){
		string s;
		cin>>s;
		for(int j=0;j<M;++j){
			if(s[j]=='1') a[i][j] = 1;
		}
	}
	BFS();
	cout << turn-1 << '\n';
	
	return 0;
}