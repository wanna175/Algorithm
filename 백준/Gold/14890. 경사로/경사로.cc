#include <bits/stdc++.h>

using namespace std;
int N,L,ret;
int a[104][104];

void check(){
	for(int i=0;i<N;++i){
		int cnt = 1;
		bool f = 0;
		for(int j=1;j<N;++j){
			if(a[i][j] == a[i][j-1]) cnt++;
			else if(a[i][j] == a[i][j-1]+1&&cnt>=L) cnt=1;
			else if(a[i][j] == a[i][j-1]-1&&cnt>=0) cnt=1-L;
			else {
				f = 1;break;
			}
		}
		if(!f&&cnt>=0) ret++;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>N>>L;
	
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>a[i][j];
		}
	}
	check();
	//대각반전 
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			swap(a[i][j],a[j][i]);
		}
	}
	check();
	cout << ret << '\n';
	return 0;
}