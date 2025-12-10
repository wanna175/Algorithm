#include <bits/stdc++.h>

using namespace std;
int a,b,c,d,tmp;
int gcd(int a,int b){
	if(a==0) return b;
	return gcd(b%a,a);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>a>>b>>c>>d;
	
	int ret1 = a*d+b*c;
	int ret2 = b*d;
	
	tmp = gcd(ret1,ret2);
	cout << ret1/tmp <<" "<<ret2/tmp;
	return 0;
}