#include <bits/stdc++.h>

using namespace std;

int N;
int a[3],visited[61][61][61];
int d[6][3]={
	{9,3,1},
	{9,1,3},
	{3,9,1},
	{3,1,9},
	{1,3,9},
	{1,9,3}
};
struct p{
	int a,b,c;
};
void BFS(int a,int b,int c){
	queue<p> q;
	q.push({a,b,c});
	visited[a][b][c] = 0;
	while(!q.empty()){
		if(visited[0][0][0]) break;
		p cp = q.front(); q.pop();
		for(int i=0;i<6;++i){
			int na = max(0,cp.a-d[i][0]);
			int nb = max(0,cp.b-d[i][1]);
			int nc = max(0,cp.c-d[i][2]);
			if(visited[na][nb][nc]) continue;
			visited[na][nb][nc] = visited[cp.a][cp.b][cp.c]+1;
			q.push({na,nb,nc});
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	
	cin >>N;
	for(int i=0;i<N;++i){
		cin>>a[i];
	}
	BFS(a[0],a[1],a[2]);
	cout << visited[0][0][0] <<'\n';
	return 0;
}