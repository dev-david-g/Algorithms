#include <fstream>
#include <cstring>
#include <vector>


using namespace std ;

const int NMAX = 100009;
const int INF = 0x3f3f3f3f ;

void Read() ;
void DFS(int) ;
void OUT() ;

ifstream cin("cerere.in") ;
ofstream cout("cerere.out") ;


inline int max(int a, int b)
{
    if(a < b) return b ;
    else return a ;
}
inline int min(int a, int b)
{
    if(a > b ) return b ;
    else return a ;
}

int N ;
int  K[NMAX] ;
bool vizitat[NMAX] ;
vector <int> V[NMAX] ;
int S[NMAX], sol[NMAX] ;

inline void Read()
{

    cin >> N ;

    for(int i = 1 ; i <= N ; ++ i)
        cin >> K[i] ;

    for(int i = 1; i < N ; ++ i)
    {
        int x, y ;
        cin >> x >> y ;
        V[x].push_back(y) ;
        vizitat[y] = true ;
    }

}


void DFS(int nod)
{
    vizitat[nod] = true ;
    S[ ++ S[ 0 ] ] = nod ;

    if(K[nod])
        sol[nod] = 1 + sol [ S [ S[ 0 ] - K [ nod ] ] ] ;

    for(unsigned  i = 0 ; i < V[ nod ].size() ; ++ i)
        if(vizitat [ V [nod][ i] ] == false)
            DFS( V [ nod ][ i ] ) ;

            S[ -- S[ 0 ] ];
}



inline void OUT()
{
    for(int i = 1; i <= N ; ++ i)
        cout << sol[i] << ' ' ;
        cout << '\n' ;


}

int main()
{
    Read() ;

    for(int i = 1 ; i <= N ; ++ i)
        if( vizitat[i] == false)
            V[0].push_back(i) ;

    memset(vizitat, false, sizeof(vizitat)) ;

    DFS(0) ;

    OUT() ;


    cin.close() ;
    cout.close() ;
    return 0 ;
}

