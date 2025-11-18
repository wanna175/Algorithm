#include <bits/stdc++.h>

using namespace std;
int n,ret,cnt;
string s;
vector<int> st;
int v[200001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>s;
	
	for(int i=0;i<n;++i){
		if(s[i]=='('){
			st.push_back(i);
		}else{
			if(st.empty()) continue;
			else{
				v[i]=1;
				v[st[st.size()-1]]=1;
				st.pop_back();
			}
		}
	}
	for(int i=0;i<n;++i){
		if(v[i]==1) cnt++;
		else{
			ret = max(cnt,ret);
			cnt=0;
		}
	}
	ret = max(ret,cnt);
	cout << ret <<'\n';
	return 0;
}