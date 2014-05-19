/// Suma maxima dintr-un triunghi.

#include <fstream>

using namespace std ;

const int NMAX = 10000 ;
const int INF = 0x3f3f3f3f ;
void Read() ;
void Solve() ;
void Out() ;
ifstream cin("triunghi.in") ;
ofstream cout("triunghi.out") ;

int N, A[NMAX][NMAX];
int MAX ;

inline void Read()
{

    cin >> N ;
    //int i, j ;
   for(int i = 0 ; i <= N; ++ i)
        for(int j = 1 ; j <= i + 1 ; ++ j)
            cin >> A[i][j] ;
}

void inline Solve()
{
    int LMAX ;
    MAX = A[0][1] ;
    for(int i = 1 ; i <= N ; ++ i)
    {   LMAX = - INF ;
        for(int j = 1 ; j <= i + 1; ++ j)
            if(LMAX < A[i][j])
            LMAX = A[i][j] ;
        MAX = MAX + LMAX ;
        //cout << LMAX << '\n';
    }

}

inline void Out()
{
    cout << MAX << '\n' ;
///    cout << sizeof(MAX) << ' ' << sizeof(A) << '\n' ;
}
int main()
{
    Read() ;
    Solve() ;
    Out() ;

    cin.close() ;
    cout.close() ;
    return 0 ;
}
