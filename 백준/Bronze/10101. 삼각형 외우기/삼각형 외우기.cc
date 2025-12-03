#include <bits/stdc++.h>

using namespace std;
int a,b,c;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>a>>b>>c;
	
	if(a+b+c!=180) goto err;
	if(a==b&&b==c){
		cout << "Equilateral\n";
	}else if(a==b||b==c||a==c){
		cout << "Isosceles\n";
	}else{
		cout << "Scalene\n";
	}
	return 0;
	
	err:
		cout<<"Error\n";
		return 0;
}