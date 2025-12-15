#include <bits/stdc++.h>

using namespace std;
deque<int> dq;
int n,a,b;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a;
		switch(a){
			case 1:
				cin>>b;
				dq.push_front(b);
				break;
			case 2:
				cin>>b;
				dq.push_back(b);
				break;
			case 3:
				if(!dq.size()){
					cout << -1 << '\n';	
				}else{
					int ret = dq.front(); 
					dq.pop_front();
					cout << ret<<'\n';
				}
				break;
			case 4:
				if(!dq.size()){
					cout << -1 << '\n';	
				}else{
					int ret = dq.back(); 
					dq.pop_back();
					cout << ret <<'\n';
				}
				break;
			case 5:
				cout << dq.size() << '\n';
				break;
			case 6:
				if(!dq.size()){
					cout << 1 << '\n';	
				}else{
					cout << 0 << '\n';
				}
				break;
			case 7:
				if(!dq.size()){
					cout << -1 << '\n';	
				}else{
					cout << dq.front() << '\n';
				}
				break;
			case 8:
				if(!dq.size()){
					cout << -1 << '\n';	
				}else{
					cout << dq.back() << '\n';
				}
				break;
			default:break;	
		}
	}
	return 0;
}