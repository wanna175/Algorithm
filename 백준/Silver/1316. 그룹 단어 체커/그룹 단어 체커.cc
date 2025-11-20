#include <bits/stdc++.h>

using namespace std;
int n,ret,a[26];
string s;
char prec;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>s;
		fill(&a[0],&a[0]+26,0);
		a[s[0]-'a']++;prec=s[0];
		bool f = 0;
		for(int j=1;j<s.size();++j){
			if(prec == s[j]) continue;
			if(a[s[j]-'a']){
				f=1;
				break;
			}
			prec = s[j];
			a[s[j]-'a']++;
		}
		if(!f) ret++;
	}
	cout << ret <<'\n';
	return 0;
}