#include <bits/stdc++.h>

using namespace std;
int ret;
string s,tmp;
map<string,int> m;
string split(const string& input, string delimiter){
	string ret="";
	auto start=0;
	auto end = input.find(delimiter);
	while(end!=string::npos){
		ret += input.substr(start,end-start)+" ";
		start = end+delimiter.size();
		end = input.find(delimiter,start);
		m[delimiter]++;
	}
	ret += input.substr(start);
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>> s;
	tmp = split(s,"dz=");
	tmp = split(tmp,"lj");
	tmp = split(tmp,"nj");
	tmp = split(tmp,"c=");
	tmp = split(tmp,"c-");
	tmp = split(tmp,"d-");
	tmp = split(tmp,"s=");
	tmp = split(tmp,"z=");
	for(int i=0;i<tmp.size();++i){
		if(tmp[i]==' ') continue;
		m["a"+tmp[i]]++;
	}
	for(auto e : m){
		ret+=e.second;
	}
	cout << ret <<'\n';
	return 0;
}