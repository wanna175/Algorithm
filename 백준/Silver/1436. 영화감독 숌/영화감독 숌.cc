#include <iostream>
#include <string>

using namespace std;
bool is_thrsix(int n) {
        int cnt = 0;
        while(true) {
                int cur = n%10;
                if (cur == 6) cnt++;
                else cnt =0;

                n /= 10;
                if (cnt == 3) return true;
                if (n == 0)   return false;
        }
}

int main(void) {
        int N;

        cin >> N;

        int cnt=0;

        int i=1;
        while(true) {
                if (is_thrsix(i)) cnt++;
                if (cnt == N) break;
                ++i;
        }

        cout << i ;
        return 0;
}
