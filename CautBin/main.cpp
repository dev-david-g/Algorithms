#include <fstream>

using namespace std ;

ifstream cin("cautbin.in") ;
ofstream cout("cautbin.out") ;

int V[100], N, X;

int caut(int s, int d)
{
    int m ;
    if(s > d)
        return -1 ;
    else
    {
        m = (s + d) /2 ;
        if(X == V[m])
            return m ;
        else if(X < V[m])
            return caut(s, m - 1) ;
        else return caut(m + 1, d) ;
    }
}

int main()
{
    cin >> N >> X ;

    for(int i = 1 ; i <= N ; ++ i)
        cin >> V[i] ;


    cout << caut(1, N) ;

    cin.close();
    cout.close();
    return 0 ;
}
