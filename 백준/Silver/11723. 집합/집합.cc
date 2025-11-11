#include <bits/stdc++.h>

using namespace std;
int m,n,s;
string str;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin>>m;
	for(int i=0;i<m;++i){
		cin>>str;
		if(str=="all"){
			s = (1<<20)-1;
			continue;
		}else if(str=="empty"){
			s = 0;
			continue;
		}
		cin>>n;
		if(str=="add") s|=(1<<(n-1));
		else if(str == "remove") s&=~(1<<(n-1));
		else if(str == "check"){
			if(s&(1<<(n-1))) cout << 1 <<'\n';
			else cout << 0 <<'\n';
		}else if(str=="toggle") s^=(1<<(n-1));
	}
	return 0;
}