#include <fstream>
#include <cstring>
#include <queue>

using namespace std ;

const int NMAX = 1010 ;
const int INF = 40040 ;
int dx[] = {0,0,-1,1,-1,1,-1,1};
int dy[] = {-1,1,0,0,1,1,-1,-1};

ifstream cin("taxa.in") ;
ofstream cout("taxa.out") ;

int N , M , V[NMAX][NMAX];
int P[NMAX][NMAX];
int lp, cp, lf, cf ;
int ok ;

 void Citire() ;
 void Fill() ;
 void Afisare() ;

inline void Citire()
{
    memset(P, INF, sizeof(P)) ;
    cin >> N >> M ;
    cin >> lp >> cp >> lf >> cf ;

    for(int i = 1 ; i <= N ; ++ i)
        for(int j = 1 ; j <= M ; ++ j)
             cin >> V[i][j] ;


           P[lp][cp] = 0 ;
}

 void Fill()
{
   do
   {
      ok = 1 ;
      for(int i = 1; i <= N ; ++ i)
        for(int j = 1 ; j <= M ; ++ j)
            for(int d = 0 ; d < 8 ; ++ d)
                {
                    int xnou = i + dx[d] ;
                    int ynou = j + dy[d] ;
                    if(xnou > 0 && xnou <= N && ynou > 0 && ynou <= M && V[xnou][ynou]!= V[i][j] && P[i][j] > P[xnou][ynou] + V[i][j] * V[xnou][ynou])
                {
                    P[i][j] = P[xnou][ynou] + V[i][j] * V[xnou][ynou] ;
                    ok = 0 ;
                }

                if(xnou > 0 && xnou <= N && ynou > 0 && ynou <= M && V[xnou][ynou] == V[i][j] && P[i][j] > P[xnou][ynou])
                {
                    P[i][j] = P[xnou][ynou] ;
                    ok = 0 ;
                }

                }
                } while(!ok) ;

}

inline void Afisare(){

    cout << P[lf][cf] << '\n' ;
}

int main()
{
    Citire() ;

    Fill() ;
    Afisare() ;
    cin.close() ;
    cout.close() ;
    return 0 ;
}
