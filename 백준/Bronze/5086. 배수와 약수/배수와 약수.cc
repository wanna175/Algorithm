#include <bits/stdc++.h>

using namespace std;
int a,b;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	while(1){
		cin>>a>>b;
		if(a==0&&b==0) break;			
		if(a>b&&a%b==0)cout << "multiple\n";
		else if(b>a&&b%a==0)cout << "factor\n";
		else cout << "neither\n";		
	}
	return 0;
}