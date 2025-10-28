#include <bits/stdc++.h>

using namespace std;
int N,K;
int a[2][500001];
int solve(){
	queue<int> q;
	q.push(N);
	a[0][N] = 1;
	int time = 1;
	while(q.size()){
		K+=time;
		if(K>500000) return -1;
		if(a[time%2][K]) return time;
		int qsize = q.size();
		for(int i=0;i<qsize;++i){
			int cur = q.front();q.pop();
			for(int next : {cur+1,cur-1,cur*2}){
				if(next<0||next>=500001) continue;
				if(a[time%2][next])	continue;
				a[time%2][next] = 1;
				if(K == next) return time;	
				q.push(next);
			}
		}
		time++;		
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>N>>K;
	if(N==K){
		cout << 0 <<'\n';
		return 0;
	}
	int ret = solve();
	cout << ret << '\n';
	return 0;
}