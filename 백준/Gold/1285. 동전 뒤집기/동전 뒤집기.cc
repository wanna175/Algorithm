#include <bits/stdc++.h>

using namespace std;
const int INF = 1e8;
int N,ret=INF;
int a[24];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;++i){
		string s;
		cin>>s;
		int value = 1;
		for(int j=0;j<N;++j){
			if(s[j]=='T') a[i] += value;
			value*=2;
		}
	}
	
	for(int i=0;i<(1<<N);++i){
		for(int j=0;j<N;++j){
			if(i&(1<<j)){
				a[j] = ~a[j];
			}
		}
		//열을 확인하면서 뒤집을지 말지 결정
		int sum=0;
		for(int j=0;j<N;++j){
			int cnt=0;
			for(int k=0;k<N;++k){
				if(a[k]&(1<<j)) cnt++;
			}
			if(N-cnt>cnt)sum+=cnt;
			else sum+=(N-cnt); 	
		} 
		ret = min(ret,sum);
		for(int j=0;j<N;++j){
			if(i&(1<<j)){
				a[j] = ~a[j];
			}
		}
	}
	cout << ret << '\n'; 
	return 0;
}