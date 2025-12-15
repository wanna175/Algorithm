#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int n,a;
vector<int> ret;
deque<pii> dq;
int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a;
		dq.push_back({i+1,a});	
	}
	int next_number = dq.front().second;
	dq.pop_front();
	ret.push_back(1);
	while(!dq.empty()){
		if(next_number>0){
			for(int i=1;i<next_number;++i){
				pii tmp = dq.front();
				dq.push_back(tmp);
				dq.pop_front();
			}
			next_number = dq.front().second;
			ret.push_back(dq.front().first);
			dq.pop_front();
		}else{
			for(int i=1;i<-next_number;++i){
				pii tmp = dq.back();
				dq.push_front(tmp);
				dq.pop_back();
			}
			next_number = dq.back().second;
			ret.push_back(dq.back().first);
			dq.pop_back();
		}
	}
	for(auto e : ret){
		cout <<e << " ";
	}
	return 0;
}