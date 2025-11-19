#include <bits/stdc++.h>

using namespace std;
string s;
int cnt;
char ret;
map<char,int> m;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin >> s;
	for(int i=0;i<s.size();++i){
		if(s[i]>'Z') s[i]-=32;
		m[s[i]]++;
	}
	for(auto e : m){
		if(cnt < e.second){
			cnt = e.second;
			ret = e.first;
		}else if (cnt == e.second){
			ret = '\?';
		}
	}
	cout << ret <<'\n';
	return 0;
}