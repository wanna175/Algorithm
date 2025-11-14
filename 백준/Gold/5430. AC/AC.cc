#include <bits/stdc++.h>

using namespace std;
int t,n,head,tail;
string p,str;
bool f;
vector<int> split(const string& input,string delimiter){
	vector<int> ret;
	if(!input.size()) return ret;
	auto start = 0;
	auto end = input.find(delimiter);
	while(end != string::npos){
		ret.push_back(stoi(input.substr(start,end-start)));
		start = end+delimiter.size();
		end = input.find(delimiter,start);
	} 
	ret.push_back(stoi(input.substr(start)));
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	while(t--){
		cin>>p>>n>>str;
		vector<int> v = split(str.substr(1,str.size()-2),",");
		head = 0;tail=n;f=0;
		for(int i=0;i<p.size();++i){
			if(p[i]=='R'){
				if(head>tail){
					head++;tail++;
				}
				else{
					head--;tail--;
				}
				swap(head,tail);
			}else{
				if(head == tail){
					f=1;break;
				}
				else if(head>tail) head--;
				else head++;
			}
		}
		if(f){
			cout << "error\n";
			continue;
		}
		string ret = "[";
		if(head>tail){
			for(int i = head;i>tail;--i){
				ret+=to_string(v[i])+",";
			}
		}
		else {
			for(int i = head;i<tail;++i){
				ret+=to_string(v[i])+",";
			}
		}
		if(ret.size()!=1) ret.pop_back();
		ret+="]\n";
		cout << ret;
	}
	return 0;
}