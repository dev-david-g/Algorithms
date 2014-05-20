/// by Gergely David

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

#define MIN (a, b) (((a)<(b))?(a):(b))
#define MAX (a, b) (((a)>(b))?(a):(b))
#define unsigned long long ull

using namespace std ;

const int NMAX = 1000005 ;
const int INF = 0x3f3f3f3f ;

//vector <int> V ;
queue < pair <int, int> > Q ;

ifstream cin("paranteze.in") ;
ofstream cout("paranteze.out") ;

int N ;
string s ;
bool  V[NMAX] ;
vector <char> D ;
int cnt = 0  ;
int  sol[NMAX] ;
char st[NMAX] ;
int K ;
int MAXX = -INF ;



int main()
{

    cin >> N  ;
    memset(V, false , sizeof(V)) ;

  /*  for(int i = 0 ; i < N ; ++ i)
    cout << V[i] <<' ' ;
    cout << '\n' ;
    */


    for(int i = 1 ; i <= N ; ++ i)
    {
        char c ;
        cin >> c ;
        D.push_back(c) ;
    }

   K = 0 ;

for(int i = 0 ; i < N ; ++ i )
{
if(D[i] == '(' || D[i] == '[' || D[i] == '{')
         {

             ++ K ;
             st[K] = D[i];
             sol[K] = i ;

         }
         else {
                if( (D[i] == ')' && st[K] == '(') || (D[i] == ']' && st[K] == '[') || (D[i] == '}' && st[K] == '{') )
            {
                V[i] = true ;
                V[sol[K]] = true ;
         //-- K ;
            }
          -- K ;
          }

}

   cnt = 0 ;

/*for(int i = 0 ; i < N ; ++ i)
    cout << V[i] <<' ' ;
    cout << '\n' ;
    */

   for(int i = 0 ; i < N ; ++ i)
        if(V[i] == true)
           ++ cnt ;
   else {
    if(MAXX < cnt)
        MAXX = cnt ;
    cnt = 0 ;
   }


if(MAXX == - INF)
    cout << 0 << '\n' ;
else cout << MAXX << '\n' ;

    cin.close() ;
    cout.close() ;
    return  0 ;
}
