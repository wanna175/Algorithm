#include <bits/stdc++.h>

using namespace std;

int N,ret = -987654321;
vector<int> n;
vector<char> op;
string s;
int oper(char c, int a, int b){
	if(c=='+') return a+b;
	if(c=='-') return a-b;
	if(c=='*') return a*b;
}
void solve(int idx,int sum){
	if(idx == n.size()-1){
		ret = max(ret,sum);
		return;
	}
	solve(idx+1,oper(op[idx],sum,n[idx+1]));
	if(idx+2 <=n.size()-1){
		int tmp = oper(op[idx+1],n[idx+1],n[idx+2]);
		solve(idx+2,oper(op[idx],sum,tmp));
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>N;
	cin>>s;
	for(int i = 0;i<N;++i){
		if(i%2==0)n.push_back(s[i]-'0');
		else op.push_back(s[i]);
	}
	solve(0,n[0]);
	cout << ret << '\n';
	return 0;
}