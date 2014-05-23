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

int  A[NMAX][NMAX][10], lg[10];
int N, M ;

inline int max(int a, int b, int c, int d)
{

    return max(a, max(b,  max(c, d))) ;
}

int main()
{
    cin >> N >> M ;

    for(int i = 1 ; i <= N ; ++ i )
      {
           for(int j = 1 ; j <= N ; ++ j)
            cin >>A[i][j][0];

            if(i > 1)
                lg[i] = lg[i >> 1] + 1 ;
      }

      int l, a, b, c, d ;

      for(int k = 1 ; (1 << k) <= N ; ++ k)
        for(int i = 1 ; i <= N - (1 << (k - 1)) + 1; ++ i)
            for(int j = 1 ; j <= N - (1 << (k - 1)) + 1; ++ j )
      {
         l = 1 << (k - 1) ;
         a = A[i][j][k - 1] ;
         b = A[i + l][j][k - 1] ;
         c = A[i][j + l][k - 1] ;
         d = A[i + l][j + l][k - 1] ;
         A[i][j][k] = max(a, b, c, d) ;

      }


      for(int i = 1 ; i <= M ; ++ i)
      {
          int x, y, L ;
          cin >> x >> y >> L ;

          int sol = lg[L] ;
          l = L - (1 << (sol)) ;
          a = A[x][y][sol] ;
          b = A[x + l][y][sol] ;
          c = A[x][y + l][sol] ;
          d = A[x + l][y + l][sol] ;

          cout << max(a, b, c, d) << '\n' ;

      }





    cin.close() ;
    cout.close() ;
    return  0 ;
}
