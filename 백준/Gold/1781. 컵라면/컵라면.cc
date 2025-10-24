#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int N,ret;//200000
vector<pii> a;
priority_queue<int> pq;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;++i){
		int d,n;
		cin>>d>>n;
		a.push_back({d,n});
	}
	sort(a.begin(),a.end(),greater<pii>());

	int j=0;
	for(int i=N;i>0;--i){
		while(j<N&&i<=a[j].first){
			pq.push(a[j].second);j++;
		}
		if(pq.size()){
			ret+=pq.top();pq.pop();	
		}
	}
	cout << ret; 
	return 0;
}