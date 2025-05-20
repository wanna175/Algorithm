#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
int N;          //2~11
int A[101];     //1~100
int op[4];      //operator + - * /
int opstack[101];
int max_ret = -1000000000, min_ret = 1000000000;
int calc(int n, int mid_ret, int op_index) {
        int ret = mid_ret;
        int i = opstack[op_index];
    if (i == 0)
        ret+=A[n];
        if (i == 1)
                ret-=A[n];
        if (i == 2)
                ret*=A[n];
        if (i == 3)
                 ret/=A[n];
 
         return ret;
}
void permutation(int n,int mid_ret, set<int>& is_visit) {
        if (n >= N-1){
                if (mid_ret > max_ret) max_ret = mid_ret;
                if (mid_ret < min_ret) min_ret = mid_ret;
                return;
        }
        for (int i=0; i< N-1; ++i){
                if (is_visit.find(i) != is_visit.end()) continue;
                is_visit.insert(i);
                permutation(n+1, calc(n+1,mid_ret,i) ,is_visit);
                is_visit.erase(i);
        }
}
int main(void) {
        cin >> N;
        for (int i=0;i<N;++i)
                cin >> A[i];
         for (int i=0;i<4;++i)
                  cin >> op[i];
  
          for (int i=0;i<N-1;++i){
                  if(i<op[0]) opstack[i] = 0;                     // +
                  else if(i<op[0]+op[1]) opstack[i] = 1;          // -
                  else if(i<op[0]+op[1]+op[2]) opstack[i] = 2;    // *
                  else opstack[i] = 3;                            // /
          }
          set<int> is_visit;
          permutation(0,A[0],is_visit);
  
          cout << max_ret << endl;
          cout << min_ret << endl;
  
         return 0;
  }
