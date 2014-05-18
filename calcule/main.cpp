#include <fstream>
#define MOD 20011

using namespace std ;

const int NMAX = 100005 ;

ifstream cin("calcule.in") ;
ofstream cout("calcule.out");

int N, sol, sx = 0 ;
int s = 0, K, S[NMAX], R[NMAX], A[NMAX];

int main()
{
    R[0] = 1 ;
    cin >> N >> K ;
    for(int i = 1 ; i <= N;  ++ i)
    {
        cin >> S[i] ;
        sx = (sx + S[i]) % K ;
        s = (s + R[sx]) % MOD ;
        ++ R[sx] ;
        int j ;
        for(j = S[i]  - 1 ; A[j] == 0 && j > 0 ;  -- j);
            -- A[j];
            ++ A[S[i]] ;
        }

        sol = 0 ;
        for(int i = 1 ; i < 20001 ; ++ i)
            sol = sol + A[i] ;

        cout << sol << '\n' ;
        cout << s << '\n' ;
    cin.close() ;
    cout.close() ;
    return 0 ;
}
