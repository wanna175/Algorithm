#include <iostream>
#include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int i=0;i<T;++i){
        string s;
        int R;
        cin>>R>>s;
        for(int j=0;j<s.size();++j)
            for(int k=0;k<R;++k){
                cout<<s[j];
            }
        cout<<'\n';
    }
    return 0;
}