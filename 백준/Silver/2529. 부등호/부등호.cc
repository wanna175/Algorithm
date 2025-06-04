#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N; // 2~9
char k[9];
int n[10];
bool is_visit[10];
long long min_ret = 9999999999 ,max_ret = -1;
void calc(const vector<int>& v) {
        long long ret = 0;
        for (const int i : v) {
                ret+=i;
                ret*=10;
        }
        ret/=10;

        if (max_ret < ret) max_ret = ret;
        if (min_ret > ret) min_ret = ret;
}
void select(int n, vector<int>& sel) {
        if (n == N+1) {
                calc(sel);
                return;
        }
        for (int i=0;i<10;++i) {
                if (is_visit[i]) continue;
                if (n>0) {
                        switch(k[n-1]) {
                                case '>':
                                        if (sel.back() < i) continue;
                                        break;
                                case '<':
                                        if (sel.back() > i) continue;
                                        break;
                        }
                }
                is_visit[i] = true;
                sel.push_back(i);
                select(n+1, sel);
                sel.pop_back();
                is_visit[i] = false;
        }
}
int main(void) {
        int div=1;
        cin >> N;
        for (int i=0;i<N;++i) {
                div*=10;
                cin >> k[i];
        }

        vector<int> sel;
        select(0,sel);
        
        if (max_ret / div == 0)
                cout << '0' <<max_ret << '\n';
        else cout << max_ret << '\n';

        if (min_ret / div == 0)
                cout << '0' <<min_ret << '\n';
        else cout <<  min_ret << '\n';
        return 0;
}
