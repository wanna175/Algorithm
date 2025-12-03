#include<bits/stdc++.h>

using namespace std;
int x,y,w,h;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>x>>y>>w>>h;
	cout << min(min(w-x,x),min(h-y,y));
	return 0;
} 