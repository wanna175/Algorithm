#include<iostream>
using namespace std;
int N;
int main(void){
    cin>>N;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=i;++j)
            cout<<'*';
        cout<<'\n';
    }
    return 0;
}