#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
string tmp;
string sea;
int ret;
int main(void) {
        getline(cin,tmp);
        getline(cin,sea);

        int size = sea.size();
        int i = 0;

        while(true) {
                auto next = tmp.find(sea,i);
                if (next == string::npos) break;
                ++ret;
                i= next + size;    
        }
        cout << ret << '\n';
        return 0;

}
