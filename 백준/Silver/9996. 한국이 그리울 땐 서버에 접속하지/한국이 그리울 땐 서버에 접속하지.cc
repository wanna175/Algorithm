#include <bits/stdc++.h>

using namespace std;
int N;
string s;
vector<string> split(const string& input, string delimiter){
	vector<string> ret;
	auto start = 0;
	auto end = input.find(delimiter);
	while(end!=string::npos){
		ret.push_back(input.substr(start,end));
		start = end+delimiter.size();
		end = input.find(delimiter,start);
	}
	ret.push_back(input.substr(start));
	return ret;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>N;
	cin>>s;
	vector<string> v = split(s,"*");
	reverse(v[1].begin(),v[1].end());
	for(int i=0;i<N;++i){
		string str;
		cin>>str;
		if(str.size() < v[0].size() + v[1].size()){
			cout << "NE" << '\n';
			continue;
		}
		if(v[0] != str.substr(0,v[0].size())){
			cout << "NE" << '\n';
			continue;
		}
		reverse(str.begin(),str.end());
		if(v[1]!= str.substr(0,v[1].size())){
			cout << "NE" << '\n';
			continue;
		}
		cout << "DA" << '\n';
	}
	return 0;
}