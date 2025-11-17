#include <bits/stdc++.h>

using namespace std;

int a[10004],b[10004],ret[10004];
string s1,s2;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>s1>>s2;
	for(int i=0;i<s1.size();++i){
		a[i] = s1[i]-'0';
	}
	for(int i=0;i<s2.size();++i){
		b[i] = s2[i]-'0';
	}
	reverse(&a[0],&a[0]+s1.size());
	reverse(&b[0],&b[0]+s2.size());
	
	int len = max(s1.size(),s2.size());
	int upper = 0;
	for(int i=0;i<len;++i){
		int c = a[i]+b[i]+upper;
		ret[i] = c%10;
		if(c/10) upper = 1;
		else upper = 0;
	}
	if(upper) ret[len++] = 1;
	for(int i=len-1;i>=0;--i){
		cout << ret[i];
	}
	cout <<'\n';
	return 0;
}