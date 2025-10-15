#include <bits/stdc++.h>

using namespace std;
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	while(true){
		cin>>n;
		if(cin.eof())break;
		int i=1;
		int ret=1;
		while(true){
			if(i%n==0) break;
			i = 10*i +1;
			i%=n;
			ret++;
		}
		cout << ret << '\n';
	}
	return 0;
}