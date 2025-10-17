#include <bits/stdc++.h>

using namespace std;
int T;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>T;
	while(T!=0){
		T--;
		string s;
		bool f = false; 
		cin>>s;
		stack<char> stk;
		for(char c:s){
			if(stk.empty()){
				if(c==')'){
					f=true;
					break;	
				}
				stk.push(')');
			}else{
				if(stk.top() == c) stk.pop();
				else stk.push(')');
			}

		}
		if(!stk.empty()||f) cout<<"NO\n";
		else cout << "YES\n";
		
	}
	
	return 0;
} 