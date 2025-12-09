#include <bits/stdc++.h>

using namespace std;
string str;
set<string> s;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>str;
	for(int i=1;i<=str.size();++i){
		for(int j=0;j<=str.size()-i;++j){
			s.insert(str.substr(j,i));
		}
	}
	cout <<s.size();
	return 0;
} 