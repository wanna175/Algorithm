#include <bits/stdc++.h>

using namespace std;
int n;
bool a[1000001];
void isPrime(){
	a[1] = 1;
	for(int i=2;i<=sqrt(2*123456);++i){
		if(a[i]) continue;
		for(int j=2*i;j<=2*123456;j+=i){
			a[j]=1;
		}
	}
}
int solve(){
	int ret = 0;
	for(int i=n+1;i<=2*n;++i){
		if(a[i]) continue;
		ret++;
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	isPrime();
	while(1){
		cin>>n;
		if(n==0) break;
		int e = solve();
		cout << e <<'\n';
	}
	
	return 0;
} 