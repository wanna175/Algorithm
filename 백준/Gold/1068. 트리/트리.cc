#include <bits/stdc++.h>

using namespace std;
int N,root,e,ret;
vector<int> t[50];
void DFS(int v){
	if(t[v].size() ==0||
		(t[v].size()==1&&t[v][0]==e)){
			ret++;
			return;
		}
	for(int u:t[v]){
		if(u==e) continue;
		DFS(u);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for(int i=0;i<N;++i){
		int p;
		cin >> p;
		if(p != -1)
			t[p].push_back(i);
		else root = i;
	}
	cin>>e;
	if(root!=e) 
		DFS(root);
	cout << ret << '\n';
	return 0;
}