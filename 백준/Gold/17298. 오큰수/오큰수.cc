#include <bits/stdc++.h>

using namespace std;
int N;
stack<int> st;
vector<int> a(1000001,0);
vector<int> ret(1000001,-1);
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>a[i];
	}
	st.push(1);
	for(int i=2;i<=N;++i){
		if (a[i-1]<a[i]){
			while(!st.empty()){
				int t = st.top();
				if(a[t]<a[i]){
					ret[t] = a[i];
					st.pop();
				}else break;
			}
		}
		st.push(i);
	}   
	for(int i=1;i<=N;++i) cout << ret[i]<< " "; 
	return 0;
}