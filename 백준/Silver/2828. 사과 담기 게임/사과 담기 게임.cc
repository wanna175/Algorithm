#include <bits/stdc++.h>

using namespace std;
int N,M,J;
int s = 1,e,ret;
vector<int> v;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>N>>M>>J;
	for(int i=0;i<J;++i){
		int a;
		cin>>a;
		v.push_back(a);
	}
	e = M;
	for(int i : v){
		if(i<s) {
			ret+=s-i;
			s = i;
			e = s+M-1;
		}
		else if(i>e) {
			ret+=i-e;
			e = i;
			s = e-M+1;
		}
	}
	cout << ret << '\n';
	return 0;
}