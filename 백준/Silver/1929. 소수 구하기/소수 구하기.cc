#include <bits/stdc++.h>

using namespace std;
int m,n;
bool a[1000001];
vector<int> isPrime(){
	vector<int> ret;
	a[1] = 1;
	for(int i=2;i<=sqrt(n);++i){
		if(a[i]) continue;
		for(int j=2*i;j<=n;j+=i){
			a[j]=1;
		}
	}
	for(int i=m;i<=n;++i){
		if(a[i]) continue;
		ret.push_back(i);
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>m>>n;
	auto v = isPrime();
	for(auto e : v){
		cout << e << '\n';
	}
	return 0;
} 