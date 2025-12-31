#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int n,k;
int w,v,c;
ll ret;
vector<int> b;
vector<pii> m;
priority_queue<int> pq;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>w>>v;
		m.push_back({w,v});
	}
	for(int i=0;i<k;++i){
		cin>>c;
		b.push_back(c);
	}
	sort(m.begin(),m.end());
	sort(b.begin(),b.end());
	int j=0;
	for(int i=0;i<k;++i){
		while(j<n&&m[j].first<=b[i]) pq.push(m[j++].second);
		if(pq.empty()) continue;
		ret+=pq.top();pq.pop();	
	}
	cout << ret;
	return 0;
} 