#include <bits/stdc++.h>

using namespace std;
int x,i;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>x;
	while(true){
		i++;
		if(i*(i+1)/2 >= x) break;
	}
	x-=i*(i-1)/2;//x번째 
	//sum = i+1
	if(i%2==0) cout << x << "/" << i+1 -x <<'\n';
	else cout << i+1 -x << "/" << x <<'\n';
	return 0;
}