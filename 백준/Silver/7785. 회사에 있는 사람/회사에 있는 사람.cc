#include <bits/stdc++.h>

using namespace std;
int n;
string str,str2;
map<string,int> m;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>str>>str2;
		if(str2 =="enter")
			m[str] = 1;
		else
			m[str] = 0;
	}
	for(auto it = m.rbegin();it!=m.rend();it++){
		if(it->second == 0) continue;
		cout << it->first << '\n';
	}
	return 0;
} 