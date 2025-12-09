#include <bits/stdc++.h>

using namespace std;
int n,m,a;
map<int,int> v;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a;
		v[a]++;
	}
	cin>>m;
	for(int i=0;i<m;++i){
		cin>>a;
		if(v.find(a)!=v.end()){
			cout << 1<<" ";
		}else cout << 0 << " ";
	}
	return 0;
}