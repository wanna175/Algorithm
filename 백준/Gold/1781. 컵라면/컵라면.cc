#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int n,d,a,ret;
vector<pii> v;
priority_queue<int> pq;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>d>>a;
		v.push_back({d,a});
	}
	sort(v.begin(),v.end(),greater<pii>());
	int i=0;
	for(int day=n;day>0;--day){
		while(i<n&&day<=v[i].first) pq.push(v[i++].second);
		if(pq.size()){
			ret+=pq.top();
			pq.pop();
		}
	}
	cout << ret;
	return 0;
}