#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};
int R,C,ret;
int a[1004][1004];
int visited[1004][1004], visited_j[1004][1004];
deque<pii> dq;
int BFS(){
	while(!dq.empty()){
		int cy,cx;
		tie(cy,cx) = dq.front();dq.pop_front();
		for(int i=0;i<4;++i){
			int ny = cy+dy[i];
			int nx = cx+dx[i];
			if(ny<0||nx<0||ny>=R||nx>=C){
				if(a[cy][cx] == 2) return visited_j[cy][cx];
				continue;
			}
			if (a[cy][cx] == 2){
				if(visited_j[ny][nx]) continue;
				if(a[ny][nx]!=0) continue;
				visited_j[ny][nx] = visited_j[cy][cx]+1;
				
				a[ny][nx] = 2;
				dq.push_back({ny,nx});
			}
			else{
				if(visited[ny][nx]) continue; 
				if(a[ny][nx]==-1) continue;
				a[ny][nx] = 1;
				visited[ny][nx] = 1; 
				dq.push_back({ny,nx});
			}
		}
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>R>>C;
	for(int i=0;i<R;++i){
		string s;
		cin>>s;
		for(int j=0;j<C;++j){
			if(s[j]=='#') a[i][j] = -1;
			else if(s[j]=='J'){
				a[i][j] = 2;
				dq.push_front({i,j});	
				visited_j[i][j] = 1;
			} 
			else if(s[j]=='F'){
				a[i][j] = 1;
				dq.push_back({i,j});
				visited[i][j] = 1;
			}
		}
	}
	ret = BFS();
	if(ret!=-1) cout << ret << '\n';
	else cout << "IMPOSSIBLE" << '\n';
	return 0;
}