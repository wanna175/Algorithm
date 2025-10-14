#include <bits/stdc++.h>

using namespace std;
vector<int> v;
bool flag = false;
vector<int> ret;
void combi(int start,int r, vector<int> b){
	if (flag) return;
	if(r == b.size()){
		//logic
		int sum = 0;
		for(int i : b){
			sum+=v[i];
		}
		if (sum == 100){
		    flag = true;
		    for(int i : b){
		        ret.push_back(v[i]);	
			}
		    
		}
		return;
	}
	for(int i = start+1;i<v.size();++i){
		b.push_back(i);
		combi(i,r,b);
		b.pop_back();
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i=0;i<9;++i){
		int n;
		cin>>n;
		v.push_back(n);
	}
	sort(v.begin(),v.end());
	vector<int> b;
	combi(-1,7,b);
	for(int i : ret){
		cout << i << '\n';
	}
	return 0;
} 