#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
priority_queue<int> pq;
vector<pii> v;
int n,ret,p,d;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>p>>d;
		v.push_back({d,p});
	}
	sort(v.begin(),v.end(),greater<pii>());
	int j=0;
	for(int i=10001;i>0;--i){
		while(j<n&&v[j].first>=i){
			pq.push(v[j].second);
			j++;
		}
		if(!pq.empty()){
		    ret += pq.top();
		    pq.pop();
		}
	}
	cout << ret;
	return 0;
}