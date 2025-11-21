#include <bits/stdc++.h>

using namespace std;
int n,ret=1,sum=1,i=1;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	//1 6 12 18 24 ...
	cin>>n;
	if(n==1){
		cout << ret <<'\n';
		return 0;
	}
	while(true){
		ret++;
		sum+=6*i;
		if(n<=sum) break;
		i++;
	}
	cout << ret <<'\n';
	return 0;
}