#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
typedef vector<int> vec;
int N; //3~8
int A[8]; //-100 ~100
bool is_visit[8];
int max_ret = -1;
void calc(const vec& v) {
        int ret=0;
        for (int i=0; i<N-1; ++i) {
                ret += abs(v.at(i)-v.at(i+1));
        }
        if (ret > max_ret) max_ret = ret;
}
void select(vec& sel,int n) {
        if (n == N) {
                calc(sel);
                return;
        }
        for (int i=0; i<N; ++i) {
                if (is_visit[i]) continue;
                is_visit[i] = true;

                sel.push_back(A[i]);
                select(sel,n+1);

                is_visit[i] = false;
                sel.pop_back();
        }

}
int main(void) {
        cin >> N;
        for (int i=0;i<N;++i)
                cin >> A[i];
        vec v;
        select(v,0);

        cout << max_ret;
        return 0;
}
