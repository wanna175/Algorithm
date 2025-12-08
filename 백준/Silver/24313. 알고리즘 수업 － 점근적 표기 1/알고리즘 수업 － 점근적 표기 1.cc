#include <bits/stdc++.h>

using namespace std;
int a,b,c,n;
int main(){
	cin>>a>>b>>c>>n;
	if(c>a){
		int t = b%(c-a);
		if(t>0&&n<=b/(c-a)) cout << 0;
		else if(t==0&&n<b/(c-a)) cout << 0;
		else cout << 1;
	}else if(c==a&&b<=0){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}