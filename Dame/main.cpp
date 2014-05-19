#include <fstream>
#include <cstring>
using namespace std ;

const int NMAX = 100 ;
const int INF = 0x3f3f3f3f; ;

ifstream fin("dame.in") ;
ofstream fout("dame.out") ;


int A[NMAX], col[NMAX], dprin[NMAX], dsec[NMAX];
int sol[NMAX] ;
int Matrix[NMAX][NMAX] ;
int NrSol ;
int N ;

void Backtraking(int) ;
void Afisare() ;


void Backtraking(int K)
{
    if(K == N + 1) Afisare() ;
    else
       {for(int i = 1 ; i <= N ; ++ i)
           {if(col[i] == 0 && dprin[i - K + N] == 0 && dsec[i + K - 1] == 0)
           {
               sol[K] = i ;
               col[i] = 1 ;
               dprin[i - K + N] = 1 ;
               dsec[i + K - 1] = 1 ;
               Backtraking(K + 1) ;
               col[i] = 0 ;
               dprin[i - K + N] = 0 ;
               dsec[i + K - 1] = 0 ;

           }
           }
       }

}

inline void Afisare()
{
    ++ NrSol ;
    for(int i = 1 ; i <= N;  ++ i)
         fout << sol[i] << ' ' ;
        fout << '\n' ;
        fout << '\n' ;
        memset(Matrix, 0, sizeof(Matrix)) ;
        for(int i = 1 ; i <= N ; ++ i)
            for(int j = 1 ; j <= N ; ++ j)
                Matrix[i][sol[i]] = 1 ;

for(int i = 1 ;i <= N ; ++ i)
{for(int j = 1 ; j <= N ; ++ j)
fout << Matrix[i][j] << ' ' ;
fout << '\n' ;
}
fout << '\n' ;


}

int main()
{
    fin >> N ;
    memset(sol, INF, sizeof(sol)) ;
    Backtraking(1) ;
fout << '\n' << NrSol << '\n' ;
    fin.close() ;
    fout.close() ;
    return 0 ;
}
