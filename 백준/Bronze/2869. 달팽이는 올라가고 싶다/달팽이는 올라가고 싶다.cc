#include <bits/stdc++.h>

using namespace std;
//typedef long long ll;
int a,b,v,ret,n;
int main(){
	cin>>a>>b>>v;
	v-=a;
	ret = v/(a-b);
	n = v%(a-b);
	if(n) ret++;
	cout << ret+1;	
	return 0;
}