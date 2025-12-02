#include <bits/stdc++.h>

using namespace std;
int m,n,sum;
bool che[10001];
vector<int> isPrime(){
	vector<int> ret;
	che[1] = 1;
	for(int i=2;i<=sqrt(n);++i){
		if(che[i]) continue;
		for(int j=2*i;j<=n;j+=i){
			che[j] = 1;
		}
	}
	for(int i=m;i<=n;++i){
		if(!che[i]) ret.push_back(i);
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>m>>n;
	vector<int> ret;
	ret = isPrime();
	if(!ret.size()){
		cout << -1;
		return 0;
	}
	for(int i=0;i<ret.size();++i){
		sum+=ret[i];
	}
	cout << sum << '\n' << ret[0];
	
	return 0;
}