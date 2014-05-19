#include <fstream>

using namespace std;

const int NMAX = 200005 ;
const int INF = 0x3f3f3f3f;

int N,  cnt = 0, bestSum, sum;
int  nr;
 int nrr = -INF ;

ifstream cin("crescator.in") ;
ofstream cout("crescator.out") ;

inline int max(int a, int b) { if(a > b) return a ; else return b ; }


int main()
{
    cin >> N ;
    for(int i = 1; i <= N ; ++ i)
    {
        cin >> nr ;
       if(nr > nrr)
           ++ cnt ;
           else {
            bestSum = max(bestSum, cnt) ;
            sum +=  ((cnt + 1) * cnt) >> 1 ;
            cnt = 1 ;
           }
           nrr = nr ;
           }

    sum +=  ((cnt + 1) * cnt) >> 1 ;
    bestSum = max(bestSum, cnt) ;
    cout << sum << ' ' << bestSum << '\n' ;
    cin.close() ;
    cout.close() ;

    return 0;
}


