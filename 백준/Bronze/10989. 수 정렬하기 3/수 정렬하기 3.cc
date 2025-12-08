#include <bits/stdc++.h>

using namespace std;
int n,a;
int v[10001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a;v[a]++;
	}
	for(int i=1;i<10001;++i){
		for(int j=0;j<v[i];++j){
			cout <<i << '\n';
		}
	}
	
	return 0;
}