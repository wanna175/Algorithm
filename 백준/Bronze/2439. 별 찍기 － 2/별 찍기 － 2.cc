#include <iostream>
#include <string>

using namespace std;

int main(void){
    int N;
    cin>>N;
    string str;
    for(int i=1;i<=N;++i)
        str+=" ";
    for(int i=N;i>0;--i){
        str[i-1]='*';
        cout<<str<<'\n';
    }
}