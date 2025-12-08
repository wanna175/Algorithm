#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int n,y,x;
vector<pii> v;
bool cmp(pii a,pii b){
	if(a.first ==b.first){
		return a.second < b.second;
	}
	return a.first <b.first; 
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>x>>y;
		v.push_back({x,y});
	}
	sort(v.begin(),v.end(),cmp);
	for(auto it : v) cout << it.first << " " << it.second << '\n';
	return 0;
} 