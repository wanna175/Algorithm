#include <bits/stdc++.h>

using namespace std;
int n,m,ret;
int a[5][5];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		string str;
		cin>>str;
		for(int j=0;j<m;++j){
			a[i][j] = str[j]-'0';
		}
	}
	for(int s=0;s<(1<<(m*n));++s){
		int sum=0;
		for(int i=0;i<n;++i){
			int cur=0;
			for(int j=0;j<m;++j){
				int k = i*m+j;
				if(!(s&(1<<k))){
					cur = 10*cur + a[i][j];
				}else{
					sum+=cur;
					cur=0;
				}
			}
			sum+=cur;
		}
		for(int j=0;j<m;++j){
			int cur=0;
			for(int i=0;i<n;++i){
				int k = i*m+j;
				if(s&(1<<k)){
					cur = 10*cur + a[i][j];
				}else{
					sum+=cur;
					cur=0;
				}
			}
			sum+=cur;
		}
		ret = max(ret,sum);
	}
	cout << ret << '\n';
	return 0;
} 