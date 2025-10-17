#include <bits/stdc++.h>

using namespace std;
int N;
int s1,s2,t1,t2;
map<int,int> m;
int main(){
	
	cin>>N;
	for(int i=0;i<N;++i){
		int t;
		cin>>t;
		string s;
		cin>>s;
		int min = stoi(s.substr(0,2));
		int sec = stoi(s.substr(3));
		
		int time = min*60+sec;
		m[time] = t;
	}
	for(int i=0;i<48*60;++i){
		if(m.find(i)!=m.end()){
			if(m[i] == 1) s1++;
			else s2++;
		}
		if(s1>s2) t1++;
		else if(s1<s2) t2++;
		
	}
	printf("%02d:%02d\n",t1/60,t1%60);
	printf("%02d:%02d",t2/60,t2%60);

	return 0;
}