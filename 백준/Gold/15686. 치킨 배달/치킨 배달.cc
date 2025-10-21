#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

const int INF = 1e8;
int N,M,ret = INF;//2-50
int a[54][54];
vector<pii> v;
vector<pii> sel;
int sumd(){
	int r=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(a[i][j]!=1) continue;
			int s = INF;
			for(auto k : sel){
				int d = abs(i-k.first)+abs(j-k.second);
				s=min(s,d);
			}
			r+=s;
		}
	}
	return r;
}
void solve(int idx,int size){
	if (size == sel.size()){
		ret = min(ret,sumd());
		return;
	}
	if(idx >=v.size()) return;
	solve(idx+1,size);
	sel.push_back(v[idx]);
	solve(idx+1,size);
	sel.pop_back();
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>a[i][j];
			if(a[i][j]==2) v.push_back({i,j});
		}
	}
	solve(0,M);

	cout << ret <<'\n';
	return 0;
}