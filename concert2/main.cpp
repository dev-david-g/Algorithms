#include <fstream>

using namespace std ;

const int NMAX = 2505 ;

ifstream cin("concert2.in") ;
ofstream cout("concert2.out") ;

int K1, K2, N, V[NMAX], cnt , best, Min[NMAX], l[NMAX], L, PozMax, MAX, d[NMAX], p[NMAX];
int Min2[NMAX], l2[NMAX], L2, PozMax2, MAX2, d2[NMAX], p2[NMAX];

void SCMAX()
{

    for(int i=1;i<=N;i++)
    {
        Min[i]=MAX;
        l[i]=L;
        while (Min[l[i]]>=V[i] && l[i]>0) l[i]--;
        d[i]=p[l[i]];
        l[i]++;
        if(l[i]>L)
        {
            L=l[i]; PozMax=i;
        }
        if(V[i]<Min[l[i]])
        {
            Min[l[i]]=V[i]; p[l[i]]=i;
        }
    }
 }

void SCMIN()
{

    for(int i=1;i<=N;i++)
    {
        Min2[i]=MAX2;
        l2[i]=L2;
        while (Min2[l2[i]]>=V[i] && l2[i]>0) l2[i]--;
        d2[i]=p2[l2[i]];
        l2[i]++;
        if(l2[i]>L2)
        {
            L2=l2[i]; PozMax2=i;
        }
        if(V[i]>Min2[l2[i]])
        {
            Min[l2[i]]=V[i]; p2[l2[i]]=i;
        }
    }
 }
int main()
{

    cin >> N >> K1 >> K2 ;

    for(int i = 1; i <= N ; ++ i)
        cin >> V[i] ;
        SCMAX() ;
        SCMIN() ;

   int sol ;
   sol = (L / K1) + (L2/ K2) ;
cout  << K1 * K2 ;

    cin.close() ;
    cout.close() ;
    return 0 ;
}
