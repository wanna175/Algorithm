#include <iostream>

using namespace std;
int N; //1~10000
int M; //1~300000000
int A[10001]; //1~30000
int ret;
int main(void) {
        cin >> N >> M;
        
        for (int i=1;i<=N;++i)
            cin >> A[i];
        for (int i = 1; i < 10001; ++i) {
                int val = A[i];
                if (val == M) {ret++; continue;}
                for (int j = i+1; j < 10001; ++j) {
                        val+=A[j];
                        if (val == M) {
                                ret++;
                                break;
                        }
                }
        }
        cout << ret << endl;
        return 0;
}
