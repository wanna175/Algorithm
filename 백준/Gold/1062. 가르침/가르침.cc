#include <iostream>
#include <vector>
using namespace std;
int N,K;
int ret;
bool alpha[26];
vector<string> v;
void calc(const vector<int>& sel) {
        int cal=0;
        for (const string& s : v) {
                bool flag = true;
                for (int i=4;i<s.length()-4;++i) {
                        if (!alpha[s[i]-'a']) flag = false;
                        if (!flag) break;
                }
                if (flag) cal++;
        }
        if (ret < cal) ret = cal;
}
void select(int cur,vector<int>& sel,int next) {
        if (cur == K) {
                calc(sel);
                return;
        }
        for (int i = next;i<26;++i) {
                if (alpha[i]) continue;
                alpha[i] = true;
                sel.push_back(i);

                select(cur+1,sel,i+1);

                alpha[i] = false;
                sel.pop_back();
        }
}
int main(void) {
        cin >> N >> K;
        for (int i=0;i<N;++i) {
                string str;
                cin >> str;
                v.emplace_back(str);
        }
        if (K < 5) {
                cout << "0" << endl;
                return 0;
        }else {
                alpha['a'-'a'] = true;
                alpha['t'-'a'] = true;
                alpha['n'-'a'] = true;
                alpha['i'-'a'] = true;
                alpha['c'-'a'] = true;
                K-=5;
        }
        vector<int> v;
        select(0,v,0);

        cout << ret << '\n';

        return 0;
}
