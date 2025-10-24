#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int N;
vector<pii> v;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;++i){
		int s,e;
		cin>>s>>e;
		v.push_back({s,e});
	}
	sort(v.begin(),v.end());
	int start = v[0].first;
	int time = start+v[0].second;
	for(int i=1;i<N;++i){
		if(time<=v[i].first){
			time = v[i].first+v[i].second;	
		}else{
			time+=v[i].second;
		} 
	}
	cout << time;
	return 0;
}