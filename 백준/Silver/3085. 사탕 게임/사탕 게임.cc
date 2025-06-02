#include <iostream>

using namespace std;
int N;
int ret;
char board[50][50];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
char dc[4] = {'C','P','Z','Y'};
void check() {
        for (int c=0;c<4;++c) {
                int cnt=0;
                for (int i=0;i<N;++i) {
                        cnt=0;
                        for (int j=0;j<N;++j) {
                                if (board[i][j]!=dc[c]) {
                                        cnt=0;
                                        continue;
                                }
                                cnt++;
                                ret = max(ret,cnt);
                        }
                }
                for (int i=0;i<N;++i) {
                        cnt=0;
                        for (int j=0;j<N;++j) {
                                if (board[j][i]!=dc[c]) {
                                        cnt=0;
                                        continue;
                                }
                                cnt++;
                                ret = max(ret,cnt);
                        }
                }

        }
}
void select(int y, int x) {
        for (int i=0;i<4;++i) {
                int ny = y+dy[i];
                int nx = x+dx[i];

                if (ny < 0 || nx < 0|| ny>=N||nx>=N) continue;
                if (board[ny][nx] == board[y][x]) continue;

                char tmp = board[ny][nx];
                board[ny][nx] = board[y][x];
                board[y][x] = tmp;
                check();

                tmp = board[ny][nx];
                board[ny][nx] = board[y][x];
                board[y][x] = tmp;
        }
}
int main(void) {
        cin >> N;
        for (int i=0;i<N;++i)
                for (int j=0;j<N;++j)
                        cin >> board[i][j];

        for (int i=0;i<N;++i)
                for (int j=0;j<N;++j) {
                        select(i,j);
                }

        cout << ret << '\n';
        return 0;
}
