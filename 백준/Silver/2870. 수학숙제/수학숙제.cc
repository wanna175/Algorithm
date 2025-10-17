#include <bits/stdc++.h>

using namespace std;
int N;
vector<string> v;
bool cmp(string a,string b){
	if(a.size()==b.size()) return a<b;
	return a.size()<b.size();
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	
	cin>>N;
	for(int i=0;i<N;++i){
		string s,tmp="";
		cin>>s;
		for(int j=0;j<s.size();++j){
			if('0'>s[j]||s[j]>'9'){
				if(tmp.size()!=0){
					v.push_back(tmp);
					tmp="";
				}
				continue;
			}
			if(tmp.size()==1&&tmp[0]=='0') tmp="";
			tmp+=s[j];
		}
		if(tmp.size()==0) continue;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end(),cmp);
	for(string i:v){
		cout << i << '\n';
	}
	return 0;
}