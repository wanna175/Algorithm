#include <bits/stdc++.h>

using namespace std;
int N,C,pr;
vector<int> v;
map<int,int> prior;
map<int,int> m;
bool cmp(int a,int b){
	if (m[a]==m[b]) return prior[a]<prior[b];
	return m[a]>m[b];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin>>N>>C;
	for(int i=0;i<N;++i){
		int n;
		cin>>n;
		v.push_back(n);
		m[n]++;
		if(m[n]==1){
			prior[n]=pr;
			pr++;
		} 
	}
	sort(v.begin(),v.end(),cmp);
	for(int i : v){
		cout << i << " ";
	}
	cout << '\n';
	return 0;
}