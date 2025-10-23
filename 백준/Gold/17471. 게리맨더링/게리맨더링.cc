#include <bits/stdc++.h>

using namespace std;
int N,n,d,ret=1e8;
int p[12],visited[12];
int adj[12][12];
vector<int> a,b;
void solve(int s,vector<int> v){
	visited[s] = 1;	
	for(int i : v){
		if(visited[i]) continue;
		if(!adj[s][i]) continue;
		solve(i,v);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>p[i];
	}
	for(int i=1;i<=N;++i){
		cin>>n;
		for(int j=0;j<n;++j){
			cin >> d;
			adj[i][d] = 1;
			adj[d][i] = 1;
		}
	}
	for(int i=0;i<(1<<N);++i){
		for(int j=0;j<N;++j){
			if(i&(1<<j)){
				a.push_back(j+1);
			}else b.push_back(j+1);
		}
		if(a.size()==0||b.size()==0) continue;
		int ra = 0,rb=0;
		fill(&visited[0],&visited[0]+12,0);
		solve(a[0],a);
		for(int l : a){
			if(!visited[l]){
				ra = -1;
				break;
			}
			ra+=p[l];
		}
		fill(&visited[0],&visited[0]+12,0);
		solve(b[0],b);
		for(int l : b){
			if(!visited[l]){
				rb = -1;
				break;
			}
			rb+=p[l];
		}
		a.clear();b.clear();
		if(ra==-1||rb==-1) continue;
		ret = min(ret,abs(ra-rb));
	}
	if(ret == 1e8) cout << -1 <<'\n';
	else cout <<ret << '\n';
	return 0;
}