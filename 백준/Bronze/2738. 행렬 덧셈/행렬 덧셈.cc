#include <bits/stdc++.h>

using namespace std;
int n,m,a[104][104],b[104][104];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>b[i][j];
			a[i][j]+=b[i][j];
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}