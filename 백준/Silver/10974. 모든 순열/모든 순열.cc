#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> vec;
int main(void) {
        cin >> N;
        for (int i=1;i<=N;++i)
                vec.push_back(i);
        do{
                for (const auto& a : vec) {
                        cout << a <<' ';
                }
                cout << '\n';
        }while(next_permutation(vec.begin(),vec.end()));
        return 0;
}
