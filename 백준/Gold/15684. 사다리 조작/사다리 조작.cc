#include <iostream>
#include <vector>

using namespace std;
int N,M,H;
int graph[11][31];
int next(int& i,int& j) {
        j++;
        if (j>H) {
                j=1;
                i++;
        }
        if (i>N-1) return -1;
        return 0;
}
bool calc() {
        bool ret = true;
        for (int i=1;i<=N;++i) {
                if (!ret) break;
                int cur = i;
                for (int j=1;j<=H;++j) {
                        if(graph[cur][j]==1) cur+=1;
                        else if(graph[cur][j]==-1) cur-=1;
                }
                if (cur != i) ret = false;
        }
        return ret;
}
bool select(int cur, int dep,int i,int j) {
        if (cur == dep)
                return calc();
        bool ret = false;
        while(next(i,j)!=-1) {
                if (graph[i][j]!=0||graph[i+1][j]!=0) continue;
                graph[i][j] = 1;
                graph[i+1][j] = -1;

                ret = select(cur+1,dep,i,j);

                graph[i][j] = 0;
                graph[i+1][j] = 0;
                if (ret) break;
        }
        return ret;
}
int main(void) {
        cin >> N >> M >> H;
        for (int i=0;i<M;++i) {
                int a,b;
                cin>>a>>b;
                graph[b][a] = 1;
                graph[b+1][a] = -1;
        }
        bool ret = false;
        int in = -1;
        for (int i=0;i<4;++i) {
                ret = select(0,i,1,0);
                if (ret) {
                        in=i;
                        break;
                }
        }
        cout << in << '\n';

        return 0;
}
