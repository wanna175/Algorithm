#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pii;

int N; //4~50
int M; //1~10
vector<pii> virus;
int board[50][50];
int sim[50][50];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int min_ret=9999;
int cnt;
void init() {
        for (int y=0;y<N;++y)
                for (int x=0;x<N;++x)
                        sim[y][x] = board[y][x];

}
int check() {
        int ret=0;
        bool flag = false;
        for (int y=0;y<N;++y) {
                if (flag) break;
                for (int x=0;x<N;++x) {
                        if (sim[y][x]==0) {
                                flag = true;
                                ret = -1;
                                break;
                        }
                        if (-sim[y][x] > ret) ret = -sim[y][x];
                }
        }
        return ret;
}
void simulation(const vector<pii>& s) {
        int ret = -1;
        int zc=0;
        init();
        queue<pii> q;
        for (auto p : s) {
                sim[p.first][p.second] = -1;
                q.push(p);
        }

        while(!q.empty()) {
                pii cur = q.front();
                q.pop();
                for(int i=0;i<4;++i) {
                        pii next = make_pair(cur.first+dy[i],cur.second+dx[i]);
                        if (next.first<0 || next.first>=N || next.second <0||next.second>=N) continue;
                        if (sim[next.first][next.second]==1) continue;
                        if (sim[next.first][next.second]<0) continue;
                        if (sim[next.first][next.second]==0) zc++;
                        q.push(next);
                        sim[next.first][next.second] = sim[cur.first][cur.second]-1;
                }
                if (zc == cnt) break;
        }
        ret = check();
        if (ret!=-1&&min_ret > ret) min_ret = ret;

}
void select(int index, int cur, vector<pii>& s) {
        if (cur == M) {
                simulation(s);
                return;
        }

        for (int i=index;i<virus.size();++i) {
                s.push_back(virus.at(i));
                select(i+1,cur+1,s);
                s.pop_back();
        }
}
int main(void) {
        cin >> N >> M;
        bool flag = false;
        for (int y=0;y<N;++y)
                for (int x=0;x<N;++x) {
                        cin >> board[y][x];
                        if (board[y][x] == 2)
                                virus.push_back(make_pair(y,x));
                        else if (board[y][x] == 0) {
                                flag = true;
                                cnt++;
                        }
                }
        if (!flag) {
                cout << "0\n";
                return 0;
        }
        vector<pii> s;
        select(0,0,s);
        if (min_ret == 9999) min_ret = 0;
        cout << min_ret-1 << '\n';

        return 0;
}
