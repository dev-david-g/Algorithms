#include <fstream>
#include <algorithm>

using namespace std ;

const int NMAX = 5005  ;
ifstream cin("bancomat.in") ;
ofstream cout("bancomat.out") ;


inline int min(int a, int b) { if(a > b) return b ; else return a ;}

int T, N, V[NMAX], x, verif;
int b[] = {0, 1, 5, 10, 50, 100, 500}, a[10];
bool ok = true ;
int main()
{
    cin >> T ;
    while(T)
    {
        for(int i = 1; i <= 6 ; ++ i)
            cin >> V[i] ;


        cin >> N  ;
        ok = true ;
        for(int i = 1; i <= N ; ++ i)
        {
            cin >> x ;

            for(int j = 6 ; j >0  && x ; -- j)
            {
                if(V[j] && x >= b[j])
                {
                    verif = x / b[j];
                    verif = min(verif, V[j]);
                    V[j] -= verif;
                    x -= b[j] * verif;
                }
            }
            if( x != 0)
                ok = false ;
        }




        if(ok == true)
            cout << "YES" << '\n' ;
        else cout << "NO" << '\n' ;
        -- T ;
    }

    cin.close() ;
    cout.close() ;
    return 0 ;
}
