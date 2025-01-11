#include <iostream>
#include <string>

using namespace std;

int main(void){
    string str;
    int N;
    cin>>N;
    cin>>str;
    int ret=0;
    for(int i=0;i<N;++i){
        ret+=str[i]-'0';
    }
    cout<<ret;
}
