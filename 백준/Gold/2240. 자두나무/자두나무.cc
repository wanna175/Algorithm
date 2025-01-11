#include<iostream>
#include<algorithm>
using namespace std;
int a[1002];
int d[1002][32][3];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, w;
    cin >> t >> w;
    for (int i = 1; i <= t; i++)
        cin >> a[i];

    for (int i = 1; i <= t; i++) {
        d[i][0][1] = d[i - 1][0][1] + (a[i] == 1 ? 1 : 0); //이동안하는 경우
        for (int j = 1; j <= w; j++) { // j번 이동
            if (i < j) break;
            d[i][j][1] = max(d[i - 1][j - 1][2], d[i - 1][j][1]) + (a[i] == 1 ? 1 : 0);
            d[i][j][2] = max(d[i - 1][j - 1][1], d[i - 1][j][2]) + (a[i] == 2 ? 1 : 0);
        }
    }
    int ans = 0;
    for (int j = 0; j <= w; j++)
        ans = max({ ans, d[t][j][1], d[t][j][2] });
    cout << ans;
}