#include <bits/stdc++.h>

using namespace std;
int N,L,ret;
int a[104][104],visited[104];

void check(){
	for(int i=0;i<N;++i){
		fill(&visited[0],&visited[0]+104,0);
		bool flag = 0;
		for(int j=0;j<N-1;++j){
			if(a[i][j]==a[i][j+1]){
				continue;
			}
			else if(a[i][j]==a[i][j+1]+1){
				int start = a[i][j+1];
				if(j+L>=N){
					flag = 1;
					break;
				}
				for(int l=1;l<=L;++l){			
					if(a[i][j+l] != start){
						flag = 1;
						break;
					}
					visited[j+l] = 1;
				}
				if(flag) break;
			}
			else if(a[i][j]==a[i][j+1]-1){
				int start = a[i][j];
				if(j-L+1<0){
					flag = 1;
					break;
				}
				for(int l=0;l<L;++l){			
					if(a[i][j-l] != start||visited[j-l]){
						flag = 1;
						break;
					}
					visited[j-l] = 1;
				}
				if(flag) break;
			}
			else {
				flag = 1;
				break;
			}
		}
		if(!flag) ret++;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>N>>L;
	
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>a[i][j];
		}
	}
	check();
	//대각반전 
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			swap(a[i][j],a[j][i]);
		}
	}
	check();
	cout << ret << '\n';
	return 0;
}