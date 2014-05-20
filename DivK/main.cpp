#include <fstream>

using namespace std ;

const int NMAX = 500005 ;

ifstream cin("divk.in") ;
ofstream cout("divk.out") ;

int N, K, A, B;
long long V[NMAX], rez[NMAX], nr[NMAX] ;
long long sol;

int main()
{
    cin >> N >> K >> A >> B ;

    for(int i = 1 ; i <= N ; ++ i)
    {
        cin >> V[i] ;
        rez[i] = (rez[i - 1] + V[i]) % K ;
        if(i > B)
            -- nr[rez[i - B - 1]];
        if(i >= A )
            ++nr[rez[i- A]] ;
        sol = sol + nr[rez[i]] ;
    }
    cout << sol ;
    cin.close() ;
    cout.close() ;
    return 0;
}
