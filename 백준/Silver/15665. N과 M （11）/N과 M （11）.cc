#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
using namespace std;
map<int,int> arr;
vector<int> keys;
int N, M;
void backtracking(int n,string str) {
	if (n == M) {
		for (int i = 0; i < keys.size(); ++i) {
			cout << str + to_string(keys[i]) << "\n";
		}
		return;
	}
	for (int i = 0; i < keys.size(); ++i) {
		backtracking(n + 1,str+ to_string(keys[i]) + " ");
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		if(arr.find(n)==arr.end())
			keys.push_back(n);
		arr[n]++;
	}
	sort(keys.begin(), keys.end());

	backtracking(1,"");
	return 0;
}