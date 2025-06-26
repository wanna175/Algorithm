#include <iostream>
using namespace std;
int n;
int main(void) {
        while(true) {
                cin >> n;
                if (cin.eof()) break;
                int i=1;
                int ret=1;
                while(true) {
                        if (i%n==0) break;
                        i = 10*i + 1;
                        while(i>n) {i-=n;}
                        ret++;
                }
                cout << ret <<'\n';
        }
        return 0;
}
