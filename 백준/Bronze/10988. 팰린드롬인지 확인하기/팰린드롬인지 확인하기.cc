#include <bits/stdc++.h>

using namespace std;
string s; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >>s;
	string temp = s;
	reverse(temp.begin(),temp.end());
	
	if (temp == s) cout << "1" << '\n';
	else cout << "0" << '\n';
	return 0;
} 