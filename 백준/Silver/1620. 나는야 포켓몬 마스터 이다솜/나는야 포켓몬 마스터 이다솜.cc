#include <bits/stdc++.h>

using namespace std;

int N,M;//1~100000
vector<string> v;
map<string,int> m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>N>>M;
	v.push_back("-1");
	for(int i=0;i<N;++i){
		string s;
		cin>>s;
		v.push_back(s);
		m[s] = i+1;
	}
	for(int i=0;i<M;++i){
		string s;
		cin>>s;
		if(atoi(s.c_str()) == 0){
			cout << m[s] << '\n';
		}else{
			cout << v[atoi(s.c_str())] << '\n';
		}
	}
	return 0;
}