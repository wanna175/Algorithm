#include <iostream>
#include <vector>

using namespace std;
int N[9];
bool calc(int i, int j) {
        int ret = 0;

        for (int u=0;u<9;++u) {
                if (u==i ||u==j) continue;
                ret+=N[u];
        }
        if (ret ==100) {
                N[i] = N[j] = 0;
                return true;
        }
        return false;
}
int main(void) {
        for (int i=0;i<9;++i)
                cin >> N[i];

        bool flag = false;
        for (int i=0;i<9&&!flag;++i)
                for (int j=i+1;j<9&&!flag;++j)
                        flag = calc(i,j);

        for (int i=0;i<9;++i) {
                if (N[i] == 0) continue;
                cout << N[i] << endl;
        }
        return 0;
}
