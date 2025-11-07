#include <bits/stdc++.h>

using namespace std;
int n,k,ret;
vector<string> v;
void solve(int idx,int vec,int cnt){
	if(cnt==k-5) {
		int sum=0;
		for(int i=0;i<n;++i){
			bool f=1;
			for(int j=4;j<v[i].size()-4;++j){
				if(vec&(1<<v[i][j]-'a')) continue;
				f=0;break;
			}
			if(f) sum++;
		}
		ret = max(ret,sum);
		return;
	}
	if(idx>=26) return;
	solve(idx+1,vec,cnt);
	if(idx=='a'-'a'||idx=='n'-'a'||idx=='t'-'a'||idx=='i'-'a'||idx=='c'-'a') return;
	solve(idx+1,vec|(1<<idx),cnt+1);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	for(int i=0;i<n;++i){
		string str;
		cin>>str;
		v.push_back(str);
	}
	if(k<5){
		cout << 0 <<'\n';
		return 0;
	}
	int vec = 0;
	vec|=(1<<'a'-'a');
	vec|=(1<<'n'-'a');
	vec|=(1<<'t'-'a');
	vec|=(1<<'i'-'a');
	vec|=(1<<'c'-'a');
	
	solve(0,vec,0);
	cout << ret <<'\n';
	return 0;
}