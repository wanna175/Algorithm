#include <iostream>
#include <set>
#include <climits>
using namespace std;

int N;         // 4~20
int S[21][21]; // 1~100
int team;
int min_ret = INT_MAX;
void calc(const set<int>& sel) {
        int ret = 0;
        set<int> a, b;
        for (int i = 1; i <= N; ++i) {
                if (sel.find(i) != sel.end())
                        a.insert(i);
                else
                        b.insert(i);
        }
        for (auto& i : a) {
                for (auto& j : a) ret+=S[i][j];
        }
        for (auto& i : b) {
                for (auto& j : b) ret-=S[i][j];
        }
        ret = ret > 0 ? ret : -ret;
        if (min_ret > ret) min_ret = ret;
}
void select(int n, set<int>& sel, int stInd) {
        if (n >= team) {
                calc(sel);
                return;
        }
        if (team-n > N-stInd)
                return;
        for (int i = stInd; i <= N; ++i) {
                if (sel.find(i)!= sel.end()) continue;
                sel.insert(i);
                select(n+1, sel, i+1);
                sel.erase(i);
        }
}
int main(void) {
        cin >> N;
        for (int i=1; i<=N; ++i) {
                for (int j=1; j<=N; ++j)
                        cin >> S[i][j];
        }
        team = N/2;
        set<int> sel;
        select(0, sel,1);

        cout << min_ret << endl;

        return 0;
}
