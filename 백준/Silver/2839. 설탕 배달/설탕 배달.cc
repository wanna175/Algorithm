#include <bits/stdc++.h>

using namespace std;
int n,cnt,ret;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	while(n>0){
		if(n%5==0){
			cnt+=n/5;
			n=0; 
			break;
		}
		n-=3;
		cnt++;
	}
	if(n==0){
		cout << cnt;
	}else{
		cout << -1;
	}
	
	return 0;
}