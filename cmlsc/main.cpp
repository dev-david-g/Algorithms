#include <fstream>
#include <vector>

using namespace std ;

const int NMAX = 1030 ;

ifstream cin("cmlsc.in") ;
ofstream cout("cmlsc.out") ;

inline int max(int a, int b) {if(a > b) return a ; else return b ;}

int V[NMAX],  N;
int A[NMAX], M;
int Sol[NMAX][NMAX] ;
vector <int>  rec ;


inline void Citire()
{
   cin >> N >> M ;

    for(int i = 1 ; i <= N ; ++ i)
        cin >> V[i] ;

    for(int i = 1 ; i <= M ; ++ i)
            cin >> A[i] ;
}

inline void Rezolva()
{
    for(int i = 1 ; i <= N ; ++ i)
        for(int j = 1 ; j <= M ; ++ j)
             if(V[i] == A[j])
             Sol[i][j] =  Sol[i - 1][j - 1] + 1 ;
             else Sol[i][j] = max(Sol[i - 1][j], Sol[i][j - 1]) ;
}

inline void Indicele()
{
    for(int i = N, j = M ; i != 0 && j != 0;)
    {
        if(V[i] == A[j])
        {
            rec.push_back(V[i]) ;
            -- i ;
            -- j ;

        }
        else  {
            i =  Sol[i - 1][j] >= Sol[i][j - 1] ? i - 1 : i ;
            j =  Sol[i - 1][j] >= Sol[i][j - 1] ? j : j - 1;
        }

    }
}

inline void Afisare()
{
  /*  for(int i = 1 ; i <= N ; ++ i)
        { for(int j = 1 ; j <= M ; ++ j)
        cout << Sol[i][j] << ' ' ;
        cout << '\n' ;
        }
        */

       // cout << Sol[N][M] << '\n' ;
        cout << rec.size() << '\n' ;
        for(int i = rec.size() - 1 ; i >= 0 ; -- i)
            cout << rec[i] << ' ' ;


}

int main()
{
    Citire() ;
    Rezolva() ;
    Indicele() ;
    Afisare() ;
    cin.close() ;
    cout.close() ;
    return 0 ;
}
