#include <bits/stdc++.h>
using namespace std;
int a,b,v,r,n;
int main(){
	cin>>a>>b>>v;
	v-=a;
	r = v/(a-b);
	n = v%(a-b);
	if(n) r++;
	cout << r+1;	
	return 0;
}