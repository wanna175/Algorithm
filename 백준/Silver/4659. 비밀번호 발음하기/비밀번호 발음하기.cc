#include <bits/stdc++.h>

using namespace std;
vector<int> v(26,0);
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	
	while(true){
		string s;
		bool f = false;
		cin>>s;
		if(s == "end") break;
		
		fill(&v[0],&v[0]+26,0);
		int seq_m = 0;
		int seq_j = 0;
		char prevc ='A';
		for(char c : s){
			v[c-'a']++;
			if(prevc == c){
				if(c!='e'&&c!='o'){
					f=true;
					break;
				} 
			}else prevc = c;
			if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
				seq_m++;
				seq_j=0;
			}
			else{
				seq_j++;
				seq_m=0;
			}
			if(seq_j==3||seq_m==3) {
				f = true;
				break;
			}
				
		}
		if(v['a'-'a']+v['e'-'a']+v['i'-'a']+v['o'-'a']+v['u'-'a']==0)
			f=true;
			
		if(f) cout << "<"<<s<<"> is not acceptable."<<'\n';
		else cout << "<"<<s<<"> is acceptable."<<'\n';
	}
	return 0;
}