#include <bits/stdc++.h>

using namespace std;
int n,m,e;
int a[100001];
deque<int> dq;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>> a[i];
	}
	for(int i=1;i<=n;++i){
		cin>> e;
		if(a[i]==1) continue;
		dq.push_back(e);
	}
	cin>>m;
	for(int i=0;i<m;++i){
		cin>>e;
		dq.push_front(e);
		cout <<dq.back() << " ";
		dq.pop_back();
	}
	return 0;
}