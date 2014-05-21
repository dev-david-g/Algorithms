#include <fstream>

using namespace std ;

const int NMAX = 501 ;
const int ppp = 500 ;

typedef int BIG[ppp] ;

ifstream cin("expozitie.in") ;
ofstream cout("expozitie.out") ;

int N, D, K ;
int R, M, Q, aux;
BIG Lc[NMAX], Lp[NMAX] ;


inline void sum(BIG A, BIG B, BIG &S)
{
    int cifra, t = 0, max;
    if(A[0] < B[0])
    {
        max = B[0] ;
        for(int i = A[0] + 1 ; i <= B[0]; ++ i)
            A[i] = 0 ;
    }
    else
    {
        max = A[0] ;
        for(int i = B[0] + 1 ; i <= A[0] ; ++ i)
            B[i] = 0 ;
    }
    int jj ;
    for(int jj = 1; jj <= max ; ++ jj)
    {
        cifra = A[jj] + B[jj] + t ;
        S[jj] = cifra % 10 ;
        t = cifra / 10 ;
    }

    if(t)
        S[jj] = t ;
    else -- jj ;
    S[0] = jj;
}

int main()
{
    cin >> N >> D >> K ;
    R = N - K * D ;
    if(R == 0) cout << 1 << '\n' ;
    else if(R < 0) cout << 0 << '\n' ;
    else
    {
        M = R + D - 1 ;
        for(int i = 1 ; i <= R ; ++ i)
            Lp[i][0] = Lp[i][1] = 1 ;
        for(int i = 2 ; i <= D ; ++ i)
        {
            aux = i ;
            Lc[1][0] = 0 ;
            while(aux)
            {
                ++ Lc[1][0] ;
                Lc[1][Lc[1][0]] = aux % 10 ;
                aux = aux / 10 ;
            }
            for(int j = 2 ; j <= R ; ++ j)
                sum(Lp[j], Lc[j - 1], Lc[j]) ;
            for(int j = 0 ; j <= R ; ++ j)
                for(int q = 0 ; q <= Lc[j][0] ; ++ q)
                    Lp[j][q] = Lc[j][q] ;

        }

        for(int jjj =Lc[R][0] ; jjj >= 1 ; -- jjj )
            cout << Lc[R][jjj] ;
    }
    // cout << '\n' ;
    cin.close() ;
    cout.close() ;
    return 0 ;
}
