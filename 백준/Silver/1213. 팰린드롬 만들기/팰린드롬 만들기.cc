#include <bits/stdc++.h>

using namespace std;
string s,ret,tmp = "";
char c = 'a';
int cnt;
vector<int> v(26,0);
const string sorry = "I'm Sorry Hansoo";
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	
	cin>>s;
	
	for(char c : s){
		v[c-'A']++;	
	} 
	for(int i=0;i<26;++i){
		if(v[i]%2!=0){
			if(c != 'a'){
				cout << sorry << '\n';
				return 0;
			}
			c=('A'+i);
		}
		for(int j=0;j<v[i]/2;++j) ret+=('A'+i);	
		
	}
	string rev = ret;
	reverse(rev.begin(),rev.end());
	if(c!='a') ret+=c;
	ret+=rev;
	cout << ret << '\n';
	return 0;
}