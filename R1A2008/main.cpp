#include <fstream>
#include <algorithm>
#include <vector>

using namespace std ;

const int NMAX = 905 ;

ifstream cin("minscalar.in") ;
ofstream cout("minscalar.out") ;

void Read() ;
void Solve() ;
void Out() ;

int T ;
int N ;
int A[NMAX], B[NMAX];
long long sum = 0 ;
int d = 0;
vector <int> V, V2 ;

inline void Read()
{
    cin >> T ;
    while(T)
    {
        cin >>  N ;

        for(int i = 1 ; i <= N ; ++ i)
            cin >> A[i] ;
        for(int j = 1 ; j <= N ; ++ j)
            cin >> B[j] ;

        Solve() ;
        Out() ;
        -- T ;
    }
}


inline void Solve()
{
   sort(A + 1, A + N + 1) ;
   sort(B + 1, B + N + 1) ;
    sum = 0 ;
    //cout << sum << ' ' ;
    for(int i = 1 ; i <= N ; ++ i)
        //for(int j = N ; j >= 1 ; -- j)
    {
        //cout << A[i] << ' ' << B[N - i + 1] << '\n';
        sum = sum +  A[i] * B[N - i + 1];
        //cout << V[i] <<' '<<V2[i]<<' ' <<V[i] * V2[i]<< '\n' ;
        //cout << sum << '\n';
    }

}

inline void Out()
{

}

int main()
{
    Read() ; ++ d ;
    cout << "Case #" << d << ": " << sum << '\n';
    cin.close() ;
    cout.close() ;
    return 0 ;
}
