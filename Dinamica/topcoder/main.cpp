#include <fstream>

using namespace std ;

const int NMAX = 1004;


ifstream cin("sum.in") ;
ofstream cout("sum.out") ;


int N, V[NMAX], Min[NMAX] ;
int Sum ;

int main()
{
    cin >> N ;
    for(int i = 1 ; i<= N ; ++ i)
        cin >> V[i], Sum = Sum + V[i];

    Min[0] = 0 ;

    for(int i = 1 ; i <= Sum ; ++ i)
        for(int j = 0 ; j < N  ; ++ j)
            if(V[j] <= i && Min[i - V[j]] + 1 < Min[i])
                Min[i] = Min[i - V[j]] + 1 ;


    cout << Min[Sum] << '\n' ;


    cin.close() ;
    cout.close() ;
    return 0 ;
}
