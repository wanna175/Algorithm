#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
long long N;
int T;
int main(void) {
        cin >> T;
        vector<long long> v;
        for (int i=1;i<=T;++i) {
                cin>>N;
                if (N == 0 || N == 1) {
                        v.push_back(2);
                        continue;
                }
                bool flag = true;
                do{
                        flag = true;
                        for (long long i=2;i<=sqrt(N);++i) {
                                if (N%i==0) {
                                        N++;
                                        flag = false;
                                        break;
                                }
                        }
                }while(!flag);
                v.push_back(N);

        }

        for (auto a : v)
                cout << a <<'\n';
        return 0;
}
