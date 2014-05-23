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


#define unsigned long long ull

using namespace std ;

const int NMAX =  501 ;
const int INF = 0x3f3f3f3f ;

vector <int> V ;
queue < pair <int, int> > Q ;

inline int MAX (long a, long b) {if(a > b ) return a; else return b;}

ifstream cin("plantatie.in") ;
ofstream cout("plantatie.out");

int  A[10][NMAX][NMAX] ;
int N, M ;

int main()
{
    cin >> N >> M ;

    for(int i = 1 ; i <= N ; ++ i )
        for(int j = 1 ; j <= N ; ++ j)
            cin >> A[0][i][j] ;

   for(int i = 1 ; 1 << i <= N ; ++ i)
    for(int j = 1 ; j + (1 << (i - 1) ) - 1 <= N ; ++ j )
    for(int k = 1 ; k + (1 << (i - 1) ) -1 <= N ; ++ k)
      A[i][j][k] = MAX ( MAX ( A[i - 1][j][k], A[i - 1][ j + (1 << (i -1) ) ][k + (1 << (i - 1) )] ),  MAX(A[i - 1 ][j + (1 << (i -1) )][k],  A[i - 1][j][k + (1 << (i - 1) )])) ;

for(int i =  0 , k = 0, next; i < M ; ++ i, k = 0)
{
    int x, y, L ;
    cin >> x >> y >> L ;

    for( next = 1 ; next <= L ; next <<= 1, ++ k) next >>= 1 ;
     -- k ;

    cout << MAX  (   MAX(    A[k][x][y],      A[k][x][y + L - next ]),     MAX(     A[k][x + L - next][y],        A[k][x + L - next][y + L - next])    ) << '\n' ;


}








    cin.close() ;
    cout.close() ;
    return  0 ;
}
