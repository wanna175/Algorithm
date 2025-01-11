#include <iostream>

using namespace std;

int main(void){
    int _m=-1;
    int _midx;
    for(int i=1;i<10;++i){
        int a;
        cin>>a;
        if(_m<a){
            _m = a;
            _midx=i;
        }
    }
    cout<<_m<<'\n'<<_midx;
}