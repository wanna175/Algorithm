#include <iostream>

using namespace std;
int N,F;
int ret;
int main(void) {
        cin >> N >> F;

        N = N/100*100;

        for (int i=0;i<100;++i) {
                if ((N+i)%F!=0) continue;
                ret = i;
                break;
        }
        if (ret <10) cout << "0";
        cout << ret;

        return 0;
}
