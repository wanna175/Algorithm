#include <bits/stdc++.h>

using namespace std;
int a[3],l;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	while(1){
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		if(a[2]==0) break;
		if(a[2]>=a[0]+a[1]){
			cout<<"Invalid\n";
			continue;
		}
		if(a[0]==a[2]){
			cout << "Equilateral\n";
		}else if(a[0]==a[1]||a[1]==a[2]){
			cout << "Isosceles\n";
		}else{
			cout << "Scalene\n";
		}
	}
	return 0;
}