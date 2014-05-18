#include <fstream>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std ;

const int NMAX = 1005 ;
const int KMAX = 1000005 ;
int dx[] =  {0,1,0,-1} ;
int dy[] = {1,0,-1,0} ;
const int INF = 0x3f3f3f3f ;
ifstream cin("ai.in") ;
ofstream cout("ai.out") ;

struct obstacol {int x, y;};
struct nod {int x, y, nrpasi;};


int compx(obstacol, obstacol) ;
int compy(obstacol, obstacol) ;
void Lee() ;
void Lee2() ;
void Math(int, int, nod, int) ;
void Initializare() ;
void Rezolvare() ;
int  cmmdc(int, int) ;


obstacol obs[KMAX] ;
int A[NMAX][NMAX], O[NMAX][NMAX] ;
nod poz1[NMAX], poz2[NMAX] ;
int N, xl1, xl2, yl1, yl2, xt, yt, xr1, xr2, yr1, yr2 ;
int x, y ;
int K, nrpoz1, nrpoz2, lmax, lc, kt ;
int min11, min12, min21, min22 ;
queue <pair <int, int> > Q ;
queue <pair <int, int> > QQ ;

inline int max(int a, int b) { if( a > b ) return a ; else return b ; }
inline int min(int a, int b) { if( a < b ) return a ; else return b ; }


inline void Initializare()
{
    cin >> N ;
    cin >> xt >> yt >> xl1 >> yl1 >> xl2 >> yl2 >> xr1 >> yr1 >> xr2 >> yr2 ;
    cin >> K ;
    for(int i = 1 ; i <= K ; ++ i)
    {
        cin >> x >> y ;
        obs[i].x = x ;
        obs[i].y = y ;
        A[x][y] = 1 ;
        ++ kt ;
    }
}



inline int compx(obstacol a, obstacol b)
{
	if (a.x > b.x)
		return 0;
	if (a.x == b.x && a.y > b.y)
		return 0;
	return 1;
}

inline int compy(obstacol a, obstacol b)
{
	if (a.y > b.y)
		return 0;
	if (a.y == b.y && a.x > b.x)
		return 0;
	return 1;
}




void Lee()
{
    O[xr1][yr1] = 0 ;
    while(!Q.empty())
    {
        int xx = Q.front().first;
        int yy = Q.front().second ;
        Q.pop() ;
        for(int i = 0 ; i < 4; ++ i)
        {
            int xnou = xx + dx[i] ;
            int ynou = yy + dy[i] ;
            if(A[xnou][ynou] == 0)
                if(O[xnou][ynou] > O[xx][yy] + 1)
                {
                O[xnou][ynou] = O[xx][yy] + 1 ;
                Q.push(make_pair(xnou, ynou)) ;
                }
        }
    }
}

void Lee2()
{
    O[xr2][yr2] = 0 ;
    while(!QQ.empty())
    {
        int xx = QQ.front().first;
        int yy = QQ.front().second ;
        QQ.pop() ;
        for(int i = 0 ; i < 4; ++ i)
        {
            int xnou = xx + dx[i] ;
            int ynou = yy + dy[i] ;
            if(A[xnou][ynou] == 0)
                if(O[xnou][ynou] > O[xx][yy] + 1)
                {
                O[xnou][ynou] = O[xx][yy] + 1 ;
                QQ-.push(make_pair(xnou, ynou)) ;
                }
        }
    }
}

inline int cmmdc(int a, int b)
{
    while(a != b)
        if(a > b) a = a - b ;
    else b = b - a ;
    return a ;
}


