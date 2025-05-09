#include <iostream>
#include <string>
using namespace std;

int main(void) {
        int N;
        int weight[51], height[51];
        int ret[51];

        cin >> N;
        for (int i=1; i<=N; ++i)
                cin >> weight[i] >> height[i];

        for (int i=1; i<=N; ++i){
                ret[i] = 1;
                for(int j=1; j<=N; ++j){
                        if (i == j) continue;
                        if (weight[i] >= weight[j]) continue;
                        if (height[i] >= height[j]) continue;
                        ret[i]++;
                }

        }

        for (int i=1; i<=N; ++i) {
                cout << ret[i] << " ";
        }

        return 0;
}
