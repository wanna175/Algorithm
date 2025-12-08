#include <bits/stdc++.h>

using namespace std;
int n,a;
vector<int> v;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a;
		v.push_back(a);	
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;++i){
		cout << v[i]<<'\n';
	}
	
	return 0;
}