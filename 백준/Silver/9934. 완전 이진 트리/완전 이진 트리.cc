#include <bits/stdc++.h>

using namespace std;
int k;
int n[1024];
vector<int> v[10];
void solve(int start,int end,int dep){
	if(start==end){
		v[dep].push_back(n[start]);
		return;
	}
	int mid = (start+end)/2;
	v[dep].push_back(n[mid]);
	//왼 
	solve(start,mid-1,dep+1);
	//오 
	solve(mid+1,end,dep+1); 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin >> k;
	int s=pow(2,k);
	for(int i=0;i<s-1;++i){
		cin>>n[i];
	}
	solve(0,s-2,0);
	for(int i=0;i<k;++i){
		for(int j=0;j<v[i].size();++j){
			cout << v[i][j] << " ";
		}
		cout << '\n';
	}
	
	return 0;
}