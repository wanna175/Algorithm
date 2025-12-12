#include <bits/stdc++.h>

using namespace std;
int n,k,cur=1,cnt=0;
bool a[1001];
vector<int> v;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;

	while(v.size()!=n){
		if(a[cur]){
			cur++;
			if(cur>n) cur=1;
			continue;
		}
		if(cnt==k-1){
			v.push_back(cur);
			a[cur]=1;
			cnt=0;
		}else{
			cnt++;
			cur++;
			if(cur>n) cur=1;
		}
	}
	cout << "<";
	for(int i=0;i<n-1;++i){
		cout << v[i]<<", ";
	}
	cout << v[n-1] << ">";
	return 0;
}