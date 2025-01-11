#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int prime[2000], a[51];
int N;
bool isvisit[51];
int match[51];
vector<int> graph[51];
vector<int> even, odd,A,B;
vector<int> answer;
void eratos() {
	for (int i = 1; i < 2000; ++i) prime[i] = i;
	int n = (int)sqrt(2000);
	for (int i = 2; i <= n; ++i) {
		if (prime[i] == 0)continue;
		for (int j = i * 2; j < 2000; j += i)
			prime[j] = 0;
	}
}
bool dfs(int u) {
	if (u == 0) return false;

	for (int v : graph[u]) {
		if (isvisit[v]) continue;
		isvisit[v] = true;
		if (match[v] == -1 || dfs(match[v])) {
			match[v] = u;
			return true;
		}
	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	eratos();
	cin >> N;
	for (int i = 1; i <= N; ++i)cin >> a[i];

	for (int i = 1; i <= N; ++i)
		(a[i] % 2 == 0) ? even.push_back(i) : odd.push_back(i);

	if (even.size() != odd.size()) {
		cout << -1; 
		return 0;
	}
	if (a[1] % 2 == 0) {
		A = even; B = odd;
	}
	else {
		A = odd; B = even;
	}
	for (int i = 0; i < A.size(); ++i)
		for (int j = 0; j < B.size(); ++j)
			if (prime[a[A[i]] + a[B[j]]]!=0) graph[i].push_back(j);

	for (int i : graph[0]) {
		fill_n(&match[0], 51, -1);
		match[i] = 0;
		int cnt = 1;
		for (int j = 1; j < A.size(); ++j) {
			fill_n(&isvisit[0], 51, false);
			isvisit[i] = true;
			if (dfs(j)) cnt++;
		}
		if (cnt == A.size()) answer.push_back(a[B[i]]);
	}

	if (answer.size() == 0) {
		cout << -1;
		return 0;
	}
	sort(answer.begin(), answer.end());
	for (int ans : answer) cout << ans << " ";
	
	return 0;
}