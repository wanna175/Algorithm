#include <bits/stdc++.h>

using namespace std;

int N;
bool flag = false;
const string str = "PREDAJA"; 
vector<int> v(26,0);
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;++i){
		string s;
		cin>>s;
		v[s[0]-'a']++;
	}
	for(int i =0;i<26;++i){
		if (v[i] >=5){
		   cout << (char)('a'+i);
		   flag = true;
		}
	}
	if (!flag) cout << str; 
	cout << '\n';
	return 0;
} 