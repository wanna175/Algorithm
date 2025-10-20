#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int N,M,m;
vector<int> v[10001];
int ret[10001],visited[10001];
int DFS(int start){
	visited[start] = 1; 
	int cnt=1;
	for(int i:v[start]){
		if(visited[i]) continue;
		cnt += DFS(i);
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<M;++i){
		int a,b;
		cin >>a>>b;
		v[b].push_back(a);
	}
	
	for(int i=1;i<=N;++i){
		fill(visited,visited+10001,0);
		ret[i] = DFS(i);
		m = max(m,ret[i]);
	}
	for(int i=1;i<=N;++i){
		if(m == ret[i]) cout << i << " ";
	}
	return 0;
}