#include <fstream>

using namespace std;

ifstream cin("bsearch.in") ;
ofstream cout("bsearch.out") ;

const int NMAX = 1000 ;
int V[NMAX], N,  X;


void bsearch(int p, int u, int key)
{
    int m ;
    while(p <= u)
    {
        m = (p + u) / 2 ;
        if( V[m] <= key)
        p = m + 1 ;
        else u = m - 1 ;

    }
    m = (p + u) / 2 ;
    if(V[m] > key) --m ;
    if(V[m] == key)
        cout << "Este in sir!" ;
    else cout << "Nu este in sir!" ;
}

int main()
{
    cin >> N ; cin >> X;
    for(int i = 1 ; i <= N ; ++i)
    {
        cin >> V[i] ;

    }
   bsearch(1, N, X) ;
        cin.close();
    cout.close();
    return 0;
}
