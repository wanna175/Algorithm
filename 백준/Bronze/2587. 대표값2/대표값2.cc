#include <bits/stdc++.h>

using namespace std;
int n;
int avg;
vector<int> v;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	
	for(int i=0;i<5;++i){
		cin>>n;
		v.push_back(n);
	}
	sort(v.begin(),v.end());
	int sum = accumulate(v.begin(),v.end(),0);
	avg = sum/5;
	cout << avg <<'\n' << v[2];
	
	return 0;
} 