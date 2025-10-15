#include <bits/stdc++.h>

using namespace std;
int N,ret;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>N;
	for(int i=0;i<N;++i){
		stack<char> st;
		string s;
		cin>>s;
		for(char c:s){
			if(!st.empty()&&st.top() == c) st.pop();
			else st.push(c);
		}
		if(st.empty()) ret++;
	}
	cout << ret << '\n';
	return 0;
} 