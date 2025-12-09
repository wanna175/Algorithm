#include <bits/stdc++.h>

using namespace std;
int n,m,ret;
string str;
map<string,int> v;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>str;
		v[str]++;
	}
	for(int i=0;i<m;++i){
		cin>>str;
		if(v.find(str)!=v.end()){
			ret++;
		}
	}
	cout << ret;
	return 0;
} 