#include <iostream>
#include <string>
using namespace std;

int main(void) {
        int N, K;
        int ret = 0;

        cin >> N >> K;

        for (int i=1; i <= N; ++i) {
                if (N % i == 0) --K;
                if (K == 0){
                        ret = i;
                        break;
                }
        }
        cout << ret;
        return 0;
}
