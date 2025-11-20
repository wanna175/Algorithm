#include <bits/stdc++.h>

using namespace std;
int a[6] = {1,1,2,2,2,8};
int ret[6];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	for(int i=0;i<6;++i){
		cin>>ret[i];
		ret[i] = a[i]-ret[i];	
	}
	for(int i=0;i<6;++i){
		cout << ret[i] << " ";
	}
	return 0;
} 