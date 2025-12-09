#include <bits/stdc++.h>

using namespace std;
int n,m,a,ret,cnt;
map<int,int> v;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>> a;
		v[a]++;
	}
	for(int i=0;i<m;++i){
		cin>>a;
		if(v.find(a)!=v.end()){
			cnt++;
		}
	}
	cout << n+m-2*cnt;
	return 0;
} 