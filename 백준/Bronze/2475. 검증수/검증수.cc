#include <iostream>

using namespace std;

int main(void){
    int n,s=0;
    for(int i=0;i<5;++i){
        cin>>n;
        s+=n*n;
    }
    cout<<s%10;
    return 0;
}