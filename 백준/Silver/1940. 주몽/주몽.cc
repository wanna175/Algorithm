#include <bits/stdc++.h>

using namespace std;
int N,M,ret = 0;
map<int,int> m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	
	cin>>N>>M;
	for(int i=0;i<N;++i){
		int n;
		cin>>n;
		m[n] = 1;
	}
	for(auto e : m){
		if(m.find(M-e.first)!=m.end()) ret++;
	}
	cout<< ret/2 << '\n';
	
	return 0;
}