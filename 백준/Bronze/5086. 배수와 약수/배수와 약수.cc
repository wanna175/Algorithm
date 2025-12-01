#include <bits/stdc++.h>

using namespace std;
int a,b;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	while(1){
		cin>>a>>b;
		if(a==0&&b==0) break;
		
		if(a>b){
			int sum=b;
			for(int i=1;i<10000;++i){
				sum+=b;
				if(sum==a){
					cout << "multiple\n";
					break;
				}else if(sum>a){
					cout << "neither\n";
					break;
				}
			}
		}else{
			int sum=a;
			for(int i=1;i<10000;++i){
				sum+=a;
				if(sum==b){
					cout << "factor\n";
					break;
				}else if(sum>b){
					cout << "neither\n";
					break;
				}
			}
		}
	}
	return 0;
}