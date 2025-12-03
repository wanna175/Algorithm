#include <bits/stdc++.h>

using namespace std;
int a[3][2],ret[2];
map<int,int> m;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>a[0][0]>>a[0][1];
	cin>>a[1][0]>>a[1][1];
	cin>>a[2][0]>>a[2][1];
	
	for(int i=0;i<2;++i){
		if(a[0][i] == a[1][i])ret[i] = a[2][i];
		else if(a[0][i] == a[2][i])ret[i] = a[1][i];
		else ret[i] = a[0][i];	
	}
	cout << ret[0] << " " << ret[1];
	
	return 0;
}