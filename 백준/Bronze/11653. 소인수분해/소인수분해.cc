#include <bits/stdc++.h>

using namespace std;
const int max_n = 10000000;
int n;
bool che[max_n+1];
void isPrime(){
	che[1]=1;
	for(int i=2;i<=sqrt(n);++i){
		if(che[i]) continue;
		for(int j=2*i;j<=n;j+=i){
			che[j] = 1;
		}
	}
	
} 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	if(n==1) return 0;
	isPrime();
	
	while(che[n]){
		for(int i=2;i<=n;++i){
			if(che[i]) continue;
			if(n%i) continue;
			n/=i;
			cout << i <<'\n';
			break;
		}
	}
	cout << n << '\n';
	
	
	return 0;
}