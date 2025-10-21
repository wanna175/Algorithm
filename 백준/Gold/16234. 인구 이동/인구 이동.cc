#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int N,L,R,ret,sum;
const int dy[] = {1,0,-1,0};
const int dx[] = {0,1,0,-1};
int a[54][54],visited[54][54];
vector<pii> v;
void BFS(int y, int x, int d){
	queue<pii> q;
	q.push({y,x});
	v.push_back({y,x});
	sum+=a[y][x];
	visited[y][x] = d;
	while(!q.empty()){
		int cy,cx;
		tie(cy,cx) = q.front();q.pop();
		for(int i=0;i<4;++i){
			int ny = cy+dy[i];
			int nx = cx+dx[i];
			if(ny<0||nx<0||ny>=N||nx>=N) continue;
			if(visited[ny][nx] != 0) continue;
			int diff = abs(a[ny][nx]-a[cy][cx]);
			if(diff<L||diff>R) continue;
			visited[ny][nx] = d;
			q.push({ny,nx});
			v.push_back({ny,nx});
			sum+=a[ny][nx];
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>N>>L>>R;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>a[i][j];
		}
	}
	while(true){
		
		fill(&visited[0][0],&visited[0][0]+54*54,0);
		int cnt=1;
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				if(visited[i][j]!=0) continue;
				BFS(i,j,cnt);
				cnt++;
				for(auto p:v){
					a[p.first][p.second] = sum/v.size();
				}
				sum=0;
				v.clear();
			}
		}
		
		if(cnt==N*N+1) break;
		
		ret++;
	}
	cout << ret << '\n';
	return 0;
} 