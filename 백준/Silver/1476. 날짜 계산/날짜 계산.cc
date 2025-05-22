#include <iostream>

using namespace std;
int E,S,M; //1~15,1~28,1~19
int ret = 1;
int main(void) {
        cin >> E >> S >> M;

        int e=1, s=1, m=1;

        while(true) {
                if (e==E && s==S && m==M) break;
                e = (e+1)>15 ? 1 : e+1;
                s = (s+1)>28 ? 1 : s+1;
                m = (m+1)>19 ? 1 : m+1;
                ++ret;
        }
        cout << ret;
        return 0;
}
