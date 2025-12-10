#include<bits/stdc++.h>

using namespace std;
int n,a,tmp,ret,length;
vector<int> v,diff;
int gcd(int a,int b){
	if(a==0) return b;
	return gcd(b%a,a);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a;
		v.push_back(a);	
	}
	length = v[n-1]-v[0];
	for(int i=1;i<v.size();++i){
		diff.push_back(v[i]-v[i-1]);
	}
	tmp = diff[0];
	for(int i=0;i<diff.size();++i){
		tmp = gcd(tmp,diff[i]);
	}
	cout << length/tmp - n+1;
	
	return 0;
}