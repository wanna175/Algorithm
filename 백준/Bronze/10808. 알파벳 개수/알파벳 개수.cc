#include <bits/stdc++.h>

using namespace std;
string s;
vector<int> ret(26,0);
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>s;
	for(int i : s){
		ret[i - 'a']++;
	}
	for(int i : ret){
		cout << i << " ";
	}
	cout << '\n';
	return 0;
}