#include <bits/stdc++.h>

using namespace std;
const int max_n = 1000; 
int n,num,cnt;
bool a[1004];
void isPrime(){
	a[1]=1;
	for(int i=2;i<=sqrt(max_n);++i){
		if(a[i]) continue;
		for(int j=2*i;j<=max_n;j+=i){
			a[j]=1;	
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	isPrime();
	
	for(int i=0;i<n;++i){
		cin>>num;
		if(a[num]) continue;
		cnt++;	
	}
	cout << cnt <<'\n';
	
	
	return 0;
} 