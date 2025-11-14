#include <bits/stdc++.h>

using namespace std;
string s;
string split(const string& input,string delimiter){
	string ret = "";
	auto start =0;
	auto end = input.find(delimiter);
	while(end!=string::npos){
		ret+=input.substr(start,end-start);
		start = end + delimiter.size();
		end = input.find(delimiter,start);
		if(delimiter != " ") ret+=" ";
	}
	ret+=input.substr(start);
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>s;
	string str = split(s,"chu");
	str = split(str,"pi");
	str = split(str,"ka");
	str = split(str," ");
	if(str.size()==0) cout << "YES\n";
	else cout <<"NO\n";
	return 0;
}