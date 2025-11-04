#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int s = 3;
const int dy[] = {1,0,-1,0,0};
const int dx[] = {0,1,0,-1,0};
int N,ret=1e8;
int a[10][10];
int visited[10][10];
void sum(){
	int su = 0;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(visited[i][j]){
				su+=a[i][j];
			}
		}
	}
	ret = min(su,ret);
}
void combi(int y,int x,int c){
	if(c==s){
		sum();
		return;
	}
	if(y>=N-1) return;
	int ny = y;
	int nx = x+1;
	if(nx>=N-1){
		ny++;nx = 1;
	}
	
	combi(ny,nx,c);
	for(int i=0;i<5;++i){
		if(visited[y+dy[i]][x+dx[i]]) return;
	}
	for(int i=0;i<5;++i){
		visited[y+dy[i]][x+dx[i]] = 1;
	}
	combi(ny,nx,c+1);
	for(int i=0;i<5;++i){
		visited[y+dy[i]][x+dx[i]] = 0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j)
			cin>>a[i][j];
	}
	combi(1,1,0);
	cout << ret << '\n';
	return 0;
} 