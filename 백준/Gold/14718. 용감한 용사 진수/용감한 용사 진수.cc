#include<iostream>
#include<cmath>

using namespace std;
int stats[101][3];
int N, K;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	
	for (int i = 0; i < N; ++i)
		cin >> stats[i][0] >> stats[i][1] >> stats[i][2];
	
	int minStat = 3000001;
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			for (int k = 0; k < N; ++k) {
				int cnt = 0;
				for (int e = 0; e < N; ++e) {
					if (stats[i][0] < stats[e][0]) continue;
					if (stats[j][1] < stats[e][1]) continue;
					if (stats[k][2] < stats[e][2]) continue;
					cnt++;
				}
				if (cnt == K) minStat = min(minStat, stats[i][0] + stats[j][1] + stats[k][2]);
			}
	cout << minStat;
	return 0;
}