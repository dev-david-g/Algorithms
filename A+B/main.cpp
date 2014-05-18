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
queue < pair <int, int> > Q ;

ifstream cin("adunare.in") ;
ofstream cout("adunare.out");

int A, B ;

int main()
{
    cin >> A >> B ;
    cout << A + B ;
    cin.close() ;
    cout.close() ;
    return  0 ;
}
