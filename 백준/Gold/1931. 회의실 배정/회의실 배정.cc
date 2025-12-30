#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int n,s,e,ret;
vector<pii> v;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>s>>e;
		v.push_back({e,s});
	}
	sort(v.begin(),v.end());
	int end=0;
	for(int i=0;i<n;++i){
		if(end>v[i].second) continue;
		end = v[i].first;
		ret++;
	}
	cout << ret;
	return 0;
}