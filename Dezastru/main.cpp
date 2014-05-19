#include <fstream>
#include <iomanip>


using namespace std ;

const int NMAX = 30 ;

ifstream cin("dezastru.in") ;
ofstream cout("dezastru.out") ;

int N, K;
float V[NMAX], sum[NMAX][NMAX], dp[NMAX][NMAX];

int main()
{
    cin >> N >> K ;
    for(int i = 1 ; i <= N ; ++ i)
        cin >> V[i] ;

    for(int i = 0 ; i <= N ; ++ i)
    sum[i][0] = dp[i][0] = 1 ;

    for(int i = 1; i <= N ; ++ i)
        for(int j = 1 ; j <= K ; ++ j)
            {
                dp[i][j] = dp[i -1][j] + dp[i - 1][j - 1] * V[i] ;
                sum[i][j] = sum[i - 1][j] + sum[i-1][j-1] ;

            }

            dp[N][K] = dp[N][K] / sum[N][K] ;
            cout << fixed << setprecision(6) << dp[N][K] << '\n' ;

    cin.close() ;
    cout.close() ;
    return 0 ;
}
