///Determinarea de al n-lea termen al sirului Fibonacci.

#include <iostream>

using namespace std;

int N ;

inline int Fibo(int N)
{
    int V[N + 1] ;
    if(N == 1) return 1 ;
    V[2] = 1 ;
    V[3] = 2 ;
    for(int i = 4 ; i <= N; ++ i)
    {
        V[i] = V[i - 1] + V[i - 2];
    }
    return V[N] ;
}

int main()
{
    cin >> N ;
    cout << Fibo(N) ;
    return 0;
}
