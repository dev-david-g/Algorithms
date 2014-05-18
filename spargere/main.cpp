#include <fstream>

using namespace std ;

const int NMAX = 100000005 ;
const int INF = 0x3f3f3f3f ;

ifstream cin ("spargere2.in") ;
ofstream cout("spargere2.out") ;
int  N, K ;
long long   V[NMAX], D[NMAX];
int  sum = 0, Max = - INF;

//inline int maxa(int a, int b, int c) { Max = a ; if(Max < b) Max = b ;  if(Max < c) Max = c ; return Max ;}

int main()
{
    cin >> N >> K ;
    for(int  i =  1; i <= N  ; ++ i)
    {
        cin >> V[i] ;
        //if(V[i] > 0)
        D[i] = D[i] + V[i] ;
    }

       for(int i =  K ; i <= N +  K; ++ i)
       {
          D[i] =  max( D[i - K] + V[i], D[i - 1]);}
          //D[i] = max(D[i], D[i - 1]) ;
          //if(D[i] > Max)
           // Max = D[i] ;



if(D[N] <= 0)
    cout << 0 << '\n' ;
else cout << D[N] << '\n' ;

        cin.close() ;
        cout.close() ;
        return 0 ;

    }
