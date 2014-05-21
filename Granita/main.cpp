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
#define unsigned long long ull

using namespace std ;

const int NMAX = 105 ;
const int INF = 0x3f3f3f3f ;

vector <int> V ;


ifstream cin("granita.in") ;
ofstream cout("granita.out");

int N ;
int x , y ;


int main()
{
vector < pair <int, int> > Q ;
    cin >> N ;

    for(int i = 0 ; i < N ; ++ i)
    {
        cin >> x >>  y ;
        Q.push_back(make_pair(x, y)) ;
    }

    sort(Q.begin(), Q.end()) ;
   // return 0 ;

    int cnt = 0 ;
    int actual = Q[0].second ;
//    actual = 0 ;

    for(int i = 0 ; i < Q.size() ; ++ i)
       {

        if(Q[i].second >= actual)
        {
            actual = Q[i].second ;
        }
        else ++ cnt ;
       }


    cout << cnt << '\n' ;


    cin.close() ;
    cout.close() ;
    return  0 ;
}
