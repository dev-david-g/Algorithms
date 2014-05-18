#include <fstream>
#include <vector>
#include <string.h>


using namespace std ;
const int NMAX =   1000005 ;

void Read() ;
void Solve() ;
void OUT() ;
void BFS(int) ;

ifstream cin("bfs.in") ;
ofstream cout("bfs.out") ;

int N, M, Start, L;
int x, y ;
vector <int> Q[NMAX] ;
int S[NMAX], A[NMAX], Cost[NMAX];

inline void Read() {

 cin >> N >> M >> Start ;
    for(int i = 1 ; i <= M ; ++ i)
        {
           cin >> x >> y ;
           Q[x].push_back(y) ;
        }
}






void BFS(int nod)
{
    memset(Cost, -1, sizeof(Cost)) ;

    L = 1 ;
    Cost[nod] = 0 ;
    S[L] = nod ;


    for(int i = 1 ; i <= L ; ++ i)
            for(int j = 0 ; j < A[S[i]] ; ++ j)
                if(Cost[Q[S[i]][j]]== - 1)
                    {
                        S[++ L] = Q[S[i]][j] ;
                        Cost[S[L]] = Cost[S[i]] + 1 ;

                    }

}

inline void Solve()
{
     for(int i = 1; i <= N ; ++ i)
        A[i] = Q[i].size() ;

   BFS(Start) ;

}

inline void OUT()
{

for(int i = 1 ; i <= N ; ++ i)
    cout << Cost[i] << ' ' ;

cout << '\n' ;
}


int main()
{
   Read() ;
    Solve() ;
   OUT() ;
   cin.close() ;
   cout.close() ;
    return 0 ;
}
