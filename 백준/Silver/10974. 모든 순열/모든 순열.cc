#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A;
int main(void) {
        cin >> N;
        for (int i=0;i<N;++i)
                A.push_back(i+1);

        do {
                for (auto it = A.begin(); it != A.end(); ++it)
                        cout << *it << ' ';
                cout << '\n';
        } while(next_permutation(A.begin(),A.end()));
        return 0;
}
