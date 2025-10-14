#include <bits/stdc++.h>

using namespace std;

const int MIN_INF = -1e9;

int n,k;
int sum[100004];
int ret = MIN_INF;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	for(int i=1;i<=n;++i){
		int m;
		cin>>m;
		sum[i] = sum[i-1]+m;
	}
	for(int i=k;i<=n;++i){
		int s = sum[i]-sum[i-k];
		ret = (ret<s)?s:ret;
	}
	cout << ret << '\n';
	return 0;
} 