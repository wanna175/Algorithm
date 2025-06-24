#include <iostream>
#include <cmath>
using namespace std;
int N,M,D;
int board[16][15];
int game[16][15];
int max_ret = -1;
bool check() {
        for (int y=0;y<N;++y)
                for(int x=0;x<M;++x)
                        if (board[y][x]!=0) return true;
        return false;
}
void move(int& ret) {
        for (int y=N;y>=1;--y) {
                for (int x=0;x<M;++x){
                        if (board[y-1][x]>1) {
                                board[y-1][x] = 0;
                                ret++;
                        }
                        board[y][x] = board[y-1][x];
                }
        }
        for (int x=0;x<M;++x)
                board[0][x] = 0;
}
void attack(int ax) {
        int ny=-1,nx=-1,m_dist=D+1;
        for (int x = 0; x<M;++x) {
                for (int y=N-1;y>=0;--y) {
                        if (board[y][x]==0) continue;
                        int dist = N-y+abs(ax-x);
                        if (m_dist <= dist) continue;
                        m_dist = dist;
                        ny = y; nx = x;
                }
        }
        if (ny != -1 && nx != -1) board[ny][nx]++;
}
void init() {
        for (int y = 0;y <N;++y)
                for (int x=0;x <M;++x)
                        board[y][x] = game[y][x];

}
void start(int f,int s,int t) {
        init();
        int ret=0;
        while(check()) {
                attack(f);
                attack(s);
                attack(t);
                move(ret);
        }
        if (max_ret < ret) max_ret = ret;
}
int main(void) {
        cin >> N >> M >> D;
        for (int y = 0;y <N;++y)
                for (int x=0;x <M;++x)
                        cin >>game[y][x];

        for (int f=0;f<M;++f)
                for (int s=f+1;s<M;++s)
                        for (int t=s+1;t<M;++t)
                                start(f,s,t);

        cout << max_ret << '\n';
        return 0;
}