inline void Math(int xl1, int yl1, nod poz1[], int &nrpoz)
{

    int d, dxx, dyy, t = 0 ;
    dxx = xt - xl1 ;
    dyy = yt - yl1 ;
    if(dxx == 0)
        if(yt < yl1)
            for(int i = yt + 1 ; i <= yl1 ; ++ i)
               {
                  poz1[t].x = xt;
                   poz1[t].y = i;
                    ++ t ;
               }
    else
        for(int i = yl1 ; i < yt ; ++ i)
           {
              poz1[t].x = xt;
               poz1[t].y = i;
                ++ t ;
           }
    else
        if(dyy == 0)
            if(xt < xl1)
                for(int i = xt + 1; i <= xl1 ; ++ i)
            {poz1[t].x = i ;
              poz1[t].y = yt ;
              ++ t ;
            }
            else
                for(int i = xl1 ; i < xt ; ++ i)
            {
                poz1[t].x = i ;
                poz1[t].y = yt ;
                ++ t ;
            }
       else
       {
           d = cmmdc(abs(dxx), abs(dyy)) ;
           dxx = abs(dxx) / d ;
           dyy = abs(dyy) / d ;

           if(xl1 < xt && yl1 < yt)
                for(t = 0, x = xl1, y = yl1; x + dxx * t < xt ; ++ t)
           {
               poz1[t].x = x + dxx * t ;
               poz1[t].y = y + dyy * t ;

           }
           if(xl1 > xt && yl1 > yt)
            for(t = 0, x = xl1, y = yl1 ;x - dxx * t > xt ; ++ t)
            {
                poz1[t].x = x - dxx * t ;
                poz1[t].y = y - dyy * t ;
            }
            if(xl1 < xt && yl1 > yt)
            for(t = 0, x = xl1, y = yl1; x + dxx * t < xt ; ++ t)
            {
                poz1[t].x = x + dxx * t ;
                poz1[t].y = y - dyy * t ;
            }
            if(xl1 > xt && yl1 < yt)
           for(t = 0, x = xl1, y = yl1 ;  x - dxx * t > xt ; ++ t)
           {
               poz1[t].x = x - dxx * t ;
               poz1[t].y = y + dyy * t ;
           }
       }
       nrpoz = t ;


}


inline void Rezolvare() {

sort(obs + 1, obs + K + 1, compx) ;

for(int i = 1 ; i <= K; ++ i)
{
    if(obs[i].x == obs[i - 1].x && obs[i].y == obs[i - 1].y + 1)
        ++ lc ;
    else lc = 0 ;
    if(lc > lmax)
        lmax = lc ;
}

sort(obs + 1, obs + K + 1, compy) ;
for(int i = 1 ; i <= K ; ++ i)
{
 if(obs[i].y == obs[i - 1].y && obs[i].x == obs[i - 1].x + 1)
        ++ lc ;
    else lc = 0 ;
    if(lc > lmax)
        lmax = lc ;
}

if(lmax >= 1)
    cout << lmax + 1 << '\n' ;
else cout << 0 << '\n' ;


Math(xl1, yl1, poz1, nrpoz1) ;
Math(xl2, yl2, poz2, nrpoz2) ;
for(int i = 0 ; i <= N + 1 ; ++ i)
    A[i][0] = A[0][i] = A[N + 1][i] = A[i][N + 1] = 1 ;
for(int i = 1 ; i <= N  ; ++ i)
    for(int j = 1; j <= N ; ++j)
        O[i][j] = N * N + 1 ;

A[xt][yt] = 1 ;

  Q.push(make_pair(xr1, yr1)) ;
    Lee() ;

min11 = min12 = N * N + 2 ;
for(int i = 0 ; i < nrpoz1; ++ i)
{
    x = poz1[i].x;
    y = poz1[i].y;
    if(min11 > O[x][y])
        min11 = O[x][y] ;

}

for(int i = 0 ; i < nrpoz2 ; ++ i)
{
    x = poz2[i].x ;
    y = poz2[i].y ;
    if(min12 > O[x][y])
        min12 = O[x][y] ;
}

//cout << min11 << min12 << '\n';


QQ.push(make_pair(xr2, yr2)) ;

Lee2() ;

min21 = min22 = N * N + 2 ;
for(int i = 0 ; i < nrpoz1; ++ i)
{
    x = poz1[i].x;
    y = poz1[i].y;
    if(min21 > O[x][y])
        min21 = O[x][y] ;

}

for(int i = 0 ; i < nrpoz2 ; ++ i)
{
    x = poz2[i].x ;
    y = poz2[i].y ;
    if(min22 > O[x][y])
        min22 = O[x][y] ;
}

//cout << min21 << min22 << '\n' ;

if(max(min11, min22) < max(min12, min21))
    cout << max(min11, min22) << '\n' ;
else cout << max(min12, min21) << '\n' ;


}
int main()
{

    Initializare() ;
    Rezolvare() ;
    cin.close() ;
    cout.close() ;
    return 0 ;
}
