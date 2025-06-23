#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <cstring>
using namespace std;
int N;
int p[11];
bool sel[11];
vector<int> adj[11];
int min_ret = 99999;
bool check(int f, set<int> se) {
        if (se.size()==0) return false;
        queue<int> q;
        q.push(f);
        se.erase(f);

        while(!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int nxt : adj[cur]) {
                        if (se.find(nxt)==se.end()) continue;
                        se.erase(nxt);
                        q.push(nxt);
                }
        }
        if (se.size()!=0) return false;
        return true;
}
void calc() {
        set<int> a,b;
        int i_a=-1,i_b=-1;
        int ret = 0;
        for (int i=1;i<=N;++i) {
                if (sel[i]) {
                        i_a = i;
                        ret+=p[i];
                        a.insert(i);
                }
                else {
                        i_b = i;
                        ret-=p[i];
                        b.insert(i);
                }
        }
        bool b_a = check(i_a,a);
        if (!b_a) return;
        bool b_b = check(i_b,b);
        if (!b_b) return;

        ret = abs(ret);
        if (ret < min_ret) min_ret = ret;
}
void select(int cur) {
        if (cur == N+1) {
                calc();
                return;
        }

        select(cur+1);

        sel[cur] = true;
        select(cur+1);
        sel[cur] = false;
}
int main(void) {
        cin >> N;
        for (int i=1;i<=N;++i)
                cin >> p[i];
        for (int i=1;i<=N;++i) {
                int n;
                cin >> n;
                for (int j=0;j<n;++j) {
                        int a;
                        cin >> a;
                        adj[i].push_back(a);
                }
        }
        sel[1] = true;
        select(2);
        if (min_ret == 99999) cout << "-1";
        else
                cout << min_ret << '\n';
        return 0;
}
