#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
int a,b,c; 
vector<pii> v(3,{0,0});
int ret=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> a >> b >> c;
	
	for(int i=0;i<3;++i){
		int s,e;
		cin >> s >> e;
		v.push_back({s,e});
	}
	for(int i = 1;i<=100;++i){
		int cnt = 0;
		for(auto e : v){
			if(e.first<i&&e.second>=i) cnt++;
		}
		if(cnt == 1) ret+=a;
		else if(cnt == 2) ret+=2*b;
		else if(cnt == 3) ret+=3*c;
	}
	cout << ret << '\n';
	return 0;
} 