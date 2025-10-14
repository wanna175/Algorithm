#include <bits/stdc++.h>

using namespace std;
string s;
string ret;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	getline(cin,s);
	for(int i=0;i<s.size();++i){
		int n;
		if ('a'<=s[i]&&s[i]<='z'){
		    n = s[i]+13;
		    if(n>'z') n+= -1-'z'+'a';
		    ret+=(char)n;
		}
		else if('A'<=s[i]&&s[i]<='Z'){
			n = s[i]+13;
		    if(n>'Z') n+= -1-'Z'+'A';
		    ret+=(char)n;
		}else ret+=s[i];
	}
	
	cout << ret << '\n';
	return 0;
}