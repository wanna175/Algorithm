#include <bits/stdc++.h>

using namespace std;
int n,a,b;
stack<int> stk;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a;
		if(a==1){
			cin>>b;
			stk.push(b);
		}else if(a==2){
			if(stk.empty()){
				cout << -1 <<'\n';
			}else{
				b = stk.top();
				stk.pop();
				cout << b << '\n';
			}
		}else if(a==3){
			cout << stk.size() << '\n';
		}else if(a==4){
			if(stk.empty()){
				cout << 1 <<'\n';
			}else{
				cout << 0 << '\n';
			}
		}else if(a==5){
			if(stk.empty()){
				cout << -1 <<'\n';
			}else{
				cout << stk.top()<< '\n';
			}
		}
	}
	return 0;
}