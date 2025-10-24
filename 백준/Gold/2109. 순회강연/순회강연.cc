#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int n,ret;
vector<pii> v;
priority_queue<int> pq;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;++i) {
		int d,p;
		cin>>p>>d;
		v.push_back({d,p});
	}
	sort(v.begin(),v.end(),greater<pii>());

	int j=0;
	for(int i=10001;i>0;--i){
		while(j<n&&i<=v[j].first) {
			pq.push(v[j].second);
			++j; 
		}
		if(pq.size()){
			ret+=pq.top();pq.pop();	
		}
	}
	cout << ret << '\n';	
	
	return 0;
}