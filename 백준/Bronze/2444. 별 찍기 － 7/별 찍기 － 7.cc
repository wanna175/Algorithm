#include<bits/stdc++.h>

using namespace std;
int n;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	int cnt = (2*n-1)/2;
	for(int i=1;i<n;++i){
		for(int j=0;j<cnt;++j)
			cout <<" ";
		cnt--;
		for(int j=0;j<(2*i-1);++j)
			cout <<"*";
		cout <<'\n';
	}
	for(int i=0;i<2*n-1;++i) cout <<"*";
	cout<<'\n';
	for(int i=n-1;i>0;--i){
		for(int j=0;j<=cnt;++j)
			cout <<" ";
		cnt++;
		for(int j=0;j<(2*i-1);++j)
			cout <<"*";
		cout <<'\n';
	}
	return 0;
} 