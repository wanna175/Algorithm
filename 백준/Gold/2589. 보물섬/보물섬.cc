#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> pii;

int dy[4] = { 1, 0, -1,  0 };
int dx[4] = { 0, 1,  0, -1 };
int N, M;
int max_ret;
char land[50][50];
void bfs(int y, int x) {
        if (land[y][x] == 'W') return;
        int ret=0;
        int distance[50][50] = {0};
        bool is_visit[50][50] = {false};
        queue<pii> q;
        q.push(make_pair(y,x));
        is_visit[y][x] = true;

        while(!q.empty()) {
                pii cur = q.front();
                q.pop();

                for (int i=0;i<4;++i){
                        int ny = cur.first + dy[i];
                        int nx = cur.second + dx[i];
                        if (ny >= N || ny < 0 || nx >= M || nx < 0) continue;
                        if (land[ny][nx] !='L' || is_visit[ny][nx]) continue;
                        is_visit[ny][nx] = true;
                        distance[ny][nx] = distance[cur.first][cur.second]+1;
                        if (distance[ny][nx] > ret) ret = distance[ny][nx];
                        q.push(make_pair(ny,nx));
                }
        }
        if (max_ret < ret) max_ret = ret;
}
int main(void) {
        cin >> N >> M;
        for (int i=0;i<N;++i)
                for (int j=0;j<M;++j) {
                        cin >> land[i][j];
                }

        for (int i=0;i<N;++i)
                for (int j=0;j<M;++j)
                        bfs(i,j);

        cout << max_ret << '\n';
        return 0;
}
