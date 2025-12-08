#include <bits/stdc++.h>

using namespace std;
string n;
int a[10];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	
	for(int i=0;i<n.size();++i){
		a[n[i]-'0']++;
	}
	for(int i=9;i>=0;--i){
		for(int j=0;j<a[i];++j){
			cout << i;
		}
	}
	
	return 0;
}