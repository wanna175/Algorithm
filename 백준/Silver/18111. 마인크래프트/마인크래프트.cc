#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef pair<int,int> pii;
int N,M,B;//1~500, 0~6.4*10^7
int board[500][500];
int max_height, min_time = INT_MAX, ret_height;
void calc(int h) {
        int ret=0, time=0;
        for(int i=0;i<N;++i)
                for(int j=0;j<M;++j) {
                        int tmp = h-board[i][j];
                        ret += tmp;
                        time += (tmp >0)?tmp:-2*tmp;
                }
        if (ret > B) return;
        if (min_time > time) { 
                min_time = time; 
                ret_height = h;  
        }

}
int main(void) {
        cin >> N >> M >> B;
        for(int i=0;i<N;++i) {
                for(int j=0;j<M;++j) {
                        cin>>board[i][j];
                        if (max_height < board[i][j]) max_height = board[i][j];
                }
        }

        for(int i=max_height;i>=0;--i)
                calc(i);
        cout << min_time << ' ' << ret_height << '\n';
        return 0;
}
