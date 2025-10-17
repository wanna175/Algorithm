#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int H,W;
int a[104][104];
queue<pii> q;
void BFS(){
	while(!q.empty()){
		int cy,cx;
		tie(cy,cx) = q.front();q.pop();
		
		int ny = cy;
		int nx = cx+1;
		if(nx>=W) continue;
		if(a[ny][nx] !=-1) continue;
		a[ny][nx] = a[cy][cx]+1;
		q.push({ny,nx});
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	
	cin>>H>>W;
	fill(&a[0][0],&a[0][0]+104*104,-1);
	for(int i=0;i<H;++i){
		string s;
		cin>>s;
		for(int j=0;j<W;++j){
			if(s[j]=='.')continue;
			a[i][j] = 0;
			q.push({i,j});
		}
	}
	BFS();
	for(int i=0;i<H;++i){
		for(int j=0;j<W;++j){
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}
	
	return 0;
}