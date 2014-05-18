#include <fstream>
#include <deque>
#include <cstring>
#include <string>
using namespace std;

const int NMAX = 500005 ;
const int INF = 0x3f3f3f3f ;

ifstream cin("secventa.in") ;
ofstream cout("secventa.out") ;

deque <int> Q ;
string s ;
int V[NMAX] ;
int N, K, v;
int Min =-INF ;
int sol1, sol2 ;

void Initializare() ;
void Rezolvare() ;
void Afisare() ;

inline void Initializare()
{
    cin >> N >> K ;
    cin.get();
    getline(cin, s) ;

}

inline void Rezolvare()
{
    int ok ;
    v = 0 ;
    int var ;
    for(int i = 1 ; i <= N ; ++ i)
    {
        var = 0 ;
        ok = 1 ;
        if(s[v] == '-') ok = -1, ++ v ;
        while(s[v] >= '0' && s[v] <= '9')
        {
            var = var * 10 + s[v] - '0' ;
            ++ v ;
        }
        var = var * ok ;
        ++ v ;
        V[i] = var ;
        while(! Q.empty() && V[i] < V[Q.back()])
            Q.pop_back() ;
        Q.push_back(i) ;
        if(i - K == Q.front()) Q.pop_front() ;
        if( i >= K)
        {
            var = V[Q.front()] ;
            if(var > Min)
            {
                Min = var ;
                sol1 = i - K + 1 ;
                sol2 = i ;
            }

        }

    }

}

inline void Afisare()
{

    cout << sol1 << ' ' << sol2 << ' ' << Min << '\n' ;
}

int main()
{
    Initializare() ;
    Rezolvare();
    Afisare() ;
    cin.close() ;
    cout.close() ;
    return 0 ;
}
