#include <bits/stdc++.h>

using namespace std;
int n,sum;
string ans;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	while(1){
		cin>>n;
		if(n==-1) break;
		
		sum=1;ans="1 + "; 
		for(int i=2;i<n;++i){
			if(n%i==0){
				sum+=i;
				ans+=to_string(i)+" + ";
			}
		}
		if(sum==n){
			cout << n << " = " << ans.substr(0,ans.size()-3) << '\n';
		}
		else{
			cout << n << " is NOT perfect.\n";
		}	
	}
	return 0;
}