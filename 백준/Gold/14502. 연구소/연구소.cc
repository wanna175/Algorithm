#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};
int N,M,m;//3-8
int a[10][10],visited[10][10],b[10][10];
vector<pii> birus;
int BFS(){
	queue<pii> q;
	int ret=0;
	fill(&visited[0][0],&visited[0][0]+10*10,0);
	fill(&b[0][0],&b[0][0]+10*10,0);
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			b[i][j] = a[i][j];
		}
	}
	for(auto i : birus){
		q.push(i);
		visited[i.first][i.second] = 1;
	}
	while(!q.empty()){
		int cy,cx;
		tie(cy,cx) = q.front();q.pop();
		for(int i=0;i<4;++i){
			int ny = cy+dy[i];
			int nx = cx+dx[i];
			if(ny<0||nx<0||ny>=N||nx>=M) continue;
			if(visited[ny][nx]) continue;
			if(b[ny][nx]!=0) continue;
			visited[ny][nx] = 1;
			b[ny][nx] = 2;
			q.push({ny,nx});
		}
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(b[i][j] == 0) ret++;
		}
	}
	return ret;
}
void combi(pii start,int size){
	if(size == 3){
		//BFS
		m = max(m,BFS());
		return;
	}
	auto i = start;
	while(true){
		i.second++;
		if(i.second >=M){
			i.first++;
			i.second = 0;
		}
		if(i.first>=N){
			break;
		}
		if(a[i.first][i.second]!=0) continue;
		
		a[i.first][i.second] = 1;
		combi(i,size+1);
		a[i.first][i.second] = 0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>> a[i][j];
			if(a[i][j] == 2)
				birus.push_back({i,j});
		}
	}
	combi({0,-1},0);
	cout<<m<<'\n';
	return 0;
}