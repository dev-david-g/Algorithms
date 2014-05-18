#include <fstream>

using namespace std ;

const int NMAX = 1005 ;

ifstream cin("cmls.in") ;
ofstream cout("cmls.out") ;

int V[NMAX], L[NMAX], N, Max,  t, mx;


int main()
{
    cin >> N ;
    for(int i = 1 ; i <= N ; ++ i)
        cin >> V[i] ;
    L[N] = 1 ;


    for(int K = N - 1 ; K > 0 ; -- K)
    {
        mx = 0 ;
        for(int i = K + 1 ; i <= N ; ++ i)
           {
                if(V[i] >= V[K] && L[i] > mx)
            mx = L[i] ;
        L[K] = mx + 1 ;
        if(L[K] > Max)
            Max = L[K] ;
           }
    }
    cout << Max << '\n' ;
    cin.close() ;
    cout.close() ;
    return 0 ;
}
