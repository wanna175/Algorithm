#include <iostream>
#include <cstring>

using namespace std;
int d(int n) {
        int ret = n;
        while(n!=0) {
                int remain = n%10;
                n/=10;
                ret += remain;
        }
        return ret;
}

int main(void) {
        bool c[10001];

        memset(c, 0, sizeof(c));

        for(int i=1; i<10001; ++i) {
                if (c[i] != 0) continue;
                int next = i;
                while(true) {
                        next = d(next);
                        if (next > 10000) break;
                        c[next] = true;
                }
        }

        for(int i=1; i<10001; ++i) {
                if (c[i] == false)
                        cout << i << '\n';
        }

        return 0;
}
