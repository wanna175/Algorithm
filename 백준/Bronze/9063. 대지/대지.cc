#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n;
int y[100000],x[100000];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>y[i]>>x[i];
	}
	int w = *max_element(y,y+n) - *min_element(y,y+n);
	int h = *max_element(x,x+n) - *min_element(x,x+n);
	cout << w*h;
	return 0;
}