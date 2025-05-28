#include <iostream>
#include <climits>
#include <set>
using namespace std;
int N;
int board[10][10];
set<int> is_visit;
int ret=INT_MAX;
void visit(int start, int id,int cost) {
        if (is_visit.size()==N) {
                if (!board[id][start]) return;
                cost +=board[id][start];
                ret = (ret>cost)?cost:ret;
                return;
        }
        for (int i=0;i<N;++i) {
                if (is_visit.find(i)!=is_visit.end()) continue;
                if (!board[id][i]) continue;
                is_visit.insert(i);
                visit(start,i,cost+board[id][i]);
                is_visit.erase(i);
        }
}
int main(void) {
        cin>>N;
        for(int i=0;i<N;++i)
                for(int j=0;j<N;++j)
                        cin>>board[i][j];

        for(int i=0;i<N;++i) {
                is_visit.insert(i);
                visit(i,i,0);
                is_visit.erase(i);
        }
        cout << ret << '\n';
        return 0;
}
