#include <bits/stdc++.h>

using namespace std;
const int max_n = 1000000;
int t,n;
bool a[max_n];
map<int,int> m; 
void isPrime(){
	a[1] = 1;
	for(int i=2;i<=1000;++i){
		if(a[i]) continue;
		for(int j=2*i;j<=max_n;j+=i){
			a[j]=1;
		}
	}
}
int solve(){
	m.clear();
	int ret = 0;
	for(int i=2;i<n;++i){
		if(a[i]) continue;
		if(a[n-i]) continue;
		if(m.find(i)!=m.end()||m.find(n-i)!=m.end()) continue;
		m[i]++;m[n-i]++; 
		ret++;
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	isPrime();
	cin>>t;
	while(t--){
		cin>>n;
		int e = solve();
		cout << e << '\n';
	}
	
	return 0;
} 