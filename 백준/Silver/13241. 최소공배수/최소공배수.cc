#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a,b,ret;
ll gcd(ll a,ll b){
	if(a==0) return b;
	return gcd(b%a,a);
}
ll lcm(ll a,ll b){
	return (a*b)/gcd(a,b);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>a>>b;
	cout << lcm(a,b);
	return 0;
} 