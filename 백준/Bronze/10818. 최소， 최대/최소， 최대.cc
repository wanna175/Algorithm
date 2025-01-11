#include <iostream>

using namespace std;

int main(void){
    int N;
    cin>>N;
    int _max=-1000001;
    int _min=1000001;
    int n;
    for(int i=0;i<N;++i){
        cin>>n;
        if(_max<n)
            _max=n;
        if(_min>n)
            _min=n;
    }
    cout<<_min<<' '<<_max;
    return 0;
}