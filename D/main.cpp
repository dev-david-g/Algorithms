#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std ;

const int NMAX = 1005 ;

ifstream cin("war.in") ;
ofstream cout("war.out") ;

vector <double> W, R ;

inline int max (int a, int b)
{
    if(a > b) return a ;
    else return b ;
}
inline int min (int a, int b)
{
    if(a > b) return b ;
    else return a ;
}

int T, N;
double A[NMAX], B[NMAX];
int d = 0 ;
int X, Y ;

int main()
{

    cin >> T ;
    while(T)
    {
        X = 0, Y = 0 ;
        ++ d ;
        cin >> N ;
        cin >> fixed >> setprecision(5) ;
        for(int i = 1 ; i <= N ; ++ i)
            cin >> A[i], W.push_back(A[i]);
        for(int j = 1 ; j <= N ; ++ j)
            cin >> B[j], R.push_back(B[j]);


        sort(W.begin(), W.end()) ;
        sort(R.begin(), R.end()) ;

        for(int i = 0, j = 0; i <= N ; ++ i)
            if(W[i] > R[j])
            {
                ++ X ;
                ++ j ;
            }

        for(int i = 0, j = 0 ; i <= N ; ++ i)
            if(R[i] > W[j])
            {
                ++ Y ;
                ++ j ;
            }

        Y = N - Y ;
        cout << "Case #" << d << ": " << X <<' '<< Y << '\n';



        -- T ;
    }

    cin.close() ;
    cout.close() ;
    return 0 ;
}
