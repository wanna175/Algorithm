#include <bits/stdc++.h>

using namespace std;
int n,a,expected=1;
string ret;
vector<int> v;
stack<int> stk;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a;
		v.push_back(a);
	}
	int i=0;
	while(1){
		if(i<n&&expected == v[i]){
			expected++;
			i++; 
		}else{
			if(!stk.empty()&&stk.top()==expected){
				stk.pop();
				expected++;
			}
			else if(i<n){
				stk.push(v[i]);
				i++;	
			}else{
				break;
			}
		}
	}
	
	if(stk.empty()) cout <<"Nice";
	else cout << "Sad";
	return 0;
}