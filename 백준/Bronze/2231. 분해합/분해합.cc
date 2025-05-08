#include <iostream>
#include <cstring>

using namespace std;
int d(int n) {
        int ret = n;
        while (n!=0) {
                int remain = n%10;
                n /= 10;
                ret += remain;
        }
        return ret;
}

int main(void) {
        int N;
        int ret = 0;

        cin >> N;

        for (int i=1; i<N; ++i) {
                if (N != d(i)) continue;
                ret = i;
                break;
        }

        cout << ret;
        return 0;
}
