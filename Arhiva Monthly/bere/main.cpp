#include <fstream>

using namespace std ;

const int NMAX = 15006 ;

ifstream cin("br.in") ;
ofstream cout ("br.out") ;

int N, T ;
int C[NMAX] ;
int K, X ;
int sol = 0;


inline int putere(int x)
{
    return (1<<(x));
}

int main()
{


    cin >> N, cin >> T ;
 int i, j ;
    for( i = 1 ; i < N + 1 ; ++ i)
    {
        cin >> C[i] ;
        C[i] = C[i] + C[i - 1] ;
    }


    for(int ma = 0 ; ma < T ; ++ ma)
    {   sol = 0 ;
        cin >> K >> X ;


        if(C[N] - C[K - 1] <= X)
        {
            sol = sol + N - K + 1 ;
            X = X - C[N] - C[K -1] ;
            K = 0 ;

        }
        else
            -- K ;

        sol = sol + N * (X / C[N]) ;
        X = X % C[N] ;

        for( j = K, i = 21 ; i >= 0 ; -- i)
            if(putere(i) + j <= N && C[putere(i) + j] - C[K] <= X)
                j = j + putere(i) ;
        sol = sol + j - K ;


        if(sol > N) sol = N ;
        cout << sol << '\n' ;

    }

    cin.close() ;
    cout.close() ;
    return 0;
}
