///Template by Gergely David

#include <fstream>
//#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <climits>

//#define MIN (long int a, long int b) (((a)<(b))?(a):(b))
//#define MAX (long int a, long int b) (((a)>(b))?(a):(b))
//#define unsigned long long ull

using namespace std ;

const int NMAX = 100005 ;
const int LMAX = 20 ;
const int INF = 0x3f3f3f3f ;

vector <int> V ;
queue < pair <int, int> > Q ;

ifstream cin("rmq.in") ;
ofstream cout("rmq.out") ;

long long  N, M, A[NMAX] ;
long long  RMQ[LMAX][NMAX];
long long  lg[NMAX] ;

inline int MAX(long a, long b)
{
    if(a > b ) return  a ;
    else return b;
}
inline int MIN(long long a, long long b)
{
    if(a < b ) return  a ;
    else return b;
}
inline int Read()
{

    cin >> N >> M ;
    for(int i = 1 ; i <= N ; ++ i )
        cin >> A[i] ;

}

int main()
{

    Read() ;

    lg[1] = 0 ;

    for(int i = 2 ; i <= N ; ++ i)
        lg[i] = lg[i / 2]  + 1  ;

    for(int i = 1 ; i <= N ; ++ i)
        RMQ[0][i] = A[i] ;

    long  int l ;

    for(int i = 1 ; (1 << i) <= N ; ++ i)
        for(int j = 1 ; j <= N - (1 << i) + 1 ; ++ j)
        {
            l = 1<<( i - 1) ;
            RMQ[i][j] = MIN(RMQ[i - 1][j], RMQ[i - 1][j + l]) ;

        }





    long int   diference, sh ;
    // for(int i = 1 ; i <= LMAX ; ++ i)
    //{for(int j = 1 ; j <= N ; ++ j )
    //   cout << RMQ[i][j] << ' ' ;
    // cout << '\n' ;
    // }

    for(int i = 1 ; i <= M ; ++ i)
    {
        int x;
        int y ;
        cin >> x >> y ;

        diference = y - x + 1 ;
        l = lg[diference] ;
        sh = diference - (1 << l) ;
        cout << MIN(RMQ[l][x], RMQ[l][x + sh ]) << '\n' ;
    }

    cin.close() ;
    cout.close() ;
    return  0 ;
}
