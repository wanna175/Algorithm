#include <bits/stdc++.h>

using namespace std;
int n,k,s;
vector<int> v;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>s;
		v.push_back(s);
	}
	sort(v.begin(),v.end(),greater<int>());
	cout << v[k-1]; 
	return 0;
} 