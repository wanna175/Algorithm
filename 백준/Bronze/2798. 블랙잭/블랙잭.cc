#include <iostream>
#include <string>

using namespace std;

int main(void) {
        int N, M;
        int card[101];

        cin >> N >> M;
        for(int i=0; i<N; ++i)
                cin >> card[i];

        int ret = -1;
        for(int i=0; i<N; ++i) {
                for(int j=i+1; j<N; ++j) {
                        for(int k=j+1; k<N; ++k){
                                int val = card[i] + card[j] + card[k];
                                if (val > M)   continue;
                                if (val > ret) ret = val;                 
                        }
                }
        }
        cout << ret;
         
        return 0;
}
