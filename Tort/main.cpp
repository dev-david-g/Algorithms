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


#define MIN (a, b) (((a)<(b))?(a):(b))
#define MAX (a, b) (((a)>(b))?(a):(b))


using namespace std ;

const int NMAX = 105 ;
const int INF = 0x3f3f3f3f ;

typedef long long Huge[1000] ;

void Atribuire(Huge, int) ;

void OUT(Huge) ;

vector <int> V ;
queue < pair <int, int> > Q ;

ifstream cin("tort.in") ;
ofstream cout("tort.out");

unsigned long  A, B ;
Huge Sol ;
int T1, T2, T3, T4 ;

inline void Atribuire(Huge x, int  y)
{

    x[0] = 0 ;
    while(y)
    {

        x[++x[0]] = y % 10 ;
        y = y / 10 ;
    }
}


inline void multire(Huge H, unsigned long  X)
{

    unsigned long  T = 0 ;
    for(int i = 1 ; i <= H[0] ; ++ i)
    {
        H[i] = H[i] * X + T;
        T = H[i] / 10 ;
        H[i] = H[i] % 10 ;

    }

    while(T)
    {
        H[ ++ H[0] ] = T % 10 ;
        T = T / 10 ;
    }
}

inline void OUT(Huge x)
{
    for(int i = x[0] ; i >= 1 ; -- i)
       cout << x[i] ;
       cout << '\n' ;
}

int main()
{
    cin >> A >> B  ;
    T1 = A + 1 ;
    T2 = B + 1 ;
    T3 = A + B  + 2 ;

    if(!(T1 % 2))
        T1 = T1 / 2 ;
    else if(!(T2 % 2))
        T2 = T2 / 2 ;
    else if(!(T3 % 2))
        T3 = T3 / 2 ;

    Atribuire(Sol, T1) ;
    multire(Sol, T2) ;
    multire(Sol, T3) ;

    OUT(Sol) ;

    cin.close() ;
    cout.close() ;
    return  0 ;
}
