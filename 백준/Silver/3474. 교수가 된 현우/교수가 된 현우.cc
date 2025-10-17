#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll T,N;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	
	cin>>T;
	while(T!=0){
		--T;
		cin>>N;
		ll ret = 0;
		for(ll i=5;i<=N;i*=5){
			ret+=N/i;
		}
		cout << ret << '\n';
	}
	return 0;
}