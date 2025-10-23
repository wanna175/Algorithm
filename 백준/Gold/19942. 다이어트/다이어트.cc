#include <bits/stdc++.h>

using namespace std;
const int INF = 1e8;
int N,mp,mf,ms,mv,ret = INF,bits;
int a[20][5];
bool cmp(int a,int b){
	int sa=0,sb=0,ta =a , tb=b;
	while(true){
		if(ta==0) return 0;
		if(tb==0) return 1;
		sa = ta%2;
		sb = tb%2;
		ta/=2;
		tb/=2;
		if(sa==1&&sb!=1)return 0;
		if(sa!=1&&sb==1)return 1;
	}

	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>N;
	cin>>mp>>mf>>ms>>mv;
	for(int i=0;i<N;++i){
		cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4];
	}
	for(int i=0;i<(1<<N);++i){
		int sp=0,sf=0,ss=0,sv=0,price = 0;
		for(int j=0;j<N;++j){
			if(i&(1<<j)){
				sp+=a[j][0];
				sf+=a[j][1];
				ss+=a[j][2];
				sv+=a[j][3];
				price+=a[j][4];
			}
		}
		if(mp>sp||mf>sf||ms>ss||mv>sv) continue;
		if(ret>price){
			ret=price;
			bits = i;
			if(bits == 0) break;
		}else if(ret == price){
			if(cmp(bits,i)) bits = i;
		}
	}
	if(ret == INF){
		cout << -1 <<'\n';
		return 0;
	}
	cout << ret << '\n';
	for(int i=0;i<N;++i){
		if(bits&(1<<i)){
			cout<< i+1 << " ";
		}
	}
	cout <<'\n';
	return 0;
}