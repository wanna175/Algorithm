#include <bits/stdc++.h>

using namespace std;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	while(true){
		getline(cin,s); 
		if(s =="."){
			break;	
		}
		stack<char> stk;
		bool f = false;
		for(char c : s){
			if (c != '['&&c!=']'&&c!='('&&c!=')') continue;
			if (stk.empty()){
				if(c==')'||c==']'){
					f = true;
					break;
				}
				stk.push(c=='('?')':']');
			}
			else{
				if(stk.top() == c)stk.pop();
				else if(stk.top() == ')'&&c==']')
				{
					f = true;
					break;
				}
				else if(stk.top() == ']'&&c==')'){
					f = true;
					break;
				}
				else stk.push(c=='('?')':']');
			}
		}
		if(!stk.empty()||f) cout <<"no\n";
		else cout<<"yes\n";
	}

	return 0;
}